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

			///private helper functions
			concurrency::task< Windows::Web::Http::HttpRequestMessage^> buildHttpRequestWithHeadersAsync(
				Windows::Web::Http::HttpMethod^ method, 
				Windows::Foundation::Uri^ uri,
				Platform::String^ TextToSpeak);

			Windows::Web::Http::IHttpContent^ SpeechClient::buildRequestContent(Platform::String^ TextToSpeak);
			Platform::String^ SpeechClient::buildSSML(Platform::String^ TextToSpeak);

			concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> synthesize(Platform::String^ TextToSpeak);

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
			///<summary>
			/// SpeechClient ctor
			///</summary>
			///<param name="SubscriptionKey">The Azure SpeechAPI service key</param>
			///<param name="AppId">Your applications ApplicationId</param>
			///<param name="ClientId">Arbitrary Client Id</param>
			SpeechClient(Platform::String^ SubscriptionKey, Platform::String^ AppId, Platform::String^ ClientId);


			///<summary>
			/// Converts given plain text into speech stream
			///</summary>
			///<param name="TextToSpeak">Plain text to convert to speech</param>
			///<returns><see cref="Windows::Foundation::IAsyncOperation">IAsyncOperation</see> that completes with 
			///<see cref="Windows::Storage::Streams::IInputStream">IInputStream</see></returns>
			Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream^>^ TextToSpeech(Platform::String^ TextToSpeak);

		private:
			~SpeechClient();

		};

	}
}

