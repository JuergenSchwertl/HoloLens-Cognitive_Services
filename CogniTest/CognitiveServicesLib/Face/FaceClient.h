#pragma once
#ifndef FACECLIENT_DEFINED
#define FACECLIENT_DEFINED

namespace CognitiveServicesLib
{
	public ref class FaceClient sealed
	{
	private:
		CognitiveServicesLib::AzureRegions m_Region;
		Platform::String^ m_SubscriptionKey;
		HpptClientImpl m_WebClient;
		static Platform::String^ FaceClient::jsonResult;

	public:
		FaceClient(CognitiveServicesLib::AzureRegions Region, Platform::String^ SubscriptionKey);
		

		[Windows::Foundation::Metadata::DefaultOverload]
		Windows::Foundation::IAsyncOperation<Platform::String^>^ DetectAsync(
			Platform::String^ FileName,
			bool ReturnFaceId, 
			bool ReturnFaceLandmarks, 
			Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes);

		Windows::Foundation::IAsyncOperation<Platform::String^>^ DetectAsync(
			Windows::Foundation::Uri^ FileUri,
			bool ReturnFaceId,
			bool ReturnFaceLandmarks,
			Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes);

		Windows::Foundation::IAsyncOperation<Platform::String^>^ DetectAsync(
			Windows::Storage::Streams::IBuffer^ ImageData,
			bool ReturnFaceId,
			bool ReturnFaceLandmarks,
			Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes);

		Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<CognitiveServicesLib::Face^>^>^ FakeDetectAsync(Platform::String^ FileName);
	};
}

#endif


