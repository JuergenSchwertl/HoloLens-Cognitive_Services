//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace CogniTest
{

	ref class ReencodeState sealed
	{
	internal:
		Windows::Graphics::Imaging::BitmapDecoder^ Decoder;
		Windows::Graphics::Imaging::BitmapEncoder^ Encoder;
		Windows::Storage::StorageFile^ File;
		Windows::Storage::FileProperties::PhotoOrientation Orientation;
	};



	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	private:
		CognitiveServicesLib::FaceClient^ m_FaceClient;
		Platform::Collections::Vector<CognitiveServicesLib::FaceAttributeOptions>^ m_FaceAttributeList;

	public:
		MainPage();

	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void BtnCamera_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void PhotoButton_Click(Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);



	private:
		// Receive notifications about rotation of the device and UI and apply any necessary rotation to the preview stream and UI controls  
		Windows::Devices::Sensors::SimpleOrientationSensor^ _orientationSensor;
		Windows::Graphics::Display::DisplayInformation^ _displayInformation;
		Windows::Devices::Sensors::SimpleOrientation _deviceOrientation;
		Windows::Graphics::Display::DisplayOrientations _displayOrientation;

		// Prevent the screen from sleeping while the camera is running
		Windows::System::Display::DisplayRequest^ _displayRequest;

		// For listening to media property changes
		Windows::Media::SystemMediaTransportControls^ _systemMediaControls;

		// MediaCapture and its state variables
		Platform::Agile<Windows::Media::Capture::MediaCapture^> _mediaCapture;
		Windows::Media::MediaProperties::IMediaEncodingProperties^ _previewProperties;
		bool _isInitialized;
		bool _isRecording;

		// Information about the camera device
		bool _externalCamera;
		bool _mirroringPreview;

		Windows::Media::Core::FaceDetectionEffect^ _faceDetectionEffect;

		// Rotation metadata to apply to the preview stream and recorded videos (MF_MT_VIDEO_ROTATION)
		// Reference: http://msdn.microsoft.com/en-us/library/windows/apps/xaml/hh868174.aspx
		const GUID RotationKey;

		// Folder in which the captures will be stored (availability check performed in SetupUiAsync)
		Windows::Storage::StorageFolder^ _captureFolder;

		// Event tokens
		Windows::Foundation::EventRegistrationToken _applicationSuspendingEventToken;
		Windows::Foundation::EventRegistrationToken _applicationResumingEventToken;
		Windows::Foundation::EventRegistrationToken _mediaControlPropChangedEventToken;
		Windows::Foundation::EventRegistrationToken _displayInformationEventToken;
		Windows::Foundation::EventRegistrationToken _recordLimitationExceededEventToken;
		Windows::Foundation::EventRegistrationToken _mediaCaptureFailedEventToken;
		Windows::Foundation::EventRegistrationToken _orientationChangedEventToken;
		Windows::Foundation::EventRegistrationToken _hardwareCameraButtonEventToken;
		Windows::Foundation::EventRegistrationToken _faceDetectedEventToken;

		// MediaCapture methods
		Concurrency::task<void> InitializeCameraAsync();
		Concurrency::task<void> CleanupCameraAsync();
		Concurrency::task<void> StartPreviewAsync();
		Concurrency::task<void> SetPreviewRotationAsync();
		Concurrency::task<void> StopPreviewAsync();
		Concurrency::task<void> TakePhotoAsync();
		void MediaCapture_Failed(Windows::Media::Capture::MediaCapture ^currentCaptureObject, Windows::Media::Capture::MediaCaptureFailedEventArgs^ errorEventArgs);

		// Rotation helpers
		Windows::Devices::Sensors::SimpleOrientation GetCameraOrientation();
		Windows::Storage::FileProperties::PhotoOrientation ConvertOrientationToPhotoOrientation(Windows::Devices::Sensors::SimpleOrientation orientation);
		int ConvertDeviceOrientationToDegrees(Windows::Devices::Sensors::SimpleOrientation orientation);
		int ConvertDisplayOrientationToDegrees(Windows::Graphics::Display::DisplayOrientations orientation);
		//void UpdateButtonOrientation();
		//void SetFacesCanvasRotation();

		// Helpers
		Concurrency::task<Windows::Devices::Enumeration::DeviceInformation^> FindCameraDeviceByPanelAsync(Windows::Devices::Enumeration::Panel panel);
		Concurrency::task<void> ReencodeAndSavePhotoAsync(Windows::Storage::Streams::IRandomAccessStream^ stream, Windows::Storage::StorageFile^ file, Windows::Storage::FileProperties::PhotoOrientation photoOrientation);
	};
}
