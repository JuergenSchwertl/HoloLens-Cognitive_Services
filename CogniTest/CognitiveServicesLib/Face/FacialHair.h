#pragma once
namespace CognitiveServicesLib
{ 
	/// <summary>
	/// Represents length of moustache, beard and sideburn
	/// </summary>
	public ref class FacialHair sealed
	{

	public:
		FacialHair();

	internal:
		static FacialHair^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(FacialHair, double, Moustache, L"moustache")
		DEFINE_PROPERTY_VARIABLES(FacialHair, double, Beard, L"beard")
		DEFINE_PROPERTY_VARIABLES(FacialHair, double, Sideburns, L"value")

	public:

		/// <summary>
		/// Gets or sets the moustache value. Represents the length of moustache.
		/// </summary>
		/// <value>
		/// The moustache value.
		/// </value>
		property double Moustache { double get(); void set(double value); }

		/// <summary>
		/// Gets or sets the beard value. Represents the length of beard.
		/// </summary>
		/// <value>
		/// The beard value.
		/// </value>
		property double Beard { double get(); void set(double value); }

		/// <summary>
		/// Gets or sets the sideburns value. Represents the length of sideburns.
		/// </summary>
		/// <value>
		/// The sideburns value.
		/// </value>
		property double Sideburns { double get(); void set(double value); }
#pragma endregion

	};
}


