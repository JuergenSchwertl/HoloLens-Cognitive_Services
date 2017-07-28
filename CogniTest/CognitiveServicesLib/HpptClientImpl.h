#pragma once

#ifndef HTTPCLIENTIMPL_DEFINED
#define HTTPCLIENTIMPL_DEFINED

namespace CognitiveServicesLib
{
	class HpptClientImpl
	{
	private:
		Windows::Web::Http::HttpClient^ m_httpClient;
		AzureRegions m_Region;
		Platform::String^ m_strSubscriptionKey;


		Concurrency::cancellation_token_source m_cancellationTokenSource;
		Windows::Storage::Streams::Buffer^ m_readBuffer;

		Windows::Web::Http::HttpRequestMessage^ HpptClientImpl::buildHttpRequestWithHeaders(Windows::Web::Http::HttpMethod^ method, Windows::Foundation::Uri^ uri);
		Windows::Web::Http::HttpStringContent^ buildJsonUrlContent(Windows::Foundation::Uri^ _FileUri);
		Windows::Web::Http::HttpStreamContent^ buildFileStreamContent(Windows::Storage::Streams::IRandomAccessStream^ _FileStream);
		Windows::Web::Http::HttpBufferContent^ buildBufferContent(Windows::Storage::Streams::IBuffer^ _Buffer);
		Concurrency::task<Platform::String^> retrieveResponseAsync(Windows::Web::Http::HttpRequestMessage^ request);

	public:
		HpptClientImpl(AzureRegions, Platform::String^);
		virtual ~HpptClientImpl();

		Concurrency::task<Platform::String^> GetAsFileAsync(Windows::Foundation::Uri^);
		//Windows::Foundation::IAsyncOperationWithProgress<Platform::String^, Windows::Web::Http::HttpProgress>^ PostFileAsync(Windows::Foundation::Uri^ _Uri, Platform::String^ _Filename);
		Concurrency::task<Platform::String^> PostStreamAsync(Windows::Foundation::Uri^ _Uri, Windows::Storage::Streams::IRandomAccessStream^ _FileStream);
		Concurrency::task<Platform::String^> PostFileAsync(Windows::Foundation::Uri^ _Uri, Platform::String^ _FileName);
		Concurrency::task<Platform::String^> PostUriAsync(Windows::Foundation::Uri^ _Uri, Windows::Foundation::Uri^ _FileUri);
		Concurrency::task<Platform::String^> PostBufferAsync(Windows::Foundation::Uri^ _Uri, Windows::Storage::Streams::IBuffer^ _Buffer);

	};
}

#endif