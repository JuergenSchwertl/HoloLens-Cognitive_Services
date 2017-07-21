
#include "pch.h"
#include <string.h>

#include "Enums.h"
#include "Strings.h"

using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;


// Common Header strings
const wchar_t HttpHeaderName::ContentType[] = L"Content-Type";
const wchar_t HttpHeaderName::OcpApimSubscriptionKey[] = L"Ocp-Apim-Subscription-Key";

// Common Parameter strings
const wchar_t Parameters::FaceId[] = L"returnFaceId";
const wchar_t Parameters::FaceLandmarks[] = L"returnFaceLandmarks";
const wchar_t Parameters::FaceAttributes[] = L"returnFaceAttributes";

//
// Common Http Content Types
//

/// <summary>Http Content-Type: application/octet-stream</summary>
const wchar_t ContentTypes::ApplicationOctetStream[] = L"application/octet-stream";

/// <summary>Http Content-Type: application/json</summary>
const wchar_t ContentTypes::ApplicationJson[] = L"application/json";

/// <summary>Http Content-Type: multipart/form-data</summary>
const wchar_t ContentTypes::MultipartFormdata[] = L"multipart/form-data";

/// <summary>Http Content-Type: image/jpg</summary>
const wchar_t ContentTypes::ImageJpg[] = L"image/jpg";

/// <summary>Http Content-Type: image/png</summary>
const wchar_t ContentTypes::ImagePng[] = L"image/png";

/// <summary>Http Content-Type: image/bmp</summary>
const wchar_t ContentTypes::ImageBmp[] = L"image/bmp";

/// <summary>Http Content-Type: image/gif</summary>
const wchar_t ContentTypes::ImageGif[] = L"image/gif";

/// <summary>File-extension jpg</summary>
const wchar_t ContentTypes::ExtensionJpg[] = L"jpg";

/// <summary>File-extension png</summary>
const wchar_t ContentTypes::ExtensionPng[] = L"png";

/// <summary>File-extension bmp</summary>
const wchar_t ContentTypes::ExtensionBmp[] = L"bmp";

/// <summary>File-extension gif</summary>
const wchar_t ContentTypes::ExtensionGif[] = L"gif";

Platform::String^ ContentTypes::GetFromFileName(Platform::String^ _Filename)
{
	std::wstring filename = std::wstring(_Filename->Data());
	size_t lastpoint = filename.find_last_of('.');
	size_t extensionlength = filename.length() - lastpoint - 1;
	std::wstring extension = filename.substr(lastpoint, extensionlength);
	PCWSTR imagetype = nullptr;

	if (extension.compare(ExtensionJpg) == 0)
	{
		imagetype = ImageJpg;
	} 
	else if (extension.compare(ExtensionPng) == 0)
	{
		imagetype = ImagePng;
	}
	else if (extension.compare(ExtensionBmp) == 0)
	{
		imagetype = ImageBmp;
	}
	else if (extension.compare(ExtensionGif) == 0)
	{
		imagetype = ImageGif;
	}

	return ref new String(imagetype);
}
//
// Common Api endpoint regions
//

/// <summary>Azure region West US: westus.api.cognitive.microsoft.com</summary>
const wchar_t AzureRegionHelper::WestUS[] = L"westus";

/// <summary>Azure region East US 2: eastus2.api.cognitive.microsoft.com</summary>
const wchar_t AzureRegionHelper::EastUS2[] = L"eastus2";

/// <summary>Azure region West Central US: westcentralus.api.cognitive.microsoft.com</summary>
const wchar_t AzureRegionHelper::WestCentralUS[] = L"westcentralus";

/// <summary>Azure region West Europe: westeurope.api.cognitive.microsoft.com</summary>
const wchar_t AzureRegionHelper::WestEurope[] = L"westeurope";

/// <summary>Azure region Southeast Asia: southeastasia.api.cognitive.microsoft.com</summary>
const wchar_t AzureRegionHelper::SoutheastAsia[] = L"southeastasia";

PCWSTR AzureRegionHelper::GetRegionName(AzureRegions _Region)
{
	switch (_Region)
	{
	case AzureRegions::WestUS:
		return AzureRegionHelper::WestUS;
		break;
	case AzureRegions::EastUS2:
		return AzureRegionHelper::EastUS2;
		break;
	case AzureRegions::WestCentralUS:
		return AzureRegionHelper::WestCentralUS;
		break;
	case AzureRegions::WestEurope:
		return AzureRegionHelper::WestEurope;
		break;
	case AzureRegions::SoutheastAsia:
		return AzureRegionHelper::SoutheastAsia;
		break;
	default:
		return nullptr;
		break;
	}
}

//
// Face API endpoints
//

/// <summary>Face-Detect Endpoint:POST https://[location].api.cognitive.microsoft.com/face/v1.0/detect[?returnFaceId][&returnFaceLandmarks][&returnFaceAttributes]</summary>
const wchar_t EndpointHelper::FaceDetect[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/detect?%s";

/// <summary>Face-Find Similar Endpoint:POST https://[location].api.cognitive.microsoft.com/face/v1.0/findsimilars</summary>
const wchar_t EndpointHelper::FaceFindSimilar[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/findsimilars";

/// <summary>Face-Group Endpoint: https://[location].api.cognitive.microsoft.com/face/v1.0/group</summary>
const wchar_t EndpointHelper::FaceGroup[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/group";

/// <summary>Face-Identify Endpoint: https://[location].api.cognitive.microsoft.com/face/v1.0/identify</summary>
const wchar_t EndpointHelper::FaceIdentify[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/identify";

/// <summary>Face-Verify Endpoint: https://[location].api.cognitive.microsoft.com/face/v1.0/verify</summary>
const wchar_t EndpointHelper::FaceVerify[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/verify";

/// <summary>Helper function to build endpoint string</summary>
/// <param name="_BaseUri">baseUri API endpoint format string</param>
///<param name="_Region">Azure region</param>
///<param name="_Parameter">additional URL parameter </param>
///<returns>Formatted URI string as <see cref="Platform::String^" /></returns>
String^ EndpointHelper::BuildEndpointString(PCWSTR _BaseUri, PCWSTR _Region, PCWSTR _Parameter)
{
	std::wstring strEndpoint(1024,'0');
	swprintf_s((PWSTR) strEndpoint.c_str(), strEndpoint.size(), _BaseUri, _Region, _Parameter);
	return ref new Platform::String(strEndpoint.c_str());
}

/// <summary>Helper function to build endpoint Uri</summary>
/// <param name="_BaseUri">baseUri API endpoint format string</param>
///<param name="_Region">Azure region</param>
///<param name="_Parameter">additional URL parameter </param>
///<returns>Formatted <see cref="Windows::Foundation::Uri^" /></returns>
Uri^ EndpointHelper::BuildEndpointUri(PCWSTR _BaseUri, PCWSTR _Region, PCWSTR _Parameter)
{
	return ref new Uri( BuildEndpointString(_BaseUri, _Region, _Parameter) );
}

/// <summary>Helper function to build endpoint Uri</summary>
/// <param name="_BaseUri">baseUri API endpoint format string</param>
///<param name="_Region">Azure region</param>
///<param name="_Parameter">additional URL parameter </param>
///<returns>Formatted <see cref="Windows::Foundation::Uri^" /></returns>
Uri^ EndpointHelper::BuildEndpointUri(PCWSTR _BaseUri, AzureRegions _Region, PCWSTR _Parameter)
{
	return BuildEndpointUri(_BaseUri, AzureRegionHelper::GetRegionName(_Region), _Parameter);
}
