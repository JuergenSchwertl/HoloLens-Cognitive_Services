#pragma once

#ifndef ENUMS_DEFINED
#define ENUMS_DEFINED

namespace CognitiveServicesLib
{
	public enum class AzureRegions : int
	{
		WestUS=1,
		EastUS2,
		WestCentralUS,
		WestEurope,
		SoutheastAsia
	};

	public enum class FaceAttributes : int
	{
		Age=1, 
		Gender, 
		HeadPose, 
		Smile, 
		FacialHair, 
		Glasses, 
		Emotion, 
		Hair, 
		Makeup, 
		Occlusion, 
		Accessories, 
		Blur, 
		Exposure,
		Noise
	};
}

#endif
