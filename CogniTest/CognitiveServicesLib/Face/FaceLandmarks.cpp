#include "pch.h"
#include "FaceLandmarks.h"

using namespace std;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, PupilLeft			, L"pupilLeft")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, PupilRight		, L"pupilRight")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseTip			, L"noseTip")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, MouthLeft			, L"mouthLeft")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, MouthRight		, L"mouthRight")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowLeftOuter	, L"eyebrowLeftOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowLeftInner	, L"eyebrowLeftInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftOuter		, L"eyeLeftOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftTop		, L"eyeLeftTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftBottom		, L"eyeLeftBottom")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeLeftInner		, L"eyeLeftInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowRightInner	, L"eyebrowRightInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeBrowRightOuter	, L"eyebrowRightOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightInner		, L"eyeRightInner")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightTop		, L"eyeRightTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightBottom	, L"eyeRightBottom")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, EyeRightOuter		, L"eyeRightOuter")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRootLeft		, L"noseRootLeft")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRootRight		, L"noseRootRight")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseLeftAlarTop	, L"noseLeftAlarTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRightAlarTop	, L"noseRightAlarTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseLeftAlarOutTip, L"noseLeftAlarOutTip")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, NoseRightAlarOutTip, L"noseRightAlarOutTip")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UpperLipTop		, L"upperLipTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UpperLipBottom	, L"upperLipBottom")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UnderLipTop		, L"underLipTop")
IMPLEMENT_PROPERTY(FaceLandmarks, FeatureCoordinate^, UnderLipBottom	, L"underLipBottom")

FaceLandmarks::FaceLandmarks()
{
}


void FaceLandmarks::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << JSON_PROPERTYNAME_PCWSTR(PupilLeft) << _COLON; PROPERTY_VARIABLE(PupilLeft)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(PupilLeft) << _COLON; PROPERTY_VARIABLE(PupilLeft)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(PupilRight) << _COLON; PROPERTY_VARIABLE(PupilRight)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(NoseTip) << _COLON; PROPERTY_VARIABLE(NoseTip)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(MouthLeft) << _COLON; PROPERTY_VARIABLE(MouthLeft)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(MouthRight) << _COLON; PROPERTY_VARIABLE(MouthRight)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeBrowLeftOuter) << _COLON; PROPERTY_VARIABLE(EyeBrowLeftOuter)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeBrowLeftInner) << _COLON; PROPERTY_VARIABLE(EyeBrowLeftInner)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeLeftOuter) << _COLON; PROPERTY_VARIABLE(EyeLeftOuter)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeLeftTop) << _COLON; PROPERTY_VARIABLE(EyeLeftTop)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeLeftBottom) << _COLON; PROPERTY_VARIABLE(EyeLeftBottom)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeLeftInner) << _COLON; PROPERTY_VARIABLE(EyeLeftInner)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeBrowRightInner) << _COLON; PROPERTY_VARIABLE(EyeBrowRightInner)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeBrowRightOuter) << _COLON; PROPERTY_VARIABLE(EyeBrowRightOuter)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeRightInner) << _COLON; PROPERTY_VARIABLE(EyeRightInner)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeRightTop) << _COLON; PROPERTY_VARIABLE(EyeRightTop)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeRightBottom) << _COLON; PROPERTY_VARIABLE(EyeRightBottom)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(EyeRightOuter) << _COLON; PROPERTY_VARIABLE(EyeRightOuter)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(NoseRootLeft) << _COLON; PROPERTY_VARIABLE(NoseRootLeft)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(NoseRootRight) << _COLON; PROPERTY_VARIABLE(NoseRootRight)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(NoseLeftAlarTop) << _COLON; PROPERTY_VARIABLE(NoseLeftAlarTop)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(NoseRightAlarTop) << _COLON; PROPERTY_VARIABLE(NoseRightAlarTop)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(NoseLeftAlarOutTip) << _COLON; PROPERTY_VARIABLE(NoseLeftAlarOutTip)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(NoseRightAlarOutTip) << _COLON; PROPERTY_VARIABLE(NoseRightAlarOutTip)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(UpperLipTop) << _COLON; PROPERTY_VARIABLE(UpperLipTop)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(UpperLipBottom) << _COLON; PROPERTY_VARIABLE(UpperLipBottom)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(UnderLipTop) << _COLON; PROPERTY_VARIABLE(UnderLipTop)->toStringStream(out); out << _ENDL;
	out << JSON_PROPERTYNAME_PCWSTR(UnderLipBottom) << _COLON; PROPERTY_VARIABLE(UnderLipBottom)->toStringStream(out); out << _ENDL;
}

Platform::String^ FaceLandmarks::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << ends;
	return ref new Platform::String(out.str().c_str());
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
