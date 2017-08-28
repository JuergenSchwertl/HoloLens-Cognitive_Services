#pragma once

namespace CognitiveServicesLib
{
	public enum class AccessoryType : int
	{
		/// <summary>
		/// Headwear
		/// </summary>
		Headwear = 1,

		/// <summary>
		/// Glasses
		/// </summary>
		Glasses,

		/// <summary>
		/// Mask
		/// </summary>
		Mask
	};

	class AccessoryTypeHelper : EnumHelper<AccessoryType, AccessoryTypeHelper>
	{
	public:
		static EnumKeyJsonName<CognitiveServicesLib::AccessoryType> ckvJsonNames[3];
	};


	/// <summary>
	/// Face accessory class contains accessory information
	/// </summary>
	public ref class Accessory sealed : Windows::Foundation::IStringable
	{


	public:
		Accessory();
		Platform::String^ ToString() override;

	internal:
		static Accessory^ FromJson(Windows::Data::Json::JsonObject ^ jsonObject);
		static Windows::Foundation::Collections::IVector<CognitiveServicesLib::Accessory^>^ FromJsonArray(Windows::Data::Json::JsonArray ^ jsonArray);
		void toStringStream(std::wostringstream& out);

	private:
		DEFINE_PROPERTY_VARIABLES(Accessory, CognitiveServicesLib::AccessoryType, Type, L"type")
		DEFINE_PROPERTY_VARIABLES(Accessory, double, Confidence, L"confidence")

	public:
		/// <summary>
		/// Indicating the accessory type
		/// </summary>
		property CognitiveServicesLib::AccessoryType Type { CognitiveServicesLib::AccessoryType get(); void set(CognitiveServicesLib::AccessoryType value); }

		/// <summary>
		/// Indicating the confidence for accessory type
		/// </summary>
		property double Confidence { double get(); void set( double value);
		}

	};

}
