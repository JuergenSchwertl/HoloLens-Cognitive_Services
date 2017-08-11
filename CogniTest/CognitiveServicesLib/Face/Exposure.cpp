#include "pch.h"
#include "Exposure.h"

using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region ExposureLevelHelper implementation
EnumKeyJsonName<ExposureLevel> ExposureLevelHelper::ckvJsonNames[] =
{
	{ ExposureLevel::UnderExposure, L"UnderExposure" },
	{ ExposureLevel::GoodExposure, L"GoodExposure" },
	{ ExposureLevel::OverExposure, L"OverExposure" },
};

ExposureLevel ExposureLevelHelper::parse(Platform::String^ strValue)
{
	return(EnumHelper<ExposureLevel>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<ExposureLevel>)));
};

Platform::String^  ExposureLevelHelper::toString(ExposureLevel enumValue)
{
	return(EnumHelper<ExposureLevel>::toString(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<ExposureLevel>)));
};
#pragma endregion



IMPLEMENT_PROPERTY(Exposure, CognitiveServicesLib::ExposureLevel, ExposureLevel, L"exposureLevel")
IMPLEMENT_PROPERTY(Exposure, double, Value, L"value")


Exposure::Exposure()
{
}

Exposure ^ CognitiveServicesLib::Exposure::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Exposure^ exp = nullptr;
	if (jsonObject != nullptr)
	{
		exp = ref new Exposure();
		String^ strValue = nullptr;


		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(ExposureLevel), nullptr);
		exp->ExposureLevel = ExposureLevelHelper::parse(strValue);

		exp->Value = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Value), 0.0);
	}
	return exp;
}
