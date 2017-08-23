#pragma once

namespace CognitiveServicesLib
{
	public ref class FeatureCoordinate sealed : Windows::Foundation::IStringable
	{
	public:
		FeatureCoordinate();
		Platform::String^ ToString() override;

	internal:
		static FeatureCoordinate^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);
		void toStringStream(std::wostringstream& out);

#pragma region Properties
	private:
		DEFINE_PROPERTY_VARIABLES(FeatureCoordinate, double, X, L"x")
		DEFINE_PROPERTY_VARIABLES(FeatureCoordinate, double, Y, L"y")

	public:

		///<summary>Gets or sets the x in pixel</summary>
		///<value>The x of the feature coordinate</value>
		property double X { double get(); void set(double value); }

		///<summary>Gets or sets the y in pixel</summary>
		///<value>The y of the feature coordinate</value>
		property double Y { double get(); void set(double value); }

#pragma endregion

	};
}

