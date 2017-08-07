#include "pch.h"
#include "FeatureCoordinate.h"

using namespace CognitiveServicesLib;

const wchar_t m_X_Name[] = L"x";


FeatureCoordinate::FeatureCoordinate() :
	X(0.0),
	Y(0.0)
{
	this->X = 0.0;
}
