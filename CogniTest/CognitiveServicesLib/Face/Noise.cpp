#include "pch.h"
#include "Noise.h"

using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region NoiseLevelHelper implementation
EnumKeyJsonName<NoiseLevel> NoiseLevelHelper::ckvJsonNames[] =
{
	{ NoiseLevel::Low, L"Low" },
	{ NoiseLevel::Medium, L"Medium" },
	{ NoiseLevel::High, L"High" }
};

NoiseLevel NoiseLevelHelper::parse(Platform::String^ strValue)
{
	return(EnumHelper<NoiseLevel>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<NoiseLevel>)));
};

Platform::String^  NoiseLevelHelper::toString(NoiseLevel enumValue)
{
	return(EnumHelper<NoiseLevel>::toString(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<NoiseLevel>)));
};
#pragma endregion


IMPLEMENT_PROPERTY(Noise, CognitiveServicesLib::NoiseLevel, NoiseLevel, L"noiseLevel")
IMPLEMENT_PROPERTY(Noise, double, Value, L"value")

Noise::Noise()
{
}

Noise ^ Noise::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Noise^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new Noise();
		String^ strValue = nullptr;

		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(NoiseLevel), nullptr);
		obj->NoiseLevel = NoiseLevelHelper::parse(strValue);

		obj->Value = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Value), 0.0);
	}
	return obj;
}
