#include "pch.h"
#include "FeatureCoordinate.h"

using namespace std;
using namespace CognitiveServicesLib;
using namespace Platform::Runtime::CompilerServices; 

IMPLEMENT_PROPERTY(FeatureCoordinate, double, X, L"x")
IMPLEMENT_PROPERTY(FeatureCoordinate, double, Y, L"y")

FeatureCoordinate::FeatureCoordinate() :
	PROPERTY_VARIABLE(X)(0.0),
	PROPERTY_VARIABLE(Y)(0.0)
{

}

void FeatureCoordinate::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << L"(" 
		<< JSON_PROPERTYNAME_PCWSTR(X) << L":" << PROPERTY_VARIABLE(X) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Y) << L":" << PROPERTY_VARIABLE(Y)
		<< L")";
}



Platform::String ^ CognitiveServicesLib::FeatureCoordinate::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << ends;
	return ref new Platform::String(out.str().c_str());
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

