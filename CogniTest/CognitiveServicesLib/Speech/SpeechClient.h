#pragma once

namespace CognitiveServicesLib
{
	///<summary>
	///<seealso cref="https://docs.microsoft.com/en-us/azure/cognitive-services/Speech/Home" />
	///</summary>
	namespace Speech
	{
		public ref class SpeechClient sealed
		{
		private:
			static Platform::String^ m_cstrSpeechendpoint;
			static Platform::String^ m_cstrSynthesizeMethod;
			Platform::String^ m_SubscriptionKey;
			Platform::String^ m_AppId;
			Platform::String^ m_ClientId;
			CognitiveServicesLib::Speech::VoiceFont m_VoiceFont;
			CognitiveServicesLib::Speech::OutputFormat m_OutputFormat;
			CognitiveServicesLib::IAuthorizationProvider^ m_AuthorizationProvider;
			Windows::Web::Http::HttpClient^ m_httpClient;

			concurrency::task< Windows::Web::Http::HttpRequestMessage^> buildHttpRequestWithHeadersAsync(
				Windows::Web::Http::HttpMethod^ method, 
				Windows::Foundation::Uri^ uri);

			concurrency::task<Windows::Storage::Streams::IInputStream^> synthesize(Platform::String^ TextToSpeak);

		public:
			property CognitiveServicesLib::Speech::VoiceFont VoiceFont
			{
				CognitiveServicesLib::Speech::VoiceFont get() { return m_VoiceFont; };
				void set(CognitiveServicesLib::Speech::VoiceFont value) { m_VoiceFont = value; };
			};

			property CognitiveServicesLib::Speech::OutputFormat OutputFormat
			{
				CognitiveServicesLib::Speech::OutputFormat get() { return m_OutputFormat;  };
				void set(CognitiveServicesLib::Speech::OutputFormat value) { m_OutputFormat = value; };
			};

		public:
			SpeechClient(Platform::String^ SubscriptionKey, Platform::String^ AppId, Platform::String^ ClientId);

		private:
			~SpeechClient();

			Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream^>^ TextToSpeech(Platform::String^ TextToSpeak);
		};

	}
}

