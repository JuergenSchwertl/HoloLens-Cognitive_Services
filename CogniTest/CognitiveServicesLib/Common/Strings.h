#pragma once

#ifndef COMMON_STRINGS_DEFINED
#define COMMON_STRINGS_DEFINED

namespace CognitiveServicesLib
{
	namespace Common
	{
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
			public:
				static PCWSTR GetRegionName(AzureRegions);
		};

		class EndpointHelper
		{
			public:
				static const wchar_t FaceDetect[];
				static const wchar_t FaceFindSimilar[];
				static const wchar_t FaceGroup[];
				static const wchar_t FaceIdentify[];
				static const wchar_t FaceVerify[];

				static Platform::String^ BuildEndpointString(PCWSTR, PCWSTR, PCWSTR);
				static Windows::Foundation::Uri^ BuildEndpointUri(PCWSTR, PCWSTR, PCWSTR);

			public:
				static Windows::Foundation::Uri^ BuildEndpointUri(PCWSTR, AzureRegions, PCWSTR);
		};


	}
}

#endif