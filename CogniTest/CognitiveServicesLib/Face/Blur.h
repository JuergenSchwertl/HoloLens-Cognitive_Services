#pragma once
namespace CognitiveServicesLib
{
	/// <summary>
	/// Definition of blur level
	/// </summary>
	public enum class BlurLevel
	{
		/// <summary>
		/// Low blur level indicating a clear face image
		/// </summary>
		Low = 1,

		/// <summary>
		/// Medium blur level indicating a slightly blurry face image
		/// </summary>
		Medium,

		/// <summary>
		/// High blur level indicating a extremely blurry face image
		/// </summary>
		High
	};

	static class BlurLevelHelper
	{
		static EnumKeyJsonName<CognitiveServicesLib::BlurLevel> ckvJsonNames[];

	public:
		static CognitiveServicesLib::BlurLevel parse(Platform::String^ strValue);
		static Platform::String^ toString(CognitiveServicesLib::BlurLevel enumValue);
	};


	public ref class Blur sealed
	{
	public:
		Blur();
	internal:
		static Blur^ FromJson(Windows::Data::Json::JsonObject ^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(Accessory, CognitiveServicesLib::BlurLevel, BlurLevel, L"blurLevel")
		DEFINE_PROPERTY_VARIABLES(Accessory, double, Value, L"value")

	public:
		/// <summary>
		/// Indicating the accessory type
		/// </summary>
		property CognitiveServicesLib::BlurLevel BlurLevel { CognitiveServicesLib::BlurLevel get(); void set(CognitiveServicesLib::BlurLevel value); }

		/// <summary>
		/// Indicating the confidence for accessory type
		/// </summary>
		property double Value { double get(); void set(double value);
		}
#pragma endregion

	};


}