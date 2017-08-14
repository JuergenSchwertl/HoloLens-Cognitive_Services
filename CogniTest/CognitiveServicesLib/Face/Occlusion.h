#pragma once
namespace CognitiveServicesLib
{

	public ref class Occlusion sealed
	{
	public:
		Occlusion();

	internal:
		static Occlusion^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(Occlusion, bool, ForeheadOccluded, L"foreheadOccluded")
		DEFINE_PROPERTY_VARIABLES(Occlusion, bool, EyeOccluded, L"eyeOccluded")
		DEFINE_PROPERTY_VARIABLES(Occlusion, bool, MouthOccluded, L"mouthOccluded")

	public:

		/// <summary>
		/// Indicating whether forehead is occluded or not
		/// </summary>
		property bool ForeheadOccluded { bool get(); void set(bool value); }

		/// <summary>
		/// Indicating whether eye is occluded or not
		/// </summary>
		property bool EyeOccluded { bool get(); void set(bool value); }

		/// <summary>
		/// Indicating whether mouth is occluded or not
		/// </summary>
		property bool MouthOccluded { bool get(); void set(bool value); }
#pragma endregion

	};
}

