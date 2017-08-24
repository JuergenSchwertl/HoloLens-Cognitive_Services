#include "pch.h"
#include "FaceAttributes.h"

using namespace std;
using namespace Platform;
using namespace Windows::Data::Json;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, double, Age, L"age")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, Platform::String^, Gender, L"gender")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::HeadPose^, HeadPose, L"headPose")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, double, Smile, L"smile")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::FacialHair^, FacialHair, L"facialHair")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::EmotionScores^, Emotion, L"emotion")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::Glasses, Glasses, L"glasses")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::Blur^, Blur, L"blur")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::Exposure^, Exposure, L"exposure")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::Noise^, Noise, L"noise")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::Makeup^, Makeup, L"makeup")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, Windows::Foundation::Collections::IVector<CognitiveServicesLib::Accessory^>^, Accessories, L"accessories")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::Occlusion^, Occlusion, L"occlusion")
IMPLEMENT_PROPERTY(CognitiveServicesLib::FaceAttributes, CognitiveServicesLib::Hair^, Hair, L"hair")


FaceAttributes::FaceAttributes()
{
}

void FaceAttributes::toStringStream(std::wostringstream& out)
{
	out.setf(ios::fixed);
	out.precision(1);
	out << _OBRACKET
		<< JSON_PROPERTYNAME_PCWSTR(Age) << _COLON << PROPERTY_VARIABLE(Age) << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Gender) << _COLON << PROPERTY_VARIABLE(Gender)->Data() << L", "
		<< JSON_PROPERTYNAME_PCWSTR(Smile) << _COLON << PROPERTY_VARIABLE(Smile) 
		<< _CBRACKET;
}


Platform::String ^ FaceAttributes::ToString()
{
	std::wostringstream out;
	toStringStream(out);
	out << _ENDS;
	return ref new Platform::String(out.str().c_str());
}

FaceAttributes ^ FaceAttributes::FromJson(JsonObject ^ jsonObject)
{
	FaceAttributes^ attr = nullptr;
	if (jsonObject != nullptr)
	{
		attr = ref new FaceAttributes();
		String^ jsonString = nullptr;
		JsonObject^ jsonObj = nullptr;

		attr->Age = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Age), 0.0);

		attr->Gender = jsonObject->GetNamedString(JSON_PROPERTYNAME(Gender), nullptr);
		
		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(HeadPose), nullptr);
		attr->HeadPose = CognitiveServicesLib::HeadPose::FromJson( jsonObj );
		
		attr->Smile = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Smile), 0.0);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(FacialHair), nullptr);
		attr->FacialHair = CognitiveServicesLib::FacialHair::FromJson(jsonObj);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Emotion), nullptr);
		attr->Emotion = CognitiveServicesLib::EmotionScores::FromJson(jsonObj);

		jsonString = jsonObj->GetNamedString(JSON_PROPERTYNAME(Glasses), nullptr);
		attr->Glasses = GlassesHelper::parse(jsonString);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Blur), nullptr);
		attr->Blur = CognitiveServicesLib::Blur::FromJson(jsonObj);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Exposure), nullptr);
		attr->Exposure = CognitiveServicesLib::Exposure::FromJson(jsonObj);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Noise), nullptr);
		attr->Noise = CognitiveServicesLib::Noise::FromJson(jsonObj);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Makeup), nullptr);
		attr->Makeup = CognitiveServicesLib::Makeup::FromJson(jsonObj);

		JsonArray^ jsonArray = jsonObject->GetNamedArray(JSON_PROPERTYNAME(Accessories), nullptr);
		attr->Accessories = CognitiveServicesLib::Accessory::FromJsonArray(jsonArray);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Occlusion), nullptr);
		attr->Occlusion = CognitiveServicesLib::Occlusion::FromJson(jsonObj);

		jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Hair), nullptr);
		attr->Hair = CognitiveServicesLib::Hair::FromJson(jsonObj);
	}
	return attr;
}