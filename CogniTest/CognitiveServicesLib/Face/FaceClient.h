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

		Windows::Foundation::IAsyncOperation<Platform::String^>^ DetectAsync(Platform::String^ FileName);
		Windows::Foundation::IAsyncOperation<Platform::String^>^ DetectAsync(Windows::Foundation::Uri^ FileUri);

		Windows::Foundation::IAsyncOperation<Platform::String^>^ FakeDetectAsync(Platform::String^ FileName);
	};
}

#endif


