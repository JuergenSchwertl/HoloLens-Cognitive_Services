#pragma once
namespace CognitiveServicesLib
{
	public enum class FaceTestEnum : int
	{
		Value1 = 1

	};

	static class FaceTestEnumHelper
	{
		static EnumKeyJsonName<CognitiveServicesLib::FaceTestEnum> ckvJsonNames[];

	public:
		static CognitiveServicesLib::FaceTestEnum parse(Platform::String^ strValue);
		static Platform::String^ toString(CognitiveServicesLib::FaceTestEnum enumValue);
	};


	public ref class FaceTest sealed
	{
	public:
		FaceTest();

	internal:
		static FaceTest^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(FaceTest, CognitiveServicesLib::FaceTestEnum, FaceTestEnumName, L"faceTestEnumName")
		DEFINE_PROPERTY_VARIABLES(FaceTest, double, Value, L"value")

	public:

		/// <summary>Indicating exposure level of face image</summary>
		property CognitiveServicesLib::FaceTestEnum FaceTestEnumName { CognitiveServicesLib::FaceTestEnum get(); void set(CognitiveServicesLib::FaceTestEnum value); }

		property double Value { double get(); void set(double value); }


#pragma endregion

	};
}

