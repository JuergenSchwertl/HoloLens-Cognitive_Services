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
		
		Windows::Foundation::Uri^ buildUri(
			PCWSTR _baseUri,
			bool _returnFaceId,
			bool _returnFaceLandmarks,
			Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ _returnFaceAttributes);

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

		///<summary>Detects faces from an image data buffer</summary>
		///<param name="ImageData">IBuffer with image data. Pass from C# as Array.AsBuffer()</param>
		///<param name="ReturnFaceId">requests Face Api to return face id</param>
		///<param name="ReturnFaceLandmarks">requests Face Api to return face landmarks</param>
		///<param name="ReturnFaceAttributes">requests Face Api to return listed face attributes. <seealso cref="CognitiveServices::FaceAttributeOptions" /></param>
		///<returns>async operation completing with Face - Detect API response as <seealso cref="CognitiveServicesLib::Face" /></returns>
		Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<CognitiveServicesLib::Face^>^>^
			FaceDetectAsync(
				Windows::Storage::Streams::IBuffer^ ImageData,
				bool ReturnFaceId,
				bool ReturnFaceLandmarks,
				Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes);


		Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<CognitiveServicesLib::Face^>^>^ FakeDetectAsync(Platform::String^ FileName);
	};
}

#endif


