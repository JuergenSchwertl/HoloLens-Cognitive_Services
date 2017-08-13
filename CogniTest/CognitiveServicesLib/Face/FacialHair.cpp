#include "pch.h"
#include "FacialHair.h"

using namespace Platform;
using namespace Windows::Data::Json;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(FacialHair, double, Moustache, L"moustache")
IMPLEMENT_PROPERTY(FacialHair, double, Beard, L"beard")
IMPLEMENT_PROPERTY(FacialHair, double, Sideburns, L"value")


FacialHair::FacialHair()
{
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
