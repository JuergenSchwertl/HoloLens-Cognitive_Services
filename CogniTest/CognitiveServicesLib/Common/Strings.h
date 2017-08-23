#pragma once

#ifndef COMMON_STRINGS_DEFINED
#define COMMON_STRINGS_DEFINED

#define _ENDL L'\r'
#define _ENDS L'\0'
#define _COLON L','
#define _OBRACKET L'('
#define _CBRACKET L')'

namespace CognitiveServicesLib
{
	namespace Common
	{
	
		class Globals
		{
		public:
			static const wchar_t cstrEmptyString[];
			static const wchar_t cstrTrue[];
			static const wchar_t cstrFalse[];
			static const wchar_t cstrNull[];

			static PCWSTR Bool_ToString(bool param);
		};

#define CSTR_NULL CognitiveServicesLib::Common::Globals::cstrNull

		class HttpHeaderName
		{
			public:
				static const wchar_t ContentType[];
				static const wchar_t OcpApimSubscriptionKey[];
		};

		class Parameters
		{
			public:
				static const wchar_t FaceId[];
				static const wchar_t FaceLandmarks[];
				static const wchar_t FaceAttributes[];

		};

		class ContentTypes
		{
			public:
				static const wchar_t ApplicationOctetStream[];
				static const wchar_t ApplicationJson[];
				static const wchar_t MultipartFormdata[];
				static const wchar_t ImageJpg[];
				static const wchar_t ImagePng[];
				static const wchar_t ImageBmp[];
				static const wchar_t ImageGif[];

				static const wchar_t ExtensionJpg[];
				static const wchar_t ExtensionPng[];
				static const wchar_t ExtensionBmp[];
				static const wchar_t ExtensionGif[];

				static Platform::String^ GetFromFileName(Platform::String^ _Filename);

		};

	    class AzureRegionHelper
		{
			private:
				static const wchar_t WestUS[];
				static const wchar_t EastUS2[];
				static const wchar_t WestCentralUS[];
				static const wchar_t WestEurope[];
				static const wchar_t SoutheastAsia[];

				static const wchar_t *lstRegions[];
			public:
				static PCWSTR GetRegionName(AzureRegions);
		};

		class FaceAttributeOptionsHelper
		{
		private:
			static const wchar_t cstrAge[];
			static const wchar_t cstrGender[];
			static const wchar_t cstrHeadPose[];
			static const wchar_t cstrSmile[];
			static const wchar_t cstrFacialHair[];
			static const wchar_t cstrGlasses[];
			static const wchar_t cstrEmotion[];
			static const wchar_t cstrHair[];
			static const wchar_t cstrMakeup[];
			static const wchar_t cstrOcclusion[];
			static const wchar_t cstrAccessories[];
			static const wchar_t cstrBlur[];
			static const wchar_t cstrExposure[];
			static const wchar_t cstrNoise[];

			static const wchar_t *lstAttributes[];
		public:
			static PCWSTR GetFaceAttribute(FaceAttributeOptions _Attribute);
		};

		class EndpointHelper
		{
			public:
				static const wchar_t FaceDetect[];
				static const wchar_t FaceFindSimilar[];
				static const wchar_t FaceGroup[];
				static const wchar_t FaceIdentify[];
				static const wchar_t FaceVerify[];

				static Platform::String^ BuildEndpointString(PCWSTR, PCWSTR, Platform::String^);
				static Windows::Foundation::Uri^ BuildEndpointUri(PCWSTR, PCWSTR, Platform::String^);

			public:
				static Windows::Foundation::Uri^ BuildEndpointUri(PCWSTR, AzureRegions, Platform::String^ Parameters);
				static Platform::String^ BuildParameterList(
					bool ReturnFaceId,
					bool ReturnFaceLandmarks,
					Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes);
		};


	}
}

#endif