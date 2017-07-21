#include "pch.h"
#include <filesystem>
#include "HpptClientImpl.h"

using namespace concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::Web::Http;

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

	IRandomAccessStream^ fileStream = co_await getOutputFileStreamAsync(filename);
	co_await response->Content->WriteToStreamAsync(fileStream);
	co_await fileStream->FlushAsync();
	fileStream = nullptr;

	co_return filename;
}

Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> HpptClientImpl::getInputFileStreamAsync(Platform::String ^ _FileName)
{
	StorageFolder^ cacheFolder = Windows::Storage::ApplicationData::Current->LocalCacheFolder;
	StorageFile^ storagefile = co_await cacheFolder->GetFileAsync("test");
	IRandomAccessStream^ fileStream = co_await storagefile->OpenAsync(FileAccessMode::Read);
	co_return fileStream;
}

Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> HpptClientImpl::getOutputFileStreamAsync(Platform::String ^ _FileName)
{
	StorageFolder^ cacheFolder = Windows::Storage::ApplicationData::Current->LocalCacheFolder;
	StorageFile^ storagefile = co_await cacheFolder->CreateFileAsync("test");
	IRandomAccessStream^ fileStream = co_await storagefile->OpenAsync(FileAccessMode::ReadWrite);
	co_return fileStream;
}

task<String^> HpptClientImpl::PostFileAsync(Uri^ _Uri, String^ _Filename)
{
	String^ key = this->m_strSubscriptionKey;
	//String^ mediatype = ContentTypes::GetFromFileName(_Filename);
	String^ mediatype = ref new String(ContentTypes::ApplicationOctetStream);

	HttpRequestMessage^ request = ref new HttpRequestMessage(HttpMethod::Post, _Uri);
	setHttpHeaders(request);

	IRandomAccessStream^ fileStream = co_await getInputFileStreamAsync(_Filename);
	HttpStreamContent^ streamContent = ref new HttpStreamContent(fileStream);
	streamContent->Headers->ContentLength = fileStream->Size;
	streamContent->Headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(mediatype);
	request->Content = streamContent;

	HttpResponseMessage^ response = co_await m_httpClient->SendRequestAsync(request, HttpCompletionOption::ResponseHeadersRead);
	response->EnsureSuccessStatusCode();

	auto strResponse = co_await response->Content->ReadAsStringAsync();
	co_return strResponse;
	
}