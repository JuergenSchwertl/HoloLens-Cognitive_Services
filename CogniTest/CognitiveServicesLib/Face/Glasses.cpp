#include "pch.h"
#include "Glasses.h"

using namespace Platform;
using namespace CognitiveServicesLib;

#pragma region FaceTestEnumHelper implementation
EnumKeyJsonName<CognitiveServicesLib::Glasses> GlassesHelper::ckvJsonNames[] =
{
	{ Glasses::NoGlasses, L"NoGlasses" },
	{ Glasses::Sunglasses, L"Sunglasses" },
	{ Glasses::ReadingGlasses, L"ReadingGlasses" },
	{ Glasses::SwimmingGoggles, L"SwimmingGoggles" }
};
#pragma endregion

