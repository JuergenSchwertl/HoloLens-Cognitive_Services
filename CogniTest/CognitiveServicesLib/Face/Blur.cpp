#include "pch.h"
#include "Blur.h"

using namespace std;
using namespace CognitiveServicesLib;
using namespace Platform;

#pragma region BlurLevelHelper implementation
EnumKeyJsonName<BlurLevel> BlurLevelHelper::ckvJsonNames[3] =
{
	{ BlurLevel::Low, L"Low" },
	{ BlurLevel::Medium, L"Medium" },
	{ BlurLevel::High, L"High" },
};
#pragma endregion

IMPLEMENT_PROPERTY(Blur, CognitiveServicesLib::BlurLevel, BlurLevel, L"blurLevel")
IMPLEMENT_PROPERTY(Blur, double, Value, L"value")


Blur::Blur()
{
}

void Blur::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(BlurLevel) << _COLON 
		<< EnumHelper<CognitiveServicesLib::BlurLevel, BlurLevelHelper>::c_str( PROPERTY_VARIABLE(BlurLevel) ) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Value) << _COLON << PROPERTY_VARIABLE(Value)
		<< _CBRACKET;

}

Platform::String^ Blur::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
}

Blur ^ Blur::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Blur^ blur = nullptr;
	if (jsonObject != nullptr)
	{
		blur = ref new Blur();
		String^ strValue = nullptr;

		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(BlurLevel), nullptr);
		blur->BlurLevel = EnumHelper<CognitiveServicesLib::BlurLevel,BlurLevelHelper>::parse(strValue);

		blur->Value = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Value), 0.0);
	}
	return blur;
}
