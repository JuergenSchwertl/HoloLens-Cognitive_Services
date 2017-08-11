#include "pch.h"
#include "Accessory.h"


using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region AccessoryTypeHelper implementation
EnumKeyJsonName<AccessoryType> AccessoryTypeHelper::ckvJsonNames[] =
{
	{ AccessoryType::Headwear, L"Headwear" },
	{ AccessoryType::Glasses, L"Glasses" },
	{ AccessoryType::Mask, L"Mask" },
};

AccessoryType AccessoryTypeHelper::parse(Platform::String^ strValue)
{
	return EnumHelper<AccessoryType>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<AccessoryType>));
};

Platform::String^  AccessoryTypeHelper::toString(AccessoryType enumValue)
{
	return EnumHelper<AccessoryType>::toString(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<AccessoryType>));
};
#pragma endregion



IMPLEMENT_PROPERTY(Accessory, CognitiveServicesLib::AccessoryType, Type, L"type")
IMPLEMENT_PROPERTY(Accessory, double, Confidence, L"confidence")


Accessory::Accessory()
{
}

Accessory ^ Accessory::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Accessory^ accessory = nullptr;
	if (jsonObject != nullptr)
	{
		accessory = ref new Accessory();
		String^ strValue = nullptr;

		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(Type), nullptr);
		accessory->Type = AccessoryTypeHelper::parse(strValue);

		accessory->Confidence = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Confidence), 0.0);
	}
	return accessory;
}
