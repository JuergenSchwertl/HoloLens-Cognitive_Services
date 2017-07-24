#include "pch.h"
#include "FileHelper.h"
#include "HpptClientImpl.h"
#include "FaceClient.h"

using namespace Concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;

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

///<summary>Detects faces from an image file</summary>
///<param name="FileUri">Uri to an Image on the web or locally (msappx://)</param>
///<returns>async task completing with Face - Detect API response as json string</returns>
IAsyncOperation<Platform::String^>^ FaceClient::DetectAsync(Uri^ FileUri)
{
	auto postaction = create_async([=]() {
		Uri^ uriEndpoint = EndpointHelper::BuildEndpointUri(EndpointHelper::FaceDetect, m_Region, Parameters::FaceAttributes);

		return m_WebClient.PostUriAsync(uriEndpoint, FileUri);
	});
	return postaction;
}


///<summary>Detects faces from an image file</summary>
///<param name="FileName">Image file name</param>
///<returns>async task completing with Face - Detect API response as json string</returns>
IAsyncOperation<String^>^ FaceClient::FakeDetectAsync(Platform::String^ FileName)
{
	auto postaction = create_async([=]() {
		return task_from_result( jsonResult );
	});
	return postaction;
}

String^ FaceClient::jsonResult = L""  
"["
"  {"
"    ""FaceId"": ""cd94c536-9839-46ac-b45b-3ad6e41776f5"","
"    ""FaceRectangle"": {"
"      ""Top"": 116,"
"      ""Left"": 265,"
"      ""Width"": 140,"
"      ""Height"": 140"
"    },"
"    ""FaceAttributes"": {"
"      ""Hair"": {"
"        ""Bald"": 0.04,"
"        ""Invisible"": false,"
"        ""HairColor"": ["
"          {"
"            ""Color"": ""black"","
"            ""Confidence"": 1.0"
"          },"
"          {"
"            ""Color"": ""brown"","
"            ""Confidence"": 0.98"
"          },"
"          {"
"            ""Color"": ""red"","
"            ""Confidence"": 0.14"
"          },"
"          {"
"            ""Color"": ""gray"","
"            ""Confidence"": 0.13"
"          },"
"          {"
"            ""Color"": ""other"","
"            ""Confidence"": 0.11"
"          },"
"          {"
"            ""Color"": ""blond"","
"            ""Confidence"": 0.02"
"          }"
"        ]"
"      },"
"      ""Smile"": 1.0,"
"      ""HeadPose"": {"
"        ""Pitch"": 0.0,"
"        ""Roll"": 3.0,"
"        ""Yaw"": 0.5"
"      },"
"      ""Gender"": ""male"","
"      ""Age"": 30.0,"
"      ""FacialHair"": {"
"        ""Moustache"": 0.2,"
"        ""Beard"": 0.1,"
"        ""Sideburns"": 0.1"
"      },"
"      ""Glasses"": ""NoGlasses"","
"      ""Makeup"": {"
"        ""EyeMakeup"": false,"
"        ""LipMakeup"": false"
"      },"
"      ""Emotion"": {"
"        ""Anger"": 0.0,"
"        ""Contempt"": 0.0,"
"        ""Disgust"": 0.0,"
"        ""Fear"": 0.0,"
"        ""Happiness"": 1.0,"
"        ""Neutral"": 0.0,"
"        ""Sadness"": 0.0,"
"        ""Surprise"": 0.0"
"      },"
"      ""Occlusion"": {"
"        ""ForeheadOccluded"": false,"
"        ""EyeOccluded"": false,"
"        ""MouthOccluded"": false"
"      },"
"      ""Accessories"": [],"
"      ""Blur"": {"
"        ""BlurLevel"": ""low"","
"        ""Value"": 0.11"
"      },"
"      ""Exposure"": {"
"        ""ExposureLevel"": ""goodExposure"","
"        ""Value"": 0.59"
"      },"
"      ""Noise"": {"
"        ""NoiseLevel"": ""medium"","
"        ""Value"": 0.3"
"      }"
"    },"
"    ""FaceLandmarks"": {"
"      ""PupilLeft"": {"
"        ""X"": 303.6,"
"        ""Y"": 155.1"
"      },"
"      ""PupilRight"": {"
"        ""X"": 368.1,"
"        ""Y"": 159.5"
"      },"
"      ""NoseTip"": {"
"        ""X"": 336.8,"
"        ""Y"": 189.8"
"      },"
"      ""MouthLeft"": {"
"        ""X"": 298.2,"
"        ""Y"": 213.7"
"      },"
"      ""MouthRight"": {"
"        ""X"": 368.3,"
"        ""Y"": 217.8"
"      },"
"      ""EyebrowLeftOuter"": {"
"        ""X"": 280.7,"
"        ""Y"": 140.9"
"      },"
"      ""EyebrowLeftInner"": {"
"        ""X"": 323.1,"
"        ""Y"": 143.2"
"      },"
"      ""EyeLeftOuter"": {"
"        ""X"": 291.5,"
"        ""Y"": 155.5"
"      },"
"      ""EyeLeftTop"": {"
"        ""X"": 303.5,"
"        ""Y"": 151.8"
"      },"
"      ""EyeLeftBottom"": {"
"        ""X"": 302.5,"
"        ""Y"": 161.1"
"      },"
"      ""EyeLeftInner"": {"
"        ""X"": 314.9,"
"        ""Y"": 158.0"
"      },"
"      ""EyebrowRightInner"": {"
"        ""X"": 352.4,"
"        ""Y"": 144.5"
"      },"
"      ""EyebrowRightOuter"": {"
"        ""X"": 394.9,"
"        ""Y"": 150.7"
"      },"
"      ""EyeRightInner"": {"
"        ""X"": 357.7,"
"        ""Y"": 160.4"
"      },"
"      ""EyeRightTop"": {"
"        ""X"": 368.1,"
"        ""Y"": 156.2"
"      },"
"      ""EyeRightBottom"": {"
"        ""X"": 367.6,"
"        ""Y"": 164.3"
"      },"
"      ""EyeRightOuter"": {"
"        ""X"": 378.5,"
"        ""Y"": 161.8"
"      },"
"      ""NoseRootLeft"": {"
"        ""X"": 326.5,"
"        ""Y"": 159.4"
"      },"
"      ""NoseRootRight"": {"
"        ""X"": 347.1,"
"        ""Y"": 160.7"
"      },"
"      ""NoseLeftAlarTop"": {"
"        ""X"": 320.2,"
"        ""Y"": 179.1"
"      },"
"      ""NoseRightAlarTop"": {"
"        ""X"": 352.3,"
"        ""Y"": 179.6"
"      },"
"      ""NoseLeftAlarOutTip"": {"
"        ""X"": 314.7,"
"        ""Y"": 191.3"
"      },"
"      ""NoseRightAlarOutTip"": {"
"        ""X"": 359.6,"
"        ""Y"": 190.8"
"      },"
"      ""UpperLipTop"": {"
"        ""X"": 334.6,"
"        ""Y"": 210.6"
"      },"
"      ""UpperLipBottom"": {"
"        ""X"": 333.7,"
"        ""Y"": 216.6"
"      },"
"      ""UnderLipTop"": {"
"        ""X"": 333.9,"
"        ""Y"": 224.5"
"      },"
"      ""UnderLipBottom"": {"
"        ""X"": 332.1,"
"        ""Y"": 234.6"
"      }"
"    }"
"  }"
"]";
