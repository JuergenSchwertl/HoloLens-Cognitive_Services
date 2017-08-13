#pragma once
namespace CognitiveServicesLib
{
	public enum class Glasses : int
	{
		/// <summary>
		/// Indicates not wearing any glasses
		/// </summary>
		NoGlasses=1,

		/// <summary>
		/// Indicates wearing sunglasses
		/// </summary>
		Sunglasses,

		/// <summary>
		/// Indicates wearing reading glasses
		/// </summary>
		ReadingGlasses,

		/// <summary>
		/// Indicates wearing swimming goggles
		/// </summary>
		SwimmingGoggles
	};

	static class GlassesHelper
	{
		static EnumKeyJsonName<CognitiveServicesLib::Glasses> ckvJsonNames[];

	public:
		static CognitiveServicesLib::Glasses parse(Platform::String^ strValue);
		static Platform::String^ toString(CognitiveServicesLib::Glasses enumValue);
	};


}

