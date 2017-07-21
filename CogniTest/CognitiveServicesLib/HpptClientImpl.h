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

		void setHttpHeaders(Windows::Web::Http::HttpRequestMessage^ _Request);

		//Concurrency::task<Windows::Storage::Streams::IInputStream^> getAsStreamAsync(Windows::Foundation::Uri^);
		Concurrency::task<int> testAsync() __resumable;
		Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> getInputFileStreamAsync(Platform::String^ _FileName);
		Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> getOutputFileStreamAsync(Platform::String^ _FileName);

	public:
		HpptClientImpl(AzureRegions, Platform::String^);
		virtual ~HpptClientImpl();

		Concurrency::task<Platform::String^> GetAsFileAsync(Windows::Foundation::Uri^);
		//Windows::Foundation::IAsyncOperationWithProgress<Platform::String^, Windows::Web::Http::HttpProgress>^ PostFileAsync(Windows::Foundation::Uri^ _Uri, Platform::String^ _Filename);
		Concurrency::task<Platform::String^> PostFileAsync(Windows::Foundation::Uri^ _Uri, Platform::String^ _Filename);

	};
}

#endif