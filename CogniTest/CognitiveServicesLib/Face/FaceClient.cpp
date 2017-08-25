#include "pch.h"
#include "FileHelper.h"
#include "HpptClientImpl.h"
#include "FaceClient.h"

using namespace Concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::Data::Json;

Windows::Foundation::Uri^ FaceClient::buildUri(
	PCWSTR _baseUri,
	bool _returnFaceId,
	bool _returnFaceLandmarks,
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ _returnFaceAttributes)
{
	String^ strParams = EndpointHelper::BuildParameterList(_returnFaceId, _returnFaceLandmarks, _returnFaceAttributes);
	Uri^ uri = EndpointHelper::BuildEndpointUri(EndpointHelper::FaceDetect, this->m_Region, strParams);
	return uri;
}

///<summary>Creates a new FaceClient for Cognitive Services face recognition</summary>
///<param name="Region">A member of the <see cref="AzureRegions" /> enumeration</param>
///<param name="SubscriptionKey">Your subscription key from the <see cref="https://portal.azure.com">Azure Portal</cref></param>
FaceClient::FaceClient(AzureRegions Region, String^ SubscriptionKey) :
	m_Region( Region ),
	m_SubscriptionKey( SubscriptionKey),
	m_WebClient ( HpptClientImpl(Region, SubscriptionKey) )
{

}

[Windows::Foundation::Metadata::DefaultOverload]
///<summary>Detects faces from an image file</summary>
///<param name="FileName">Image file name</param>
///<param name="ReturnFaceId">requests Face Api to return face id</param>
///<param name="ReturnFaceLandmarks">requests Face Api to return face landmarks</param>
///<param name="ReturnFaceAttributes">requests Face Api to return listed face attributes. <seealso cref="CognitiveServices::FaceAttributeOptions" /></param>
///<returns>async task completing with Face - Detect API response as json string</returns>
IAsyncOperation<String^>^ FaceClient::DetectAsync(
	Platform::String^ FileName, 
	bool ReturnFaceId, 
	bool ReturnFaceLandmarks, 
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes)
{
	auto postaction = create_async([=]() {
		String^ strParams = EndpointHelper::BuildParameterList(ReturnFaceId, ReturnFaceLandmarks, ReturnFaceAttributes);
		Uri^ uri = EndpointHelper::BuildEndpointUri(EndpointHelper::FaceDetect, m_Region, strParams);
		return m_WebClient.PostFileAsync(uri, L"test");
	});
	return postaction;
}

///<summary>Detects faces from an image Uri</summary>
///<param name="FileUri">Uri to an Image on the web or locally (ms-appx://)</param>
///<param name="ReturnFaceId">requests Face Api to return face id</param>
///<param name="ReturnFaceLandmarks">requests Face Api to return face landmarks</param>
///<param name="ReturnFaceAttributes">requests Face Api to return listed face attributes. <seealso cref="CognitiveServices::FaceAttributeOptions" /></param>
///<returns>async task completing with Face - Detect API response as json string</returns>
IAsyncOperation<Platform::String^>^ FaceClient::DetectAsync(
	Uri^ FileUri,
	bool ReturnFaceId,
	bool ReturnFaceLandmarks,
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes)
{
	auto postaction = create_async([=]() {
		String^ strParams = EndpointHelper::BuildParameterList(ReturnFaceId, ReturnFaceLandmarks, ReturnFaceAttributes);
		Uri^ uriEndpoint = EndpointHelper::BuildEndpointUri(EndpointHelper::FaceDetect, m_Region, strParams);

		return m_WebClient.PostUriAsync(uriEndpoint, FileUri);
	});
	return postaction;
}

///<summary>Detects faces from an image data buffer</summary>
///<param name="ImageData">IBuffer with image data. Pass from C# as Array.AsBuffer()</param>
///<param name="ReturnFaceId">requests Face Api to return face id</param>
///<param name="ReturnFaceLandmarks">requests Face Api to return face landmarks</param>
///<param name="ReturnFaceAttributes">requests Face Api to return listed face attributes. <seealso cref="CognitiveServices::FaceAttributeOptions" /></param>
///<returns>async task completing with Face - Detect API response as json string</returns>
IAsyncOperation<Platform::String^>^ FaceClient::DetectAsync(
	Windows::Storage::Streams::IBuffer^ ImageData,
	bool ReturnFaceId,
	bool ReturnFaceLandmarks,
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes)
{
	auto postaction = create_async([=]() {
		String^ strParams = EndpointHelper::BuildParameterList(ReturnFaceId, ReturnFaceLandmarks, ReturnFaceAttributes);
		Uri^ uriEndpoint = EndpointHelper::BuildEndpointUri(EndpointHelper::FaceDetect, m_Region, strParams);

		return m_WebClient.PostBufferAsync(uriEndpoint, ImageData);
	});
	
	return postaction;
}

[Windows::Foundation::Metadata::DefaultOverload]
///<summary>Detects faces from an image file</summary>
///<param name="FileName">relative path of a file</param>
///<param name="ReturnFaceId">requests Face Api to return face id</param>
///<param name="ReturnFaceLandmarks">requests Face Api to return face landmarks</param>
///<param name="ReturnFaceAttributes">requests Face Api to return listed face attributes. <seealso cref="CognitiveServices::FaceAttributeOptions" /></param>
///<returns>async task completing with Face - Detect API response as json string</returns>
Windows::Foundation::IAsyncOperation<
	Windows::Foundation::Collections::IVector<
	CognitiveServicesLib::Face^
	>^
>^ FaceClient::FaceDetectAsync(
	Platform::String^ FileName,
	bool ReturnFaceId,
	bool ReturnFaceLandmarks,
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes)
{
	auto postaction = create_async([=]() {
		Uri^ uriEndpoint = buildUri(EndpointHelper::FaceDetect, ReturnFaceId, ReturnFaceLandmarks, ReturnFaceAttributes);

		auto worker = m_WebClient.PostFileAsync(uriEndpoint, FileName)
			.then([](String^ result) {
			auto vec = Face::FromJsonString(result);
			return vec;
		});
		return worker;
	});

	return postaction;
}

///<summary>Detects faces from an image uri</summary>
///<param name="FileUri">Uri to an Image file on the web or in your msappx:/// installation directory </param>
///<param name="ReturnFaceId">requests Face Api to return face id</param>
///<param name="ReturnFaceLandmarks">requests Face Api to return face landmarks</param>
///<param name="ReturnFaceAttributes">requests Face Api to return listed face attributes. <seealso cref="CognitiveServices::FaceAttributeOptions" /></param>
///<returns>async task completing with Face - Detect API response as json string</returns>
Windows::Foundation::IAsyncOperation<
	Windows::Foundation::Collections::IVector<
	CognitiveServicesLib::Face^
	>^
>^ FaceClient::FaceDetectAsync(
	Windows::Foundation::Uri^ FileUri,
	bool ReturnFaceId,
	bool ReturnFaceLandmarks,
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes)
{
	auto postaction = create_async([=]() {
		Uri^ uriEndpoint = buildUri(EndpointHelper::FaceDetect, ReturnFaceId, ReturnFaceLandmarks, ReturnFaceAttributes);

		auto worker = m_WebClient.PostUriAsync(uriEndpoint, FileUri)
			.then([](String^ result) {
			auto vec = Face::FromJsonString(result);
			return vec;
		});
		return worker;
	});

	return postaction;
}

///<summary>Detects faces from an image data buffer</summary>
///<param name="ImageData">IBuffer with image data. Pass from C# as Array.AsBuffer()</param>
///<param name="ReturnFaceId">requests Face Api to return face id</param>
///<param name="ReturnFaceLandmarks">requests Face Api to return face landmarks</param>
///<param name="ReturnFaceAttributes">requests Face Api to return listed face attributes. <seealso cref="CognitiveServices::FaceAttributeOptions" /></param>
///<returns>async task completing with Face - Detect API response as json string</returns>
Windows::Foundation::IAsyncOperation<
	Windows::Foundation::Collections::IVector<
		CognitiveServicesLib::Face^
	>^
>^ FaceClient::FaceDetectAsync(
	Windows::Storage::Streams::IBuffer^ ImageData,
	bool ReturnFaceId,
	bool ReturnFaceLandmarks,
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes)
{
	auto postaction = create_async([=]() {
		Uri^ uriEndpoint = buildUri(EndpointHelper::FaceDetect, ReturnFaceId, ReturnFaceLandmarks, ReturnFaceAttributes);

		auto worker = m_WebClient.PostBufferAsync(uriEndpoint, ImageData)
		.then([](String^ result) {
			auto vec = Face::FromJsonString(result);
			return vec;
		});
		return worker;
	});

	return postaction;
}





///<summary>Detects faces from an image file</summary>
///<param name="FileName">Image file name</param>
///<returns>async task completing with Face - Detect API response as json string</returns>
IAsyncOperation<IVector<Face^>^>^ FaceClient::FakeDetectAsync(Platform::String^ FileName)
{
	auto postaction = create_async([=]() {
		return Face::FromJsonString(jsonResult);
	});
	return postaction;
}

String^ FaceClient::jsonResult = L""
"["
"    {"
"        \"faceId\": \"c5c24a82-6845-4031-9d5d-978df9175426\","
"        \"faceRectangle\": {"
"            \"width\": 78,"
"            \"height\": 78,"
"            \"left\": 394,"
"            \"top\": 54"
"        },"
"        \"faceLandmarks\": {"
"            \"pupilLeft\": {"
"                \"x\": 412.7,"
"                \"y\": 78.4 "
"            },"
"            \"pupilRight\": {"
"                \"x\": 446.8,"
"                \"y\": 74.2 "
"            },"
"            \"noseTip\": {"
"                \"x\": 437.7,"
"                \"y\": 92.4 "
"            },"
"            \"mouthLeft\": {"
"                \"x\": 417.8,"
"                \"y\": 114.4 "
"            },"
"            \"mouthRight\": {"
"                \"x\": 451.3,"
"                \"y\": 109.3 "
"            },"
"            \"eyebrowLeftOuter\": {"
"                \"x\": 397.9,"
"                \"y\": 78.5 "
"            },"
"            \"eyebrowLeftInner\": {"
"                \"x\": 425.4,"
"                \"y\": 70.5 "
"            },"
"            \"eyeLeftOuter\": {"
"                \"x\": 406.7,"
"                \"y\": 80.6 "
"            },"
"            \"eyeLeftTop\": {"
"                \"x\": 412.2,"
"                \"y\": 76.2 "
"            },"
"            \"eyeLeftBottom\": {"
"                \"x\": 413.0,"
"                \"y\": 80.1 "
"            },"
"            \"eyeLeftInner\": {"
"                \"x\": 418.9,"
"                \"y\": 78.0 "
"            },"
"            \"eyebrowRightInner\": {"
"                \"x\": 4.8,"
"                \"y\": 69.7 "
"            },"
"            \"eyebrowRightOuter\": {"
"                \"x\": 5.5,"
"                \"y\": 68.5 "
"            },"
"            \"eyeRightInner\": {"
"                \"x\": 441.5,"
"                \"y\": 75.0 "
"            },"
"            \"eyeRightTop\": {"
"                \"x\": 446.4,"
"                \"y\": 71.7 "
"            },"
"            \"eyeRightBottom\": {"
"                \"x\": 447.0,"
"                \"y\": 75.3 "
"            },"
"            \"eyeRightOuter\": {"
"                \"x\": 451.7,"
"                \"y\": 73.4 "
"            },"
"            \"noseRootLeft\": {"
"                \"x\": 428.0,"
"                \"y\": 77.1 "
"            },"
"            \"noseRootRight\": {"
"                \"x\": 435.8,"
"                \"y\": 75.6 "
"            },"
"            \"noseLeftAlarTop\": {"
"                \"x\": 428.3,"
"                \"y\": 89.7 "
"            },"
"            \"noseRightAlarTop\": {"
"                \"x\": 442.2,"
"                \"y\": 87.0 "
"            },"
"            \"noseLeftAlarOutTip\": {"
"                \"x\": 424.3,"
"                \"y\": 96.4 "
"            },"
"            \"noseRightAlarOutTip\": {"
"                \"x\": 446.6,"
"                \"y\": 92.5 "
"            },"
"            \"upperLipTop\": {"
"                \"x\": 437.6,"
"                \"y\": 105.9 "
"            },"
"            \"upperLipBottom\": {"
"                \"x\": 437.6,"
"                \"y\": 108.2 "
"            },"
"            \"underLipTop\": {"
"                \"x\": 436.8,"
"                \"y\": 111.4 "
"            },"
"            \"underLipBottom\": {"
"                \"x\": 437.3,"
"                \"y\": 114.5 "
"            }"
"        },"
"        \"faceAttributes\": {"
"            \"age\": 71.0,"
"            \"gender\": \"male\","
"            \"smile\": 0.88,"
"            \"facialHair\": {"
"                \"moustache\": 0.8,"
"                \"beard\": 0.1,"
"                \"sideburns\": 0.02"
//"                }"
"            },"
"            \"glasses\": \"sunglasses\","
"            \"headPose\": {"
"                \"roll\": 2.1,"
"                \"yaw\": 3,"
"                \"pitch\": 0"
"            },"
"            \"emotion\":{"
"                \"anger\": 0.575,"
"                \"contempt\": 0,"
"                \"disgust\": 0.006,"
"                \"fear\": 0.008,"
"                \"happiness\": 0.394,"
"                \"neutral\": 0.013,"
"                \"sadness\": 0,"
"                \"surprise\": 0.004"
"            },"
"            \"hair\": {"
"                \"bald\": 0.0,"
"                \"invisible\": false,"
"                \"hairColor\": ["
"                    {\"color\": \"brown\", \"confidence\": 1.0},"
"                    {\"color\": \"blond\", \"confidence\": 0.88},"
"                    {\"color\": \"black\", \"confidence\": 0.48},"
"                    {\"color\": \"other\", \"confidence\": 0.11},"
"                    {\"color\": \"gray\", \"confidence\": 0.07},"
"                    {\"color\": \"red\", \"confidence\": 0.03}"
"                ]"
"            },"
"            \"makeup\": {"
"                \"eyeMakeup\": true,"
"                \"lipMakeup\": false"
"            },"
"            \"occlusion\": {"
"                \"foreheadOccluded\": false,"
"                \"eyeOccluded\": false,"
"                \"mouthOccluded\": false"
"            },"
"            \"accessories\": ["
"                {\"type\": \"headWear\", \"confidence\": 0.99},"
"                {\"type\": \"glasses\", \"confidence\": 1.0},"
"                {\"type\": \"mask\",\" confidence\": 0.87}"
"            ],"
"            \"blur\": {"
"                \"blurLevel\":\"Medium\","
"                \"value\":0.51"
"            },"
"            \"exposure\": {"
"                \"exposureLevel\":\"GoodExposure\","
"                \"value\":0.55"
"            },"
"            \"noise\": {"
"                \"noiseLevel\":\"Low\","
"                \"value\":0.12"
"            }"
"        }"
"    }"
"]";
