#include "pch.h"
#include "FaceRectangle.h"
#include "FeatureCoordinate.h"
#include "FaceLandmarks.h"
#include "Face.h"

using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(Face, Platform::String^, FaceId, L"faceId")
IMPLEMENT_PROPERTY(Face, CognitiveServicesLib::FaceRectangle^, FaceRectangle, L"faceRectangle")
IMPLEMENT_PROPERTY(Face, CognitiveServicesLib::FaceLandmarks^, FaceLandmarks, L"faceLandmarks")
//IMPLEMENT_PROPERTY(Face, FaceAttributes^, FaceAttributes, L"faceAttributes")


Face::Face()
{
	
}

Face ^ CognitiveServicesLib::Face::FromJson(Windows::Data::Json::JsonObject^ jsonObject)
{
	Face^ face = nullptr;
	if (jsonObject != nullptr)
	{
		face = ref new Face();
		face->FaceId = jsonObject->GetNamedString(JSON_PROPERTYNAME(FaceId), nullptr);
		face->FaceRectangle = CognitiveServicesLib::FaceRectangle::FromJson( jsonObject->GetNamedObject(JSON_PROPERTYNAME(FaceRectangle), nullptr) );
		face->FaceLandmarks = CognitiveServicesLib::FaceLandmarks::FromJson( jsonObject->GetNamedObject(JSON_PROPERTYNAME(FaceLandmarks), nullptr));
		//face->FaceAttributes = CognitiveServicesLib::FaceAtributes::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(FaceRectangle), nullptr));
	}
	return face;
}
