#include "pch.h"
#include "Exposure.h"

using namespace std;
using namespace Platform;
using namespace CognitiveServicesLib;




#pragma region ExposureLevelHelper implementation
EnumKeyJsonName<ExposureLevel> ExposureLevelHelper::ckvJsonNames[3] =
{
	{ ExposureLevel::UnderExposure, L"UnderExposure" },
	{ ExposureLevel::GoodExposure, L"GoodExposure" },
	{ ExposureLevel::OverExposure, L"OverExposure" },
};
#pragma endregion



IMPLEMENT_PROPERTY(Exposure, CognitiveServicesLib::ExposureLevel, ExposureLevel, L"exposureLevel")
IMPLEMENT_PROPERTY(Exposure, double, Value, L"value")


Exposure::Exposure()
{
}

void Exposure::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(2);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(ExposureLevel) << _COLON
		<< EnumHelper<CognitiveServicesLib::ExposureLevel, ExposureLevelHelper>::c_str(PROPERTY_VARIABLE(ExposureLevel))
		<< JSON_PROPERTYNAME_PCWSTR(ExposureLevel) << _COLON << PROPERTY_VARIABLE(Value)
		<< _CBRACKET;
}

Platform::String^ Exposure::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
}

Exposure ^ Exposure::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Exposure^ exp = nullptr;
	if (jsonObject != nullptr)
	{
		exp = ref new Exposure();
		String^ strValue = nullptr;


		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(ExposureLevel), nullptr);
		exp->ExposureLevel = EnumHelper<CognitiveServicesLib::ExposureLevel, ExposureLevelHelper>::parse(strValue);

		exp->Value = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Value), 0.0);
	}
	return exp;
}
