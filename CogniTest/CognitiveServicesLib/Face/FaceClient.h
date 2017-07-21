#pragma once
#ifndef FACECLIENT_DEFINED
#define FACECLIENT_DEFINED

namespace CognitiveServicesLib
{
	ref class FaceClient sealed
	{
	private:
		CognitiveServicesLib::AzureRegions m_Region;
		Platform::String^ m_SubscriptionKey;
		HpptClientImpl& m_WebClient;

	public:
		FaceClient(CognitiveServicesLib::AzureRegions _Region, Platform::String^ );

		Windows::Foundation::IAsyncOperation<Platform::String^>^ DetectAsync(Platform::String^);
	};
}

#endif


