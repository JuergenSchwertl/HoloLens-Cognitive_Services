#include "pch.h"
#include "FeatureCoordinate.h"
#include "FaceLandmarks.h"
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, PupilLeft, L"pupilLeft")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, PupilRight, L"pupilRight")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseTip, L"noseTip")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, MouthLeft, L"mouthLeft")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, MouthRight, L"mouthRight")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowLeftOuter, L"eyebrowLeftOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowLeftInner, L"eyebrowLeftInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftOuter, L"eyeLeftOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftTop, L"eyeLeftTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftBottom, L"eyeLeftBottom")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftInner, L"eyeLeftInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowRightInner, L"eyebrowRightInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowRightOuter, L"eyebrowRightOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightInner, L"eyeRightInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightTop, L"eyeRightTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightBottom, L"eyeRightBottom")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightOuter, L"eyeRightOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRootLeft, L"noseRootLeft")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRootRight, L"noseRootRight")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseLeftAlarTop, L"noseLeftAlarTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRightAlarTop, L"noseRightAlarTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseLeftAlarOutTip, L"noseLeftAlarOutTip")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRightAlarOutTip, L"noseRightAlarOutTip")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UpperLipTop, L"upperLipTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UpperLipBottom, L"upperLipBottom")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UnderLipTop, L"underLipTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UnderLipBottom, L"underLipBottom")

FaceLandmarks::FaceLandmarks()
{
}

FaceLandmarks ^ FaceLandmarks::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	FaceLandmarks^ fl = nullptr;
	if (jsonObject != nullptr)
	{
		fl = ref new FaceLandmarks();
		fl->PupilLeft = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(PupilLeft),nullptr));
		fl->PupilRight = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(PupilRight), nullptr));
		fl->NoseTip = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(NoseTip), nullptr));
		fl->MouthLeft = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(MouthLeft), nullptr));
		fl->MouthRight = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(MouthRight), nullptr));
		fl->EyeBrowLeftOuter = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeBrowLeftOuter), nullptr));
		fl->EyeBrowLeftInner = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeBrowLeftInner), nullptr));
		fl->EyeLeftOuter = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeLeftOuter), nullptr));
		fl->EyeLeftTop = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeLeftTop), nullptr));
		fl->EyeLeftBottom = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeLeftBottom), nullptr));
		fl->EyeLeftInner = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeLeftInner), nullptr));
		fl->EyeBrowRightInner = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeBrowRightInner), nullptr));
		fl->EyeBrowRightOuter = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeBrowRightOuter), nullptr));
		fl->EyeRightInner = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeRightInner), nullptr));
		fl->EyeRightTop = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeRightTop), nullptr));
		fl->EyeRightBottom = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeRightBottom), nullptr));
		fl->EyeRightOuter = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(EyeRightOuter), nullptr));
		fl->NoseRootLeft = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(NoseRootLeft), nullptr));
		fl->NoseRootRight = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(NoseRootRight), nullptr));
		fl->NoseLeftAlarTop = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(NoseLeftAlarTop), nullptr));
		fl->NoseRightAlarTop = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(NoseRightAlarTop), nullptr));
		fl->NoseLeftAlarOutTip = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(NoseLeftAlarOutTip), nullptr));
		fl->NoseRightAlarOutTip = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(NoseRightAlarOutTip), nullptr));
		fl->UpperLipTop = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(UpperLipTop), nullptr));
		fl->UpperLipBottom = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(UpperLipBottom), nullptr));
		fl->UnderLipTop = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(UnderLipTop), nullptr));
		fl->UnderLipBottom = FeatureCoordinate::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(UnderLipBottom), nullptr));

	}
	return fl;
}
