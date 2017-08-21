#include "pch.h"
#include "FaceRectangle.h"
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(FaceRectangle, int, Width, L"width")
IMPLEMENT_PROPERTY(FaceRectangle, int, Height, L"height")
IMPLEMENT_PROPERTY(FaceRectangle, int, Left, L"left")
IMPLEMENT_PROPERTY(FaceRectangle, int, Top, L"top")

FaceRectangle::FaceRectangle() :
	PROPERTY_VARIABLE( Width )(0),
	PROPERTY_VARIABLE( Height )(0),
	PROPERTY_VARIABLE( Left )(0),
	PROPERTY_VARIABLE( Top )(0)
{
}

FaceRectangle ^ FaceRectangle::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	FaceRectangle^ fr = nullptr;
	if (jsonObject != nullptr)
	{
		fr = ref new FaceRectangle();
		fr->Width = (int) jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Width), 0.0);
		fr->Height = (int) jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Height), 0.0);
		fr->Left = (int) jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Left), 0.0);
		fr->Top = (int) jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Top), 0.0);
	}
	return fr;
}
