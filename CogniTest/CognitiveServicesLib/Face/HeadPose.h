#pragma once
namespace CognitiveServicesLib
{

	public ref class HeadPose sealed
	{
	public:
		HeadPose();

	internal:
		static HeadPose^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(HeadPose, double, Roll, L"roll")
		DEFINE_PROPERTY_VARIABLES(HeadPose, double, Yaw, L"yaw")
		DEFINE_PROPERTY_VARIABLES(HeadPose, double, Pitch, L"pitch")

	public:

		/// <summary>
		/// Gets or sets the roll.
		/// </summary>
		/// <value>
		/// The roll of the face pose.
		/// </value>
		property double Roll { double get(); void set(double value); }

		/// <summary>
		/// Gets or sets the yaw.
		/// </summary>
		/// <value>
		/// The yaw of the face pose.
		/// </value>
		property double Yaw { double get(); void set(double value); }

		/// <summary>
		/// Gets or sets the pitch.
		/// </summary>
		/// <value>
		/// The pitch of the face pose.
		/// </value>
		property double Pitch { double get(); void set(double value); }

#pragma endregion

	};
}

