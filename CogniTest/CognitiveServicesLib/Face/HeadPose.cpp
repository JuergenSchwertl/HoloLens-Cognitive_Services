#include "pch.h"
#include "HeadPose.h"

using namespace Platform;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(HeadPose, double, Roll, L"roll")
IMPLEMENT_PROPERTY(HeadPose, double, Yaw, L"yaw")
IMPLEMENT_PROPERTY(HeadPose, double, Pitch, L"pitch")


CognitiveServicesLib::HeadPose::HeadPose()
{
}

HeadPose ^ HeadPose::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	HeadPose^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new HeadPose();
		obj->Roll = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Roll), 0.0);
		obj->Yaw = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Yaw), 0.0);
		obj->Pitch = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Pitch), 0.0);
	}
	return obj;
}
