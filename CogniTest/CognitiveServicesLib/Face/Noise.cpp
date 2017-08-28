#include "pch.h"
#include "Noise.h"

using namespace std;
using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region NoiseLevelHelper implementation
EnumKeyJsonName<NoiseLevel> NoiseLevelHelper::ckvJsonNames[3] =
{
	{ NoiseLevel::Low, L"Low" },
	{ NoiseLevel::Medium, L"Medium" },
	{ NoiseLevel::High, L"High" }
};
#pragma endregion


IMPLEMENT_PROPERTY(Noise, CognitiveServicesLib::NoiseLevel, NoiseLevel, L"noiseLevel")
IMPLEMENT_PROPERTY(Noise, double, Value, L"value")

Noise::Noise()
{
}

void Noise::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(NoiseLevel) << _COLON
		<< EnumHelper<CognitiveServicesLib::NoiseLevel, NoiseLevelHelper>::c_str(NoiseLevel) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Value) << _COLON << PROPERTY_VARIABLE(Value)
		<< _CBRACKET;

}

Platform::String^ Noise::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
}

Noise ^ Noise::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	Noise^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new Noise();
		String^ strValue = nullptr;

		strValue = jsonObject->GetNamedString(JSON_PROPERTYNAME(NoiseLevel), nullptr);
		obj->NoiseLevel = EnumHelper<CognitiveServicesLib::NoiseLevel,NoiseLevelHelper>::parse(strValue);

		obj->Value = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Value), 0.0);
	}
	return obj;
}
