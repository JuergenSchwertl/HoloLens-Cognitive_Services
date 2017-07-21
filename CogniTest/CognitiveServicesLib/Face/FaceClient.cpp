#include "pch.h"
#include "HpptClientImpl.h"
#include "FaceClient.h"

using namespace Concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;

///<summary>Creates a new FaceClient for Cognitive Services face recognition</summary>
///<param name="Region">A member of the <see cref="AzureRegions" /> enumeration</param>
///<param name="SubscriptionKey">Your subscription key from the <see cref="https://portal.azure.com">Azure Portal</cref></param>
FaceClient::FaceClient(AzureRegions Region, String^ SubscriptionKey) :
	m_Region( Region ),
	m_SubscriptionKey( SubscriptionKey),
	m_WebClient ( HpptClientImpl(Region, SubscriptionKey) )
{

}

///<summary>Detects faces from an image file</summary>
///<param name="FileName">Image file name</param>
///<returns>async task completing with Face - Detect API response as json string</returns>
IAsyncOperation<String^>^ FaceClient::DetectAsync(Platform::String^ FileName)
{
	auto postaction = create_async([=]() {
		Uri^ uri = EndpointHelper::BuildEndpointUri(EndpointHelper::FaceDetect, m_Region, Parameters::FaceAttributes);
		return m_WebClient.PostFileAsync(uri, L"test");
	});
	return postaction;
}