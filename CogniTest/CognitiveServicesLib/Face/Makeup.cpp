#include "pch.h"
#include "Makeup.h"

using namespace std;
using namespace Platform;
using namespace CognitiveServicesLib;


IMPLEMENT_PROPERTY(Makeup, bool, EyeMakeup, L"eyeMakeup")
IMPLEMENT_PROPERTY(Makeup, bool, LipMakeup, L"lipMakeup")

Makeup::Makeup()
{
}

void Makeup::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(EyeMakeup) << _COLON << PROPERTY_VARIABLE(EyeMakeup) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(LipMakeup) << _COLON << PROPERTY_VARIABLE(LipMakeup)
		<< _CBRACKET;

}

Platform::String^ Makeup::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
}

Makeup ^ Makeup::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Makeup^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new Makeup();
		String^ strValue = nullptr;
		obj->EyeMakeup = jsonObject->GetNamedBoolean(JSON_PROPERTYNAME(EyeMakeup), 0.0);
		obj->LipMakeup = jsonObject->GetNamedBoolean(JSON_PROPERTYNAME(LipMakeup), 0.0);
	}
	return obj;
}
