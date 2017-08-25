#include "pch.h"
#include "FacialHair.h"

using namespace std;
using namespace Platform;
using namespace Windows::Data::Json;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(FacialHair, double, Moustache, L"moustache")
IMPLEMENT_PROPERTY(FacialHair, double, Beard, L"beard")
IMPLEMENT_PROPERTY(FacialHair, double, Sideburns, L"value")


FacialHair::FacialHair()
{
}

void FacialHair::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(Moustache) << _COLON << PROPERTY_VARIABLE(Moustache) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Beard) << _COLON << PROPERTY_VARIABLE(Beard) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Sideburns) << _COLON << PROPERTY_VARIABLE(Sideburns)
		<< _CBRACKET;

}

Platform::String^ FacialHair::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
}

FacialHair ^ FacialHair::FromJson(JsonObject ^ jsonObject)
{
	FacialHair^ fh = nullptr;
	if (jsonObject != nullptr)
	{
		fh = ref new FacialHair();
		fh->Moustache = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Moustache), 0.0);
		fh->Beard = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Beard), 0.0);
		fh->Sideburns = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Sideburns), 0.0);
	}
	return fh;
}
