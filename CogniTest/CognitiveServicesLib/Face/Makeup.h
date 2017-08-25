#pragma once
namespace CognitiveServicesLib
{
	/// <summary>
	/// Face Makeup class contains Makeup information
	/// </summary>
	public ref class Makeup sealed
		: Windows::Foundation::IStringable
	{
	public:
		Makeup();
		Platform::String^ ToString() override;

	internal:
		static Makeup^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);
		void toStringStream(std::wostringstream& out);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(Makeup, bool, EyeMakeup, L"eyeMakeup")
		DEFINE_PROPERTY_VARIABLES(Makeup, bool, LipMakeup, L"lipMakeup")

	public:
		/// <summary>
		/// Indicating whether eye has Makeup or not
		/// </summary>
		property bool EyeMakeup { bool get(); void set(bool value); }

		/// <summary>
		/// Indicating whether lip has Makeup or not
		/// </summary>
		property bool LipMakeup { bool get(); void set(bool value); }
#pragma endregion
	};
}

