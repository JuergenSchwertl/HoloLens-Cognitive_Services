#pragma once

namespace CognitiveServicesLib
{
	public ref class FaceAttributes sealed
	{
	public:
		FaceAttributes();
	internal:
		static FaceAttributes^ FromJson(Windows::Data::Json::JsonObject ^ jsonObject);


#pragma region Properties
	private:

	public:

		/// <summary>
		/// Gets or sets the age value.
		/// </summary>
		/// <value>
		/// The age value.
		/// </value>
		property double Age { double get(); void set(double value); }

		/// <summary>
		/// Gets or sets the gender.
		/// </summary>
		/// <value>
		/// The gender.
		/// </value>
		property Platform::String^ Gender { Platform::String^ get(); void set(Platform::String^ value); }

		/// <summary>
		/// Gets or sets the head pose.
		/// </summary>
		/// <value>
		/// The head pose.
		/// </value>
		property CognitiveServicesLib::HeadPose^ HeadPose { CognitiveServicesLib::HeadPose^ get(); void set(CognitiveServicesLib::HeadPose^ value); }

		/// <summary>
		/// Gets or sets the smile value. Represents the confidence of face is smiling.
		/// </summary>
		/// <value>
		/// The smile value.
		/// </value>
		property double Smile { double get(); void set(double value); }

		/// <summary>
		/// Gets or sets the facial hair.
		/// </summary>
		/// <value>
		/// The facial hair.
		/// </value>
		property CognitiveServicesLib::FacialHair^ FacialHair { CognitiveServicesLib::FacialHair^ get(); void set(CognitiveServicesLib::FacialHair^ value); }

		/// <summary>
		/// Gets or sets the emotion.
		/// </summary>
		/// <value>
		/// The emotion.
		/// </value>
		property CognitiveServicesLib::EmotionScores^ Emotion {CognitiveServicesLib::EmotionScores^  get(); void set(CognitiveServicesLib::EmotionScores^ value); }

		/// <summary>
		/// Gets or sets the glasses type.
		/// </summary>
		/// <value>
		/// The glasses type.
		/// </value>
		property CognitiveServicesLib::Glasses Glasses { CognitiveServicesLib::Glasses get(); void set(CognitiveServicesLib::Glasses value); }

		/// <summary>
		/// Gets or sets the blur
		/// </summary>
		/// <value>
		/// The blur type
		/// </value>
		property CognitiveServicesLib::Blur^ Blur { CognitiveServicesLib::Blur^ get(); void set(CognitiveServicesLib::Blur^ value); }

		/// <summary>
		/// Gets or sets the exposure
		/// </summary>
		/// <value>
		/// The exposure type
		/// </value>
		property CognitiveServicesLib::Exposure^ Exposure { CognitiveServicesLib::Exposure^ get(); void set(CognitiveServicesLib::Exposure^ value); }

		/// <summary>
		/// Gets or sets the noise
		/// </summary>
		/// <value>
		/// The noise type
		/// </value>
		property CognitiveServicesLib::Noise^ Noise { CognitiveServicesLib::Noise^ get(); void set(CognitiveServicesLib::Noise^ value); }

		/// <summary>
		/// Gets or sets the makeup
		/// </summary>
		/// <value>
		/// The makeup type
		/// </value>
		property CognitiveServicesLib::Makeup^ Makeup { CognitiveServicesLib::Makeup^ get(); void set(CognitiveServicesLib::Makeup^ value); }

		/// <summary>
		/// Gets or sets the accessories
		/// </summary>
		/// <value>
		/// The accessory type array
		/// </value>
		property Windows::Foundation::Collections::IVector< CognitiveServicesLib::Accessory^>^ Accessories
		{
			Windows::Foundation::Collections::IVector< CognitiveServicesLib::Accessory^>^ get();
			void set(Windows::Foundation::Collections::IVector< CognitiveServicesLib::Accessory^>^ value);
		}

		/// <summary>
		/// Gets or sets the occlusion
		/// </summary>
		/// <value>
		/// The occlusion type
		/// </value>
		//property CognitiveServicesLib::Occlusion^ Occlusion
		//{
		//		property CognitiveServicesLib::Occlusion^ get(); 
		//		void set(property CognitiveServicesLib::Occlusion^ value);
		//}

		/// <summary>
		/// Gets or sets the hair
		/// </summary>
		/// <value>
		/// The hair type
		/// </value>
		//property CognitiveServicesLib::Hair^ Hair
		//{
		//		CognitiveServicesLib::Hair^ get();
		//		void set(CognitiveServicesLib::Hair^ value);
		//}

#pragma endregion

	};
}