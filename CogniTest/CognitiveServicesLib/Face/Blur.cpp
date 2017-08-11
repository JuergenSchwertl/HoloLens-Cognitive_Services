#include "pch.h"
#include "Blur.h"

using namespace CognitiveServicesLib;
using namespace Platform;

#pragma region BlurLevelHelper implementation
EnumKeyJsonName<BlurLevel> BlurLevelHelper::ckvJsonNames[] =
{
	{ BlurLevel::Low, L"Low" },
	{ BlurLevel::Medium, L"Medium" },
	{ BlurLevel::High, L"High" },
};

BlurLevel BlurLevelHelper::parse(Platform::String^ strValue)
{
	return EnumHelper<BlurLevel>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<BlurLevel>));
};

Platform::String^  BlurLevelHelper::toString(BlurLevel enumValue)
{
	return EnumHelper<BlurLevel>::toString(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<BlurLevel>));
};
#pragma endregion

IMPLEMENT_PROPERTY(Blur, CognitiveServicesLib::BlurLevel, BlurLevel, L"blurLevel")
IMPLEMENT_PROPERTY(Blur, double, Value, L"value")


Blur::Blur()
{
}

Blur ^ Blur::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Blur^ blur = nullptr;
	if (jsonObject != nullptr)
	{
		blur = ref new Blur();
		String^ strValue = nullptr;

		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(BlurLevel), nullptr);
		blur->BlurLevel = BlurLevelHelper::parse(strValue);

		blur->Value = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Value), 0.0);
	}
	return blur;
}
