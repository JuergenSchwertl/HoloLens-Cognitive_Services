#include "pch.h"
#include "Occlusion.h"

using namespace Platform;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(Occlusion, bool, ForeheadOccluded	, L"foreheadOccluded")
IMPLEMENT_PROPERTY(Occlusion, bool, EyeOccluded			, L"eyeOccluded")
IMPLEMENT_PROPERTY(Occlusion, bool, MouthOccluded		, L"mouthOccluded")

Occlusion::Occlusion()
{
}

Occlusion ^ Occlusion::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Occlusion^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new Occlusion();
		obj->ForeheadOccluded = jsonObject->GetNamedBoolean(JSON_PROPERTYNAME(ForeheadOccluded), 0.0);
		obj->EyeOccluded = jsonObject->GetNamedBoolean(JSON_PROPERTYNAME(EyeOccluded), 0.0);
		obj->MouthOccluded = jsonObject->GetNamedBoolean(JSON_PROPERTYNAME(MouthOccluded), 0.0);
	}
	return obj;
}
