#include "pch.h"
#include <filesystem>
#include "Errors/ErrorResponse.h"
#include "FileHelper.h"
#include "HpptClientImpl.h"

using namespace concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::Web::Http;
using namespace Windows::Data::Json;
using namespace std::experimental::filesystem::v1;


Windows::Web::Http::HttpClient^ m_httpClient = nullptr;



HpptClientImpl::HpptClientImpl(AzureRegions _Region, Platform::String^ _SubscriptionKey) :
	m_Region( _Region ),
	m_strSubscriptionKey( _SubscriptionKey ),
	m_httpClient( ref new HttpClient() ),
	m_cancellationTokenSource ( cancellation_token_source() )
{
	
	
}

HpptClientImpl::~HpptClientImpl()
{
	//m_httpClient->Close();
	m_httpClient = nullptr;
}

HttpRequestMessage^ HpptClientImpl::buildHttpRequestWithHeaders(HttpMethod^ method, Uri^ uri)
{
	HttpRequestMessage^ request = ref new HttpRequestMessage(method, uri);
	request->Headers->Append(ref new String( HttpHeaderName::OcpApimSubscriptionKey ), m_strSubscriptionKey);
	//request->Headers->Append(ref new String(HttpHeaderName::OcpApimSubscriptionKey), L"incorrect key to test");
	return request;
}


HttpStringContent^ HpptClientImpl::buildJsonUrlContent(Uri^ _FileUri)
{
	// Build json object 
	JsonObject^ json = ref new JsonObject();
	json->Insert(L"url", JsonValue::CreateStringValue(_FileUri->ToString()));

	// build IHttpContent with content-type and content-length
	String^ strJson = json->Stringify();
	HttpStringContent^ content = ref new HttpStringContent( strJson );
	content->Headers->ContentLength = (unsigned long long) strJson->Length();
	content->Headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(ref new String(ContentTypes::ApplicationJson));
	__LOGMSG(content->Headers->ToString());
	return content;
}

HttpStreamContent^ HpptClientImpl::buildFileStreamContent(IRandomAccessStream^ _FileStream)
{
	HttpStreamContent^ content = ref new HttpStreamContent(_FileStream);
	content->Headers->ContentLength = _FileStream->Size;
	content->Headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(ref new String(ContentTypes::ApplicationOctetStream));

	__LOGMSG(content->Headers->ToString());

	return content;
}

HttpBufferContent^ HpptClientImpl::buildBufferContent(IBuffer^ _Buffer)
{
	HttpBufferContent^ content = ref new HttpBufferContent(_Buffer);
	content->Headers->ContentLength = (unsigned long long) _Buffer->Length;
	content->Headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(ref new String(ContentTypes::ApplicationOctetStream));

	__LOGMSG(content->Headers->ToString());

	return content;
}

task<String^> HpptClientImpl::retrieveResponseAsync(HttpRequestMessage^ request)
{
	HttpResponseMessage^ response = co_await m_httpClient->SendRequestAsync(request, HttpCompletionOption::ResponseHeadersRead);
	__LOGMSG(response->ReasonPhrase);

	auto strResponse = co_await response->Content->ReadAsStringAsync();
	if (!response->IsSuccessStatusCode)
	{
		auto ex = Platform::Exception::CreateException(BG_E_HTTP_ERROR_BASE | (int)response->StatusCode, strResponse);
		__LOG_EXCEPTION(ex);
		throw ex;
	}

	__LOGMSG(strResponse);
	
	co_return strResponse;
}

task<String^> HpptClientImpl::GetAsFileAsync(Uri^ _Uri)
{
	IInputStream^ httpStream;

	HttpRequestMessage^ request = buildHttpRequestWithHeaders(HttpMethod::Get, _Uri);
	
	HttpResponseMessage^ response = co_await m_httpClient->SendRequestAsync(request, HttpCompletionOption::ResponseHeadersRead);
	response->EnsureSuccessStatusCode();

	String^ strContentTypeHeader = ref new String(HttpHeaderName::ContentType);
	String^ strContentType = nullptr;

	if (response->Headers->HasKey(strContentTypeHeader))
	{
		strContentType = response->Headers->Lookup(strContentTypeHeader);
	}

	// TODO: generate filename with correct extension
	String^ filename = L"test.wav";

	IRandomAccessStream^ fileStream = co_await FileHelper::GetOutputFileStreamAsync(filename);
	co_await response->Content->WriteToStreamAsync(fileStream);
	co_await fileStream->FlushAsync();
	fileStream = nullptr;

	co_return filename;
}

task<String^> HpptClientImpl::PostStreamAsync(Uri^ _Uri, IRandomAccessStream^ _FileStream)
{
	__LOGMSG(_Uri);

	HttpRequestMessage^ request = buildHttpRequestWithHeaders(HttpMethod::Post, _Uri);
	request->Content = buildFileStreamContent(_FileStream);
	String^ strResponse = co_await retrieveResponseAsync( request );
	co_return strResponse;
}

task<String^> HpptClientImpl::PostUriAsync(Uri^ _EndpointUri, Uri^ _FileUri)
{
	__LOGMSG(_EndpointUri);

	std::wstring schema(_FileUri->SchemeName->Data());
	std::transform(schema.begin(), schema.end(), schema.begin(), ::tolower);

	if (schema.compare(L"ms-appx") == 0)
	{ // local file in application install folder
		IRandomAccessStream^ fileStream = co_await FileHelper::GetInputFileStreamAsync(_FileUri);
		auto strResponse = co_await PostStreamAsync(_EndpointUri, fileStream);
		co_return strResponse;
	}
	else
	{
		HttpRequestMessage^ request = buildHttpRequestWithHeaders(HttpMethod::Post, _EndpointUri);
		request->Content = buildJsonUrlContent( _FileUri );
		String^ strResponse = co_await retrieveResponseAsync(request);
		co_return strResponse;
	}
}

task<String^> HpptClientImpl::PostFileAsync(Uri^ _EndpointUri, String^ _Filename)
{
	IRandomAccessStream^ fileStream = co_await FileHelper::GetInputFileStreamAsync(_Filename);
	auto strResponse = co_await PostStreamAsync(_EndpointUri, fileStream);
	co_return strResponse;
}

task<String^> HpptClientImpl::PostBufferAsync(Uri^ _EndpointUri, IBuffer^ _Buffer)
{
	__LOGMSG(_EndpointUri);

	HttpRequestMessage^ request = buildHttpRequestWithHeaders(HttpMethod::Post, _EndpointUri);
	request->Content = buildBufferContent(_Buffer);
	String^ strResponse = co_await retrieveResponseAsync(request);
	co_return strResponse;
}