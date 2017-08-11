#include "pch.h"
#include "Accessory.h"
#include "Blur.h"
#include "Exposure.h"
#include "FaceAttributes.h"

using namespace CognitiveServicesLib;
using namespace Platform;
using namespace Windows::Data::Json;

FaceAttributes::FaceAttributes()
{
}

FaceAttributes ^ FaceAttributes::FromJson(JsonObject ^ jsonObject)
{
	FaceAttributes^ attr = nullptr;
	if (jsonObject != nullptr)
	{
		attr = ref new FaceAttributes();
		JsonObject^ jsonObj = nullptr;

		//jsonObj = jsonObject->GetNamedObject(JSON_PROPERTYNAME(Exposure), nullptr);
		//attr->Exposure = Exposure::FromJson( jsonObj );

	}
	return attr;
}