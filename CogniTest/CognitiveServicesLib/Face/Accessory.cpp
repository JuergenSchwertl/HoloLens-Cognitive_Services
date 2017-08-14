#include "pch.h"
#include "Accessory.h"


using namespace Platform;
using namespace Platform::Collections;
using namespace CognitiveServicesLib;
using namespace Windows::Data::Json;
using namespace Windows::Foundation::Collections;


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

IVector<Accessory^>^ Accessory::FromJsonArray(JsonArray ^ jsonArray)
{
	Vector<Accessory^>^ vec = nullptr;
	if (jsonArray != nullptr)
	{
		vec = ref new Vector<Accessory^>;

		for each (IJsonValue^ jsonValue in jsonArray)
		{
			if (jsonValue != nullptr && jsonValue->ValueType == JsonValueType::Object)
			{
				JsonObject^ jsonObject = jsonValue->GetObject();
				Accessory^ accessory = Accessory::FromJson(jsonObject);
				if (accessory != nullptr)
				{
					vec->Append(accessory);
				}
			}
		}
	}
	return vec;
}