#include "pch.h"
#include "FeatureCoordinate.h"

using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(FeatureCoordinate, double, X, L"x")
IMPLEMENT_PROPERTY(FeatureCoordinate, double, Y, L"y")

FeatureCoordinate::FeatureCoordinate() :
	PROPERTY_VARIABLE(X)(0.0),
	PROPERTY_VARIABLE(Y)(0.0)
{

}

FeatureCoordinate^ FeatureCoordinate::FromJson(Windows::Data::Json::JsonObject^ jsonObject)
{
	FeatureCoordinate^ fc = nullptr;
	if (jsonObject != nullptr)
	{
		fc = ref new FeatureCoordinate();
		fc->X = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(X), 0.0);
		fc->Y = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Y), 0.0);
	}
	return fc;
}