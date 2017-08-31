
#include "pch.h"
#include <string.h>
#include <sstream>

#include "Enums.h"
#include "Strings.h"

using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;

const wchar_t Globals::cstrEmptyString[] = L"";
const wchar_t Globals::cstrTrue[] = L"true";
const wchar_t Globals::cstrFalse[] = L"false";
const wchar_t Globals::cstrNull[] = L"null";

PCWSTR Globals::Bool_ToString(bool param)
{
	return param ? cstrTrue : cstrFalse;
}
// Common Header strings
const wchar_t HttpHeaderName::ContentType[] = L"Content-Type";
const wchar_t HttpHeaderName::ContentLength[] = L"Content-Length";
const wchar_t HttpHeaderName::OcpApimSubscriptionKey[] = L"Ocp-Apim-Subscription-Key";
const wchar_t HttpHeaderName::X_Microsoft_OutputFormat[] = L"X-Microsoft-OutputFormat";
const wchar_t HttpHeaderName::X_Search_AppId[] = L"X-Search-AppId";
const wchar_t HttpHeaderName::X_Search_ClientId[] = L"X-Search-ClientId";
const wchar_t HttpHeaderName::Authorization[] = L"Authorization";
const wchar_t HttpHeaderName::User_Agent[] = L"User-Agent";

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

/// <summary>Http Content-Type: application/ssml+xml</summary>
const wchar_t ContentTypes::ApplicationSsmlXml[] = L"application/ssml+xml";

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

const wchar_t * AzureRegionHelper::lstRegions[] = {
	Globals::cstrEmptyString,
	WestUS,
	EastUS2,
	WestCentralUS,
	WestEurope,
	SoutheastAsia
};

PCWSTR AzureRegionHelper::GetRegionName(AzureRegions _Region)
{
	int index = (int)_Region;
	if (index > 0 && index < (sizeof(lstRegions) / sizeof(PCWSTR)))
		return lstRegions[index];
	else
		return nullptr;
}

const wchar_t FaceAttributeOptionsHelper::cstrAge[] = L"age";
const wchar_t FaceAttributeOptionsHelper::cstrGender[] = L"gender";
const wchar_t FaceAttributeOptionsHelper::cstrHeadPose[] = L"headPose";
const wchar_t FaceAttributeOptionsHelper::cstrSmile[] = L"smile";
const wchar_t FaceAttributeOptionsHelper::cstrFacialHair[] = L"facialHair";
const wchar_t FaceAttributeOptionsHelper::cstrGlasses[] = L"glasses";
const wchar_t FaceAttributeOptionsHelper::cstrEmotion[] = L"emotion";
const wchar_t FaceAttributeOptionsHelper::cstrHair[] = L"hair";
const wchar_t FaceAttributeOptionsHelper::cstrMakeup[] = L"makeup";
const wchar_t FaceAttributeOptionsHelper::cstrOcclusion[] = L"occlusion";
const wchar_t FaceAttributeOptionsHelper::cstrAccessories[] = L"accessories";
const wchar_t FaceAttributeOptionsHelper::cstrBlur[] = L"blur";
const wchar_t FaceAttributeOptionsHelper::cstrExposure[] = L"exposure";
const wchar_t FaceAttributeOptionsHelper::cstrNoise[] = L"noise";

const wchar_t *FaceAttributeOptionsHelper::lstAttributes[] = { 
	Globals::cstrEmptyString,
	cstrAge, 
	cstrGender,
	cstrHeadPose,
	cstrSmile,
	cstrFacialHair,
	cstrGlasses,
	cstrEmotion,
	cstrHair,
	cstrMakeup,
	cstrOcclusion,
	cstrAccessories,
	cstrBlur,
	cstrExposure,
	cstrNoise
};

PCWSTR FaceAttributeOptionsHelper::GetFaceAttribute(FaceAttributeOptions _Attribute)
{
	int index = (int)_Attribute;
	if (index > 0 && index < (sizeof(lstAttributes) / sizeof(PCWSTR)) )
		return lstAttributes[index];
	else
		return nullptr;
}

//
// Face API endpoints
//

/// <summary>Face-Detect Endpoint:POST https://[location].api.cognitive.microsoft.com/face/v1.0/detect[?returnFaceId][&returnFaceLandmarks][&returnFaceAttributes]
/// <see cref="https://westus.dev.cognitive.microsoft.com/docs/services/563879b61984550e40cbbe8d/operations/563879b61984550f30395236" /></summary>
const wchar_t EndpointHelper::FaceDetect[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/detect?%s";

/// <summary>Face-Find Similar Endpoint:POST https://[location].api.cognitive.microsoft.com/face/v1.0/findsimilars
/// <see cref="https://westus.dev.cognitive.microsoft.com/docs/services/563879b61984550e40cbbe8d/operations/563879b61984550f30395237" /></summary>
const wchar_t EndpointHelper::FaceFindSimilar[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/findsimilars";

/// <summary>Face-Group Endpoint: https://[location].api.cognitive.microsoft.com/face/v1.0/group
/// <see cref="https://westus.dev.cognitive.microsoft.com/docs/services/563879b61984550e40cbbe8d/operations/563879b61984550f30395238" /></summary>
const wchar_t EndpointHelper::FaceGroup[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/group";

/// <summary>Face-Identify Endpoint: https://[location].api.cognitive.microsoft.com/face/v1.0/identify
/// <see cref="https://westus.dev.cognitive.microsoft.com/docs/services/563879b61984550e40cbbe8d/operations/563879b61984550f30395239" /></summary>
const wchar_t EndpointHelper::FaceIdentify[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/identify";

/// <summary>Face-Verify Endpoint: https://[location].api.cognitive.microsoft.com/face/v1.0/verify
/// <see cref="https://westus.dev.cognitive.microsoft.com/docs/services/563879b61984550e40cbbe8d/operations/563879b61984550f3039523a" /></summary>
const wchar_t EndpointHelper::FaceVerify[] = L"https://%s.api.cognitive.microsoft.com/face/v1.0/verify";

/// <summary>Helper function to build endpoint string</summary>
/// <param name="_BaseUri">baseUri API endpoint format string</param>
///<param name="_Region">Azure region</param>
///<param name="_Parameter">additional URL parameter </param>
///<returns>Formatted URI string as <see cref="Platform::String^" /></returns>
String^ EndpointHelper::BuildEndpointString(PCWSTR _BaseUri, PCWSTR _Region, String^ _Parameters)
{
	std::wstring strEndpoint(1024,'0');
	swprintf_s((PWSTR) strEndpoint.c_str(), strEndpoint.size(), _BaseUri, _Region, _Parameters->Data());
	return ref new Platform::String(strEndpoint.c_str());
}

/// <summary>Helper function to build endpoint Uri</summary>
/// <param name="_BaseUri">baseUri API endpoint format string</param>
///<param name="_Region">Azure region</param>
///<param name="_Parameter">additional URL parameter </param>
///<returns>Formatted <see cref="Windows::Foundation::Uri^" /></returns>
Uri^ EndpointHelper::BuildEndpointUri(PCWSTR _BaseUri, PCWSTR _Region, String^ _Parameters)
{
	return ref new Uri( BuildEndpointString(_BaseUri, _Region, _Parameters) );
}

/// <summary>Helper function to build endpoint Uri</summary>
/// <param name="_BaseUri">baseUri API endpoint format string</param>
///<param name="_Region">Azure region</param>
///<param name="_Parameter">additional URL parameter </param>
///<returns>Formatted <see cref="Windows::Foundation::Uri^" /></returns>
Uri^ EndpointHelper::BuildEndpointUri(PCWSTR _BaseUri, AzureRegions _Region, String^ _Parameters)
{
	return BuildEndpointUri(_BaseUri, AzureRegionHelper::GetRegionName(_Region), _Parameters);
}

Platform::String^ EndpointHelper::BuildParameterList(
	bool ReturnFaceId,
	bool ReturnFaceLandmarks,
	Windows::Foundation::Collections::IIterable<FaceAttributeOptions>^ ReturnFaceAttributes)
{
	std::wstringstream ssParams;
	ssParams << L"?" << Parameters::FaceId << L"=" << Globals::Bool_ToString(ReturnFaceId);
	ssParams << L"&" << Parameters::FaceLandmarks << L"=" << Globals::Bool_ToString(ReturnFaceLandmarks);
	if (ReturnFaceAttributes != nullptr && ReturnFaceAttributes->First()->HasCurrent)
	{
		auto iter = ReturnFaceAttributes->First();
		ssParams << L"&" << Parameters::FaceAttributes << L"=" << FaceAttributeOptionsHelper::GetFaceAttribute(iter->Current);
		while (iter->MoveNext())
			if (iter->HasCurrent)
				ssParams << L"," << FaceAttributeOptionsHelper::GetFaceAttribute(iter->Current);
	}

	return ref new String(ssParams.str().c_str());
}
