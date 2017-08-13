#include "pch.h"
#include "Emotion.h"

using namespace Platform;
using namespace CognitiveServicesLib;

IMPLEMENT_PROPERTY(EmotionScores, double, Anger		, L"anger")
IMPLEMENT_PROPERTY(EmotionScores, double, Contempt	, L"contempt")
IMPLEMENT_PROPERTY(EmotionScores, double, Disgust	, L"disgust")
IMPLEMENT_PROPERTY(EmotionScores, double, Fear		, L"Fear")
IMPLEMENT_PROPERTY(EmotionScores, double, Happiness	, L"happiness")
IMPLEMENT_PROPERTY(EmotionScores, double, Neutral	, L"neutral")
IMPLEMENT_PROPERTY(EmotionScores, double, Sadness	, L"sadness")
IMPLEMENT_PROPERTY(EmotionScores, double, Surprise	, L"surprise")

EmotionScores::EmotionScores()
{
}

EmotionScores ^ EmotionScores::FromJson(Windows::Data::Json::JsonObject ^ jsonObject)
{
	EmotionScores^ obj = nullptr;
	if (jsonObject != nullptr)
	{
		obj = ref new EmotionScores();
		obj->Anger = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Anger), 0.0);
		obj->Contempt = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Contempt), 0.0);
		obj->Disgust = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Disgust), 0.0);
		obj->Fear = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Fear), 0.0);
		obj->Happiness = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Happiness), 0.0);
		obj->Neutral = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Neutral), 0.0);
		obj->Sadness = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Sadness), 0.0);
		obj->Surprise = jsonObject->GetNamedNumber(JSON_PROPERTYNAME(Surprise), 0.0);
	}
	return obj;
}
