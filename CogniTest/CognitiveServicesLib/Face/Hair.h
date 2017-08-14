#pragma once
namespace CognitiveServicesLib
{
	/// <summary>
	/// Hair color type
	/// </summary>
	public enum class HairColorType : int
	{
		/// <summary>
		/// unknown
		/// </summary>
		Unknown = 1,

		/// <summary>
		/// White
		/// </summary>
		White,

		/// <summary>
		/// Gray
		/// </summary>
		Gray,

		/// <summary>
		/// Blond
		/// </summary>
		Blond,

		/// <summary>
		/// Brown
		/// </summary>
		Brown,

		/// <summary>
		/// Red
		/// </summary>
		Red,

		/// <summary>
		/// Black
		/// </summary>
		Black,

		/// <summary>
		/// Other
		/// </summary>
		Other

	};

	class HairColorTypeHelper
	{
		static EnumKeyJsonName<CognitiveServicesLib::HairColorType> ckvJsonNames[];

	public:
		static CognitiveServicesLib::HairColorType parse(Platform::String^ strValue);
		static Platform::String^ toString(CognitiveServicesLib::HairColorType enumValue);
	};

	/// <summary>
	/// Face HairColor class contains hair color information
	/// </summary>
	public ref class HairColor sealed
	{
	public:
		HairColor();

	internal:
		static HairColor^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);
		static Windows::Foundation::Collections::IVector<CognitiveServicesLib::HairColor^>^ FromJsonArray(Windows::Data::Json::JsonArray ^ jsonArray);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(HairColor, CognitiveServicesLib::HairColorType, HairColorTypeName, L"HairColorTypeName")
		DEFINE_PROPERTY_VARIABLES(HairColor, double, Confidence, L"confidence")

	public:

		/// <summary>
		/// Indicating the hair color type
		/// </summary>
		property CognitiveServicesLib::HairColorType HairColorTypeName 
		{ 
			CognitiveServicesLib::HairColorType get(); 
			void set(CognitiveServicesLib::HairColorType value); 
		}

		/// <summary>
		/// Indicating the confidence for hair color type
		/// </summary>
		property double Confidence { double get(); void set(double value); }


#pragma endregion

	};

	/// <summary>
	/// Face Hair class contains hair information
	/// </summary>
	public ref class Hair sealed
	{
	public:
		Hair();

	internal:
		static Hair^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(Hair, double, Bald, L"bald")
		DEFINE_PROPERTY_VARIABLES(Hair, bool, Invisible, L"bald")
		DEFINE_PROPERTY_VARIABLES(Hair, Windows::Foundation::Collections::IVector< CognitiveServicesLib::HairColor^>^, HairColor, L"hairColor")

	public:
		/// <summary>
		/// Indicating the confidence of a bald head
		/// </summary>
		property double Bald { double get(); void set(double value); }

		/// <summary>
		/// Indicating whether hair is occluded or not
		/// </summary>
		property bool Invisible { bool get(); void set(bool value); }

		/// <summary>
		/// Indicating all possible hair colors with confidences
		/// </summary>
		property Windows::Foundation::Collections::IVector< CognitiveServicesLib::HairColor^>^ HairColor
		{
			Windows::Foundation::Collections::IVector< CognitiveServicesLib::HairColor^>^ get();
			void set(Windows::Foundation::Collections::IVector< CognitiveServicesLib::HairColor^>^ value);
		}
#pragma endregion
	};
}

