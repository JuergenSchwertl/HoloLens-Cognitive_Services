#include "pch.h"
#include "Makeup.h"

using namespace Platform;
using namespace CognitiveServicesLib;


IMPLEMENT_PROPERTY(Makeup, bool, EyeMakeup, L"eyeMakeup")
IMPLEMENT_PROPERTY(Makeup, bool, LipMakeup, L"lipMakeup")

Makeup::Makeup()
{
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
