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

	class GlassesHelper
	{
	public:
		static EnumKeyJsonName<CognitiveServicesLib::Glasses> ckvJsonNames[4];
		void Test();
	};

}

