#include "pch.h"
#include "FaceRectangle.h"
#include "FeatureCoordinate.h"
#include "FaceLandmarks.h"
#include "Face.h"

using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(Face, GUID, FaceId, L"faceId")
IMPLEMENT_PROPERTY(Face, CognitiveServicesLib::FaceRectangle^, FaceRectangle, L"faceRectangle")
IMPLEMENT_PROPERTY(Face, CognitiveServicesLib::FaceLandmarks^, FaceLandmarks, L"faceLandmarks")
//IMPLEMENT_PROPERTY(Face, FaceAttributes^, FaceAttributes, L"faceAttributes")


Face::Face()
{
	
}
