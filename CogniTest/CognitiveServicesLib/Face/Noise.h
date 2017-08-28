#pragma once
namespace CognitiveServicesLib
{
	public enum class NoiseLevel : int
	{
		/// <summary>
		/// Low noise level indicating a clear face image
		/// </summary>
		Low = 1,

		/// <summary>
		/// Medium noise level indicating a slightly noisy face image
		/// </summary>
		Medium,

		/// <summary>
		/// High noise level indicating a extremely noisy face image
		/// </summary>
		High
	};

	class NoiseLevelHelper
	{
	public:
		static EnumKeyJsonName<CognitiveServicesLib::NoiseLevel> ckvJsonNames[3];
	};


	public ref class Noise sealed
		: Windows::Foundation::IStringable
	{
	public:
		Noise();
		Platform::String^ ToString() override;

	internal:
		static Noise^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);
		void toStringStream(std::wostringstream& out);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(Noise, CognitiveServicesLib::NoiseLevel, NoiseLevel, L"noiseLevel")
		DEFINE_PROPERTY_VARIABLES(Noise, double, Value, L"value")

	public:

		/// <summary>
		/// Indicating noise level of face image
		/// </summary>
		property CognitiveServicesLib::NoiseLevel NoiseLevel { CognitiveServicesLib::NoiseLevel get(); void set(CognitiveServicesLib::NoiseLevel value); }


		/// <summary>
		/// Noise value is in range [0, 1]. Larger value means the face image is more noisy.
		/// [0, 0.3) is low noise level.
		/// [0.3, 0.7) is medium noise level.
		/// [0.7, 1] is high noise level. 
		/// </summary>
		property double Value { double get(); void set(double value); }
#pragma endregion

	};
}

