#include "pch.h"
#include "FaceTest.h"

using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region FaceTestEnumHelper implementation
EnumKeyJsonName<FaceTestEnum> FaceTestEnumHelper::ckvJsonNames[] =
{
	{ FaceTestEnum::Value1, L"Value1" }};

FaceTestEnum FaceTestEnumHelper::parse(Platform::String^ strValue)
{
	return(EnumHelper<FaceTestEnum>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<FaceTestEnum>)));
};

Platform::String^  FaceTestEnumHelper::toString(FaceTestEnum enumValue)
{
	return(EnumHelper<FaceTestEnum>::toString(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<FaceTestEnum>)));
};
#pragma endregion


IMPLEMENT_PROPERTY(FaceTest, CognitiveServicesLib::FaceTestEnum, FaceTestEnumName, L"faceTestEnumName")
IMPLEMENT_PROPERTY(FaceTest, double, Value, L"value")

FaceTest::FaceTest()
{
}

FaceTest ^ FaceTest::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	FaceTest^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new FaceTest();
		String^ strValue = nullptr;


		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(FaceTestEnumName), nullptr);
		obj->FaceTestEnumName = FaceTestEnumHelper::parse(strValue);

		obj->Value = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Value), 0.0);
	}
	return obj;
}
