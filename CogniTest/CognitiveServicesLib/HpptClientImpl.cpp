#include "pch.h"
#include <filesystem>
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

void HpptClientImpl::setHttpHeaders(Windows::Web::Http::HttpRequestMessage^ _Request)
{
	_Request->Headers->Append(ref new String( HttpHeaderName::OcpApimSubscriptionKey ), m_strSubscriptionKey);
}


HttpStringContent^ buildJsonUrlContent(Uri^ _FileUri)
{
	// Build json object 
	JsonObject^ json = ref new JsonObject();
	json->Insert(L"url", JsonValue::CreateStringValue(_FileUri->ToString()));

	// build IHttpContent with content-type and content-length
	String^ strJson = json->Stringify();
	HttpStringContent^ content = ref new HttpStringContent( strJson );
	content->Headers->ContentLength = strJson->Length();
	content->Headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(ref new String(ContentTypes::ApplicationJson));
	return content;
}

HttpStreamContent^ HpptClientImpl::buildFileStreamContent(IRandomAccessStream^ _FileStream)
{
	HttpStreamContent^ streamContent = ref new HttpStreamContent(_FileStream);
	streamContent->Headers->ContentLength = _FileStream->Size;
	streamContent->Headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(ref new String(ContentTypes::ApplicationOctetStream));
	return streamContent;
}

task<String^> HpptClientImpl::GetAsFileAsync(Uri^ _Uri)
{
	IInputStream^ httpStream;

	HttpRequestMessage^ request = ref new HttpRequestMessage(HttpMethod::Get, _Uri);
	setHttpHeaders(request);

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
	String^ key = this->m_strSubscriptionKey;
	//String^ mediatype = ContentTypes::GetFromFileName(_Filename);

	HttpRequestMessage^ request = ref new HttpRequestMessage(HttpMethod::Post, _Uri);
	setHttpHeaders(request);

	HttpStreamContent^ streamContent = buildFileStreamContent(_FileStream);
	request->Content = streamContent;

	HttpResponseMessage^ response = co_await m_httpClient->SendRequestAsync(request, HttpCompletionOption::ResponseHeadersRead);
	response->EnsureSuccessStatusCode();

	auto strResponse = co_await response->Content->ReadAsStringAsync();
	co_return strResponse;
}

task<String^> HpptClientImpl::PostUriAsync(Uri^ _EndpointUri, Uri^ _FileUri)
{
	std::wstring schema(_FileUri->SchemeName->Data());
	std::transform(schema.begin(), schema.end(), schema.begin(), ::tolower);

	if (schema.compare(L"msappx") == 0)
	{ // local file in application install folder
		IRandomAccessStream^ fileStream = co_await FileHelper::GetInputFileStreamAsync(_FileUri);
		//auto strResponse = co_await PostStreamAsync(_EndpointUri, fileStream);
		//co_return strResponse;
		return PostStreamAsync(_EndpointUri, fileStream);
	}
	else
	{
		String^ key = this->m_strSubscriptionKey;
		//String^ mediatype = ContentTypes::GetFromFileName(_Filename);

		HttpRequestMessage^ request = ref new HttpRequestMessage(HttpMethod::Post, _EndpointUri);
		setHttpHeaders(request);

		HttpStringContent^ httpContent = buildJsonUrlContent( _FileUri );
		request->Content = httpContent;

		HttpResponseMessage^ response = co_await m_httpClient->SendRequestAsync(request, HttpCompletionOption::ResponseHeadersRead);
		response->EnsureSuccessStatusCode();

		//auto strResponse = co_await response->Content->ReadAsStringAsync();
		//co_return strResponse;
		return response->Content->ReadAsStringAsync();

	}
}

task<String^> HpptClientImpl::PostFileAsync(Uri^ _EndpointUri, String^ _Filename)
{
	IRandomAccessStream^ fileStream = co_await FileHelper::GetInputFileStreamAsync(_Filename);
	auto strResponse = co_await PostStreamAsync(_EndpointUri, fileStream);
	co_return strResponse;
}