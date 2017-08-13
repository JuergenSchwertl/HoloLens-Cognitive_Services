#pragma once
namespace CognitiveServicesLib
{
	public ref class EmotionScores sealed
	{
	public:
		EmotionScores();

	internal:
		static EmotionScores^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Anger, L"anger")
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Contempt, L"contempt")
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Disgust, L"disgust")
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Fear, L"Fear")
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Happiness, L"happiness")
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Neutral, L"neutral")
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Sadness, L"sadness")
		DEFINE_PROPERTY_VARIABLES(EmotionScores, double, Surprise, L"surprise")

	public:
		/// <summary>
		/// 
		/// </summary>
		property double Anger { double get(); void set(double value); }

		/// <summary>
		/// 
		/// </summary>
		property double Contempt { double get(); void set(double value); }

		/// <summary>
		/// 
		/// </summary>
		property double Disgust { double get(); void set(double value); }

		/// <summary>
		/// 
		/// </summary>
		property double Fear { double get(); void set(double value); }

		/// <summary>
		/// 
		/// </summary>
		property double Happiness { double get(); void set(double value); }

		/// <summary>
		/// 
		/// </summary>
		property double Neutral { double get(); void set(double value); }

		/// <summary>
		/// 
		/// </summary>
		property double Sadness { double get(); void set(double value); }

		/// <summary>
		/// 
		/// </summary>
		property double Surprise { double get(); void set(double value); }

#pragma endregion

	};
}

