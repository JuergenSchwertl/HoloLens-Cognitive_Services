//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"

#include "MainPage.xaml.h"

using namespace CogniTest;

using namespace Concurrency;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Imaging;
using namespace Windows::Graphics::Display;
using namespace Windows::Media;
using namespace Windows::Media::Core;
using namespace Windows::Media::FaceAnalysis;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Devices::Sensors;
using namespace Windows::Devices::Enumeration;
using namespace Windows::Storage;

using namespace CognitiveServicesLib;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
	: _mediaCapture(nullptr)
	, _previewProperties(nullptr)
	, _isInitialized(false)
	, _isRecording(false)
	, _externalCamera(false)
	, _mirroringPreview(false)
	, _deviceOrientation(SimpleOrientation::NotRotated)
	, _displayOrientation(DisplayOrientations::Portrait)
	, _displayRequest(ref new Windows::System::Display::DisplayRequest())
	, RotationKey({ 0xC380465D, 0x2271, 0x428C,{ 0x9B, 0x83, 0xEC, 0xEA, 0x3B, 0x4A, 0x85, 0xC1 } })
{
	InitializeComponent();

	_orientationSensor = SimpleOrientationSensor::GetDefault();
	_displayInformation = DisplayInformation::GetForCurrentView();
	_systemMediaControls = SystemMediaTransportControls::GetForCurrentView();

	m_FaceClient = ref new FaceClient(AzureRegions::WestEurope, L"c36cbe9c22c3409a9e5ee9f56bb5c543");
	m_FaceAttributeList = ref new Vector<FaceAttributeOptions>(
	{
		FaceAttributeOptions::Age,
		FaceAttributeOptions::Gender,
		FaceAttributeOptions::HeadPose,
		FaceAttributeOptions::Smile,
		FaceAttributeOptions::FacialHair,
		FaceAttributeOptions::Glasses,
		FaceAttributeOptions::Emotion,
		FaceAttributeOptions::Hair,
		FaceAttributeOptions::Makeup,
		FaceAttributeOptions::Occlusion,
		FaceAttributeOptions::Accessories,
		FaceAttributeOptions::Blur,
		FaceAttributeOptions::Exposure,
		FaceAttributeOptions::Noise
	}
	);
}


void CogniTest::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Uri^ uriTestImage = ref new Uri(L"ms-appx:///Assets/Juergen_Schwertl.jpg");


	Concurrency::create_task(m_FaceClient->DetectAsync(uriTestImage, true, true, m_FaceAttributeList))
	.then([=](Platform::String^ result) {
		LblResult->Text = result;
	}, task_continuation_context::use_current())
	.then([=](task<void> t) {
		try {
			t.get();
		}
		catch (Exception^ ex)
		{
			LblResult->Text = ex->Message;
		}
	}, task_continuation_context::use_current());
}


void CogniTest::MainPage::BtnCamera_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	InitializeCameraAsync();
}


/// <summary>
/// Initializes the MediaCapture, registers events, gets camera device information for mirroring and rotating, starts preview and unlocks the UI
/// </summary>
/// <returns></returns>
task<void> MainPage::InitializeCameraAsync()
{
	// Get available devices for capturing pictures
	return FindCameraDeviceByPanelAsync(Windows::Devices::Enumeration::Panel::Front)
		.then([this](DeviceInformation^ camera)
	{
		if (camera == nullptr)
		{
			//WriteLine("No camera device found!");
			return;
		}
		// Figure out where the camera is located
		if (camera->EnclosureLocation == nullptr || camera->EnclosureLocation->Panel == Windows::Devices::Enumeration::Panel::Unknown)
		{
			// No information on the location of the camera, assume it's an external camera, not integrated on the device
			_externalCamera = true;
		}
		else
		{
			// Camera is fixed on the device
			_externalCamera = false;

			// Only mirror the preview if the camera is on the front panel
			_mirroringPreview = (camera->EnclosureLocation->Panel == Windows::Devices::Enumeration::Panel::Front);
		}

		_mediaCapture = ref new Capture::MediaCapture();

		_mediaCaptureFailedEventToken =
			_mediaCapture->Failed += ref new Capture::MediaCaptureFailedEventHandler(this, &MainPage::MediaCapture_Failed);

		auto settings = ref new Capture::MediaCaptureInitializationSettings();
		settings->VideoDeviceId = camera->Id;
		settings->StreamingCaptureMode = Capture::StreamingCaptureMode::AudioAndVideo;

		// Initialize media capture and start the preview
		create_task(_mediaCapture->InitializeAsync(settings))
			.then([this]()
		{
			_isInitialized = true;

			return StartPreviewAsync()
				.then([this]()
			{
				PhotoButton->IsEnabled = true;
			});
		}).then([this](task<void> previousTask)
		{
			try
			{
				previousTask.get();
			}
			catch (AccessDeniedException^ ex)
			{
				//WriteLine("The app was denied access to the camera");
			}
		});
	});
}

/// <summary>
/// Cleans up the camera resources (after stopping any video recording and/or preview if necessary) and unregisters from MediaCapture events
/// </summary>
/// <returns></returns>
Concurrency::task<void> MainPage::CleanupCameraAsync()
{

	if (_mediaCapture != nullptr)
	{
		_mediaCapture = nullptr;
	}
	return create_task([]() {});
}

/// <summary>
/// Starts the preview and adjusts it for for rotation and mirroring after making a request to keep the screen on
/// </summary>
/// <returns></returns>
task<void> MainPage::StartPreviewAsync()
{
	// Prevent the device from sleeping while the preview is running
	_displayRequest->RequestActive();

	// Set the preview source in the UI and mirror it if necessary
	PreviewControl->Source = _mediaCapture.Get();
	PreviewControl->FlowDirection = _mirroringPreview ? Windows::UI::Xaml::FlowDirection::RightToLeft : Windows::UI::Xaml::FlowDirection::LeftToRight;

	// Start the preview
	return create_task(_mediaCapture->StartPreviewAsync())
		.then([this](task<void> previousTask)
	{
		_previewProperties = _mediaCapture->VideoDeviceController->GetMediaStreamProperties(Capture::MediaStreamType::VideoPreview);

		// Only need to update the orientation if the camera is mounted on the device
		if (!_externalCamera)
		{
			_displayOrientation = _displayInformation->CurrentOrientation;
			return SetPreviewRotationAsync();
		}

		// Not external, just return the previous task
		return previousTask;
	});
}

/// <summary>
/// Gets the current orientation of the UI in relation to the device (when AutoRotationPreferences cannot be honored) and applies a corrective rotation to the preview
/// </summary>
/// <returns></returns>
task<void> MainPage::SetPreviewRotationAsync()
{
	// Calculate which way and how far to rotate the preview
	int rotationDegrees = ConvertDisplayOrientationToDegrees(_displayOrientation);

	// The rotation direction needs to be inverted if the preview is being mirrored
	if (_mirroringPreview)
	{
		rotationDegrees = (360 - rotationDegrees) % 360;
	}

	// Add rotation metadata to the preview stream to make sure the aspect ratio / dimensions match when rendering and getting preview frames
	auto props = _mediaCapture->VideoDeviceController->GetMediaStreamProperties(Capture::MediaStreamType::VideoPreview);
	props->Properties->Insert(RotationKey, rotationDegrees);
	return create_task(_mediaCapture->SetEncodingPropertiesAsync(Capture::MediaStreamType::VideoPreview, props, nullptr));
}

/// <summary>
/// Stops the preview and deactivates a display request, to allow the screen to go into power saving modes
/// </summary>
/// <returns></returns>
task<void> MainPage::StopPreviewAsync()
{
	_previewProperties = nullptr;

	return create_task(_mediaCapture->StopPreviewAsync())
		.then([this]()
	{
		// Use the dispatcher because this method is sometimes called from non-UI threads
		return Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([this]()
		{
			// Cleanup the UI
			PreviewControl->Source = nullptr;
			// Allow the device screen to sleep now that the preview is stopped
			_displayRequest->RequestRelease();
		}));
	});
}

/// <summary>
/// Takes a photo to a StorageFile and adds rotation metadata to it
/// </summary>
/// <returns></returns>
task<void> MainPage::TakePhotoAsync()
{
	auto inputStream = ref new Streams::InMemoryRandomAccessStream();

	// Take the picture
	//WriteLine("Taking photo...");
	return create_task(_mediaCapture->CapturePhotoToStreamAsync(Windows::Media::MediaProperties::ImageEncodingProperties::CreatePng(), inputStream))
	.then([this, inputStream]()
	{
		unsigned int nImageSize = (unsigned int)inputStream->Size;
		// make sure to rewind stream!
		inputStream->Seek(0);

		Windows::Storage::Streams::Buffer^ buf = ref new Windows::Storage::Streams::Buffer(nImageSize);
		
		return create_task(inputStream->ReadAsync(buf, nImageSize, Windows::Storage::Streams::InputStreamOptions::None));
	})
	.then([this](Windows::Storage::Streams::IBuffer^ buf) 
	{
		return create_task(m_FaceClient->DetectAsync(buf, false, false, m_FaceAttributeList ));
	})
	.then([this](Platform::String^ result) 
	{
		LblResult->Text = result;	
		//Windows::Data::Json::JsonArray^ json = Windows::Data::Json::JsonArray::Parse(result);
		//
		//auto face = CognitiveServicesLib::Face::FromJson(json->First()->Current);
		
		//WriteLine("Photo taken! Saving to " + file->Path);

		// Done taking a photo, so re-enable the button

		//auto photoOrientation = ConvertOrientationToPhotoOrientation(GetCameraOrientation());
		//return ReencodeAndSavePhotoAsync(inputStream, file, photoOrientation);
			return create_task([]() {});
	}).then([this](task<void> previousTask)
	{
		try
		{
			previousTask.get();
		}
		catch (Exception^ ex)
		{
			// File I/O errors are reported as exceptions
			//WriteException(ex);
		}
	});
}

/// <summary>
/// Attempts to find and return a device mounted on the panel specified, and on failure to find one it will return the first device listed
/// </summary>
/// <param name="panel">The desired panel on which the returned device should be mounted, if available</param>
/// <returns></returns>
task<DeviceInformation^> MainPage::FindCameraDeviceByPanelAsync(Windows::Devices::Enumeration::Panel panel)
{
	// Get available devices for capturing pictures
	auto allVideoDevices = DeviceInformation::FindAllAsync(DeviceClass::VideoCapture);

	auto deviceEnumTask = create_task(allVideoDevices);
	return deviceEnumTask.then([panel](DeviceInformationCollection^ devices)
	{
		for (auto cameraDeviceInfo : devices)
		{
			if (cameraDeviceInfo->EnclosureLocation != nullptr && cameraDeviceInfo->EnclosureLocation->Panel == panel)
			{
				return cameraDeviceInfo;
			}
		}

		// Nothing matched, just return the first
		if (devices->Size > 0)
		{
			return devices->GetAt(0);
		}

		// We didn't find any devices, so return a null instance
		DeviceInformation^ camera = nullptr;
		return camera;
	});
}

/// <summary>
/// Applies the given orientation to a photo stream and saves it as a StorageFile
/// </summary>
/// <param name="stream">The photo stream</param>
/// <param name="file">The StorageFile in which the photo stream will be saved</param>
/// <param name="photoOrientation">The orientation metadata to apply to the photo</param>
/// <returns></returns>
task<void> MainPage::ReencodeAndSavePhotoAsync(Streams::IRandomAccessStream^ stream, StorageFile^ file, FileProperties::PhotoOrientation photoOrientation)
{
	// Using this state variable to pass multiple values through our task chain
	ReencodeState^ state = ref new ReencodeState();
	state->File = file;
	state->Orientation = photoOrientation;

	return create_task(BitmapDecoder::CreateAsync(stream))
		.then([state](BitmapDecoder^ decoder)
	{
		state->Decoder = decoder;
		return create_task(state->File->OpenAsync(FileAccessMode::ReadWrite));
	}).then([state](Streams::IRandomAccessStream^ outputStream)
	{
		return create_task(BitmapEncoder::CreateForTranscodingAsync(outputStream, state->Decoder));
	}).then([state](BitmapEncoder^ encoder)
	{
		state->Encoder = encoder;
		auto properties = ref new Windows::Graphics::Imaging::BitmapPropertySet();
		properties->Insert("System.Photo.Orientation", ref new BitmapTypedValue((unsigned short)state->Orientation, Windows::Foundation::PropertyType::UInt16));

		return create_task(state->Encoder->BitmapProperties->SetPropertiesAsync(properties));
	}).then([state]()
	{
		return state->Encoder->FlushAsync();
	});
}


/// <summary>
/// Calculates the current camera orientation from the device orientation by taking into account whether the camera is external or facing the user
/// </summary>
/// <returns>The camera orientation in space, with an inverted rotation in the case the camera is mounted on the device and is facing the user</returns>
SimpleOrientation MainPage::GetCameraOrientation()
{
	if (_externalCamera)
	{
		// Cameras that are not attached to the device do not rotate along with it, so apply no rotation
		return SimpleOrientation::NotRotated;
	}

	auto result = _deviceOrientation;

	// Account for the fact that, on portrait-first devices, the camera sensor is mounted at a 90 degree offset to the native orientation
	if (_displayInformation->NativeOrientation == DisplayOrientations::Portrait)
	{
		switch (result)
		{
		case SimpleOrientation::Rotated90DegreesCounterclockwise:
			result = SimpleOrientation::NotRotated;
			break;
		case SimpleOrientation::Rotated180DegreesCounterclockwise:
			result = SimpleOrientation::Rotated90DegreesCounterclockwise;
			break;
		case SimpleOrientation::Rotated270DegreesCounterclockwise:
			result = SimpleOrientation::Rotated180DegreesCounterclockwise;
			break;
		case SimpleOrientation::NotRotated:
		default:
			result = SimpleOrientation::Rotated270DegreesCounterclockwise;
			break;
		}
	}

	// If the preview is being mirrored for a front-facing camera, then the rotation should be inverted
	if (_mirroringPreview)
	{
		// This only affects the 90 and 270 degree cases, because rotating 0 and 180 degrees is the same clockwise and counter-clockwise
		switch (result)
		{
		case SimpleOrientation::Rotated90DegreesCounterclockwise:
			return SimpleOrientation::Rotated270DegreesCounterclockwise;
		case SimpleOrientation::Rotated270DegreesCounterclockwise:
			return SimpleOrientation::Rotated90DegreesCounterclockwise;
		}
	}

	return result;
}


/// <summary>
/// Converts the given orientation of the device in space to the metadata that can be added to captured photos
/// </summary>
/// <param name="orientation">The orientation of the device in space</param>
/// <returns></returns>
FileProperties::PhotoOrientation MainPage::ConvertOrientationToPhotoOrientation(SimpleOrientation orientation)
{
	switch (orientation)
	{
	case SimpleOrientation::Rotated90DegreesCounterclockwise:
		return FileProperties::PhotoOrientation::Rotate90;
	case SimpleOrientation::Rotated180DegreesCounterclockwise:
		return FileProperties::PhotoOrientation::Rotate180;
	case SimpleOrientation::Rotated270DegreesCounterclockwise:
		return FileProperties::PhotoOrientation::Rotate270;
	case SimpleOrientation::NotRotated:
	default:
		return FileProperties::PhotoOrientation::Normal;
	}
}

/// <summary>
/// Converts the given orientation of the device in space to the corresponding rotation in degrees
/// </summary>
/// <param name="orientation">The orientation of the device in space</param>
/// <returns>An orientation in degrees</returns>
int MainPage::ConvertDeviceOrientationToDegrees(SimpleOrientation orientation)
{
	switch (orientation)
	{
	case SimpleOrientation::Rotated90DegreesCounterclockwise:
		return 90;
	case SimpleOrientation::Rotated180DegreesCounterclockwise:
		return 180;
	case SimpleOrientation::Rotated270DegreesCounterclockwise:
		return 270;
	case SimpleOrientation::NotRotated:
	default:
		return 0;
	}
}

/// <summary>
/// Converts the given orientation of the app on the screen to the corresponding rotation in degrees
/// </summary>
/// <param name="orientation">The orientation of the app on the screen</param>
/// <returns>An orientation in degrees</returns>
int MainPage::ConvertDisplayOrientationToDegrees(DisplayOrientations orientation)
{
	switch (orientation)
	{
	case DisplayOrientations::Portrait:
		return 90;
	case DisplayOrientations::LandscapeFlipped:
		return 180;
	case DisplayOrientations::PortraitFlipped:
		return 270;
	case DisplayOrientations::Landscape:
	default:
		return 0;
	}
}

void MainPage::PhotoButton_Click(Object^, Windows::UI::Xaml::RoutedEventArgs^)
{
	TakePhotoAsync();
}


void MainPage::MediaCapture_Failed(Capture::MediaCapture ^currentCaptureObject, Capture::MediaCaptureFailedEventArgs^ errorEventArgs)
{

	CleanupCameraAsync();
}
