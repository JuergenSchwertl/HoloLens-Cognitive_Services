#include "pch.h"
#include "Accessory.h"

using namespace std;
using namespace Platform;
using namespace Platform::Collections;
using namespace CognitiveServicesLib;
using namespace Windows::Data::Json;
using namespace Windows::Foundation::Collections;


#pragma region AccessoryTypeHelper implementation
EnumKeyJsonName<AccessoryType> AccessoryTypeHelper::ckvJsonNames[] =
{
	{ AccessoryType::Headwear, L"headWear" },
	{ AccessoryType::Glasses, L"glasses" },
	{ AccessoryType::Mask, L"mask" },
};

AccessoryType AccessoryTypeHelper::parse(Platform::String^ strValue)
{
	return EnumHelper<AccessoryType>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<AccessoryType>));
}

LPCTSTR AccessoryTypeHelper::c_str(AccessoryType enumValue)
{
	return(EnumHelper<AccessoryType>::c_str(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<AccessoryType>)));
}

Platform::String^ AccessoryTypeHelper::toString(AccessoryType enumValue)
{
	return(ref new Platform::String(c_str(enumValue)));
}

#pragma endregion



IMPLEMENT_PROPERTY(Accessory, CognitiveServicesLib::AccessoryType, Type, L"type")
IMPLEMENT_PROPERTY(Accessory, double, Confidence, L"confidence")


Accessory::Accessory() :
	PROPERTY_VARIABLE(Type)( (AccessoryType) 0),
	PROPERTY_VARIABLE(Confidence)(0.0)
{
}

void Accessory::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(2);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(Type) << _COLON << AccessoryTypeHelper::c_str(PROPERTY_VARIABLE(Type)) << L", "
		<< L"c:" << PROPERTY_VARIABLE(Confidence)
		<< _CBRACKET;
}

Platform::String^ Accessory::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
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