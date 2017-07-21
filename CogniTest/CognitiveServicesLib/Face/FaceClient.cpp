#include "pch.h"
#include "HpptClientImpl.h"
#include "FaceClient.h"

using namespace Concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;

FaceClient::FaceClient(AzureRegions _Region, String^ _SubscriptionKey) : 
	m_Region( _Region ),
	m_SubscriptionKey( _SubscriptionKey),
	m_WebClient ( HpptClientImpl(_Region, _SubscriptionKey) )
{

}

IAsyncOperation<String^>^ FaceClient::DetectAsync(Platform::String^ _FileName)
{
	auto postaction = create_async([this]() {
		Uri^ uri = EndpointHelper::BuildEndpointUri(EndpointHelper::FaceDetect, m_Region, Parameters::FaceAttributes);
		return m_WebClient.PostFileAsync(uri, L"test");
	});
	return postaction;
}