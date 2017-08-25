#include "pch.h"
#include "HeadPose.h"

using namespace std;
using namespace Platform;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(HeadPose, double, Roll, L"roll")
IMPLEMENT_PROPERTY(HeadPose, double, Yaw, L"yaw")
IMPLEMENT_PROPERTY(HeadPose, double, Pitch, L"pitch")


CognitiveServicesLib::HeadPose::HeadPose()
{
}

void HeadPose::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(Roll) << _COLON << PROPERTY_VARIABLE(Roll) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Yaw) << _COLON << PROPERTY_VARIABLE(Yaw) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Pitch) << _COLON << PROPERTY_VARIABLE(Pitch)
		<< _CBRACKET;

}

Platform::String^ HeadPose::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
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
