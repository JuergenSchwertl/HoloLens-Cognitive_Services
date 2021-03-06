#pragma once

namespace CognitiveServicesLib
{
	public enum class ExposureLevel : int 
	{
		/// <summary>
		/// Indicating face image is in under exposure
		/// </summary>
		UnderExposure = 1,

		/// <summary>
		/// Indicating face image is in good exposure
		/// </summary>
		GoodExposure,

		/// <summary>
		/// Indicating face image is in over exposure
		/// </summary>
		OverExposure
	};

	class ExposureLevelHelper
	{
	public:
		static EnumKeyJsonName<CognitiveServicesLib::ExposureLevel> ckvJsonNames[3];
	};


	public ref class Exposure sealed : Windows::Foundation::IStringable
	{
	public:
		Exposure();
		Platform::String^ ToString() override;

	internal:
		static Exposure^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);
		void toStringStream(std::wostringstream& out);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES( Exposure, CognitiveServicesLib::ExposureLevel, ExposureLevel, L"exposureLevel")
		DEFINE_PROPERTY_VARIABLES( Exposure, double, Value, L"value")

	public:

		/// <summary>Indicating exposure level of face image</summary>
		property CognitiveServicesLib::ExposureLevel ExposureLevel { CognitiveServicesLib::ExposureLevel get(); void set(CognitiveServicesLib::ExposureLevel value); }

		/// <summary>
		/// Exposure value is in range [0, 1]. Larger value means the face image is more brighter.
		/// [0, 0.25) is under exposure.
		/// [0.25, 0.75) is good exposure.
		/// [0.75, 1] is over exposure.
		/// </summary>
		property double Value { double get(); void set(double value); }


#pragma endregion

	};
}

