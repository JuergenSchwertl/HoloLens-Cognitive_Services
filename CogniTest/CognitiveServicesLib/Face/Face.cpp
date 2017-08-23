#include "pch.h"
#include "Face.h"

using namespace std;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;
using namespace Windows::Data::Json;

IMPLEMENT_PROPERTY(Face, Platform::String^, FaceId, L"faceId")
IMPLEMENT_PROPERTY(Face, CognitiveServicesLib::FaceRectangle^, FaceRectangle, L"faceRectangle")
IMPLEMENT_PROPERTY(Face, CognitiveServicesLib::FaceLandmarks^, FaceLandmarks, L"faceLandmarks")
IMPLEMENT_PROPERTY(Face, CognitiveServicesLib::FaceAttributes^, FaceAttributes, L"faceAttributes")


Face::Face() :
	PROPERTY_VARIABLE(FaceId)(nullptr),
	PROPERTY_VARIABLE(FaceRectangle)(nullptr),
	PROPERTY_VARIABLE(FaceLandmarks)(nullptr),
	PROPERTY_VARIABLE(FaceAttributes)(nullptr)
{
	
}

void Face::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << JSON_PROPERTYNAME_PCWSTR(FaceId) << _COLON << PROPERTY_VARIABLE(FaceId)->Data() << _ENDL
		<< JSON_PROPERTYNAME_PCWSTR(FaceRectangle) << _COLON;

	if (JSON_PROPERTYNAME_PCWSTR(FaceRectangle) == nullptr)
	{
		out << CSTR_NULL;
	}
	else
	{
		FaceRectangle->toStringStream(out);
		out << _ENDL;
	}

	if (JSON_PROPERTYNAME_PCWSTR(FaceLandmarks) == nullptr)
	{
		out << CSTR_NULL;
	}
	else
	{
		FaceLandmarks->toStringStream(out);
		out << _ENDL;
	}

	if (JSON_PROPERTYNAME_PCWSTR(FaceAttributes) == nullptr)
	{
		out << CSTR_NULL;
	}
	else
	{
//		FaceAttributes->toStringStream(out);
		out << _ENDL;
	}

}

Platform::String^ Face::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	out.flush();
	return ref new Platform::String(out.str().c_str());
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
		face->FaceAttributes = CognitiveServicesLib::FaceAttributes::FromJson(jsonObject->GetNamedObject(JSON_PROPERTYNAME(FaceAttributes), nullptr));
	}
	return face;
}

Windows::Foundation::Collections::IVector<Face^>^ Face::FromJsonArray(Windows::Data::Json::JsonArray^ jsonArray)
{
	Vector<Face^>^ vecFaces = ref new Vector<Face^ >();
	for (auto m : jsonArray)
	{
		if (m->ValueType == JsonValueType::Object)
		{
			JsonObject^ jsonObject = m->GetObject();
			Face^ face = Face::FromJson(jsonObject);
			vecFaces->Append(face);
		}
	}
	return safe_cast<IVector<CognitiveServicesLib::Face^>^>( vecFaces );
}

Windows::Foundation::Collections::IVector<Face^>^ Face::FromJsonString(Platform::String^ jsonString)
{
	JsonArray^ jsonArray = nullptr;
	if (JsonArray::TryParse(jsonString, &jsonArray))
	{
		return Face::FromJsonArray(jsonArray);
	}
	return nullptr;
}