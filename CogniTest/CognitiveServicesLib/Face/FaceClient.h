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

	public:
		FaceClient(CognitiveServicesLib::AzureRegions Region, Platform::String^ SubscriptionKey);

		Windows::Foundation::IAsyncOperation<Platform::String^>^ DetectAsync(Platform::String^ FileName);
	};
}

#endif


