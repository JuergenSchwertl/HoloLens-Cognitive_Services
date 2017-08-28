#include "pch.h"
#include "Glasses.h"

using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region GlassesHelper implementation
EnumKeyJsonName<Glasses> GlassesHelper::ckvJsonNames[4] =
{
	{ Glasses::NoGlasses, L"NoGlasses" },
	{ Glasses::Sunglasses, L"Sunglasses" },
	{ Glasses::ReadingGlasses, L"ReadingGlasses" },
	{ Glasses::SwimmingGoggles, L"SwimmingGoggles" }
};
#pragma endregion

void GlassesHelper::Test()
{
	std::wostringstream out;
	size_t s1 = sizeof(CognitiveServicesLib::GlassesHelper::ckvJsonNames);
	size_t s2 = sizeof(EnumKeyJsonName<CognitiveServicesLib::Glasses>);

	
}