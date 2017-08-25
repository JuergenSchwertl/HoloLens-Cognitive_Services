#include "pch.h"
#include "Occlusion.h"

using namespace std;
using namespace Platform;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(Occlusion, bool, ForeheadOccluded	, L"foreheadOccluded")
IMPLEMENT_PROPERTY(Occlusion, bool, EyeOccluded			, L"eyeOccluded")
IMPLEMENT_PROPERTY(Occlusion, bool, MouthOccluded		, L"mouthOccluded")

Occlusion::Occlusion()
{
}

void Occlusion::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(ForeheadOccluded) << _COLON << PROPERTY_VARIABLE(ForeheadOccluded) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(EyeOccluded) << _COLON << PROPERTY_VARIABLE(EyeOccluded) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(MouthOccluded) << _COLON << PROPERTY_VARIABLE(MouthOccluded)
		<< _CBRACKET;

}

Platform::String^ Occlusion::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
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
