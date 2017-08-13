#include "pch.h"
#include "Glasses.h"

using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region FaceTestEnumHelper implementation
EnumKeyJsonName<Glasses> GlassesHelper::ckvJsonNames[] =
{
	{ Glasses::NoGlasses, L"NoGlasses" },
	{ Glasses::Sunglasses, L"Sunglasses" },
	{ Glasses::ReadingGlasses, L"ReadingGlasses" },
	{ Glasses::SwimmingGoggles, L"SwimmingGoggles" }
};

Glasses CognitiveServicesLib::GlassesHelper::parse(Platform::String^ strValue)
{
	return(EnumHelper<Glasses>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<Glasses>)));
};

Platform::String^  CognitiveServicesLib::GlassesHelper::toString(Glasses enumValue)
{
	return(EnumHelper<Glasses>::toString(enumValue, ckvJsonNames, sizeof(ckvJsonNames) / sizeof(EnumKeyJsonName<Glasses>)));
};
#pragma endregion

