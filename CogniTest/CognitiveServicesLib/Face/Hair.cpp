#include "pch.h"
#include "Hair.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Data::Json;
using namespace Windows::Foundation::Collections;
using namespace CognitiveServicesLib;

#pragma region HairColorTypeHelper implementation
EnumKeyJsonName<HairColorType> HairColorTypeHelper::ckvJsonNames[] =
{
	{ HairColorType::Unknown, L"unknown" },
	{ HairColorType::White, L"white" },
	{ HairColorType::Gray, L"gray" },
	{ HairColorType::Blond, L"blond" },
	{ HairColorType::Brown, L"brown" },
	{ HairColorType::Red, L"red" },
	{ HairColorType::Black, L"black" },
	{ HairColorType::Other, L"other" },
};

HairColorType HairColorTypeHelper::parse(Platform::String^ strValue)
{
	return(EnumHelper<HairColorType>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<HairColorType>)));
};

Platform::String^  HairColorTypeHelper::toString(HairColorType enumValue)
{
	return(EnumHelper<HairColorType>::toString(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<HairColorType>)));
};
#pragma endregion


IMPLEMENT_PROPERTY(HairColor, CognitiveServicesLib::HairColorType, Color, L"color")
IMPLEMENT_PROPERTY(HairColor, double, Confidence, L"confidence")

HairColor::HairColor()
{
}

HairColor ^ HairColor::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	HairColor^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new HairColor();
		String^ strValue = nullptr;


		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(Color), nullptr);
		obj->Color = HairColorTypeHelper::parse(strValue);

		obj->Confidence = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Confidence), 0.0);
	}
	return obj;
}

IVector<HairColor^>^ HairColor::FromJsonArray(JsonArray ^ jsonArray)
{
	Vector<HairColor^>^ vec = nullptr;
	if (jsonArray != nullptr)
	{
		vec = ref new Vector<HairColor^>;

		for each (IJsonValue^ jsonValue in jsonArray)
		{
			if (jsonValue!=nullptr && jsonValue->ValueType == JsonValueType::Object)
			{
				JsonObject^ jsonObject = jsonValue->GetObject();
				HairColor^ haircolor = HairColor::FromJson(jsonObject);
				if (haircolor != nullptr)
				{
					vec->Append(haircolor);
				}
			}
		}
	}
	return vec;
}


IMPLEMENT_PROPERTY(Hair, double, Bald, L"bald")
IMPLEMENT_PROPERTY(Hair, bool, Invisible, L"invisible")
IMPLEMENT_PROPERTY(Hair, Windows::Foundation::Collections::IVector< CognitiveServicesLib::HairColor^>^, HairColor, L"hairColor")

Hair::Hair()
{
}

Hair ^ Hair::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Hair^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new Hair();

		obj->Bald = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Bald), 0.0);
		obj->Invisible = jsonObject->GetNamedBoolean(JSON_PROPERTYNAME(Invisible), false);

		JsonArray^ jsonArray = jsonObject->GetNamedArray(JSON_PROPERTYNAME(HairColor), nullptr);
		obj->HairColor = CognitiveServicesLib::HairColor::FromJsonArray( jsonArray );
	}
	return obj;
}
