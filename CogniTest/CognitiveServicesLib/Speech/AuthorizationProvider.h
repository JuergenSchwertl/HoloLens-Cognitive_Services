#pragma once
namespace CognitiveServicesLib
{
	namespace Speech
	{
		/// <summary>
		/// Cognitive Services Authorization Provider.
		/// </summary>
		ref class AuthorizationProvider sealed : CognitiveServicesLib::IAuthorizationProvider
		{

		private:
			static Platform::String^ m_FetchTokenUri;
			static int m_IntervalInMinutes;

			Platform::String^ m_AuthorizationToken;
			Platform::String^ m_SubscriptionKey;
			Concurrency::task<Platform::String^> m_FetchTask;
			Concurrency::cancellation_token_source m_CancellationTokenSource;
			Windows::System::Threading::ThreadPoolTimer^ m_Timer;
			
			void setTimer();

			Concurrency::task<Platform::String^> FetchTokenAsync();


		public:
			AuthorizationProvider(Platform::String^ SubscriptionKey);

		private:
			~AuthorizationProvider();

		public:
			/// <summary>
			/// Gets the authorization token asynchronously.
			/// </summary>
			/// <returns>
			/// A task that represents the asynchronous read operation. The value of the string parameter contains the next the authorization token.
			/// </returns>
			/// <remarks>
			/// This method should always return a valid authorization token at the time it is called.
			/// </remarks>
			virtual Windows::Foundation::IAsyncOperation<Platform::String^>^ GetAuthorizationTokenAsync();
		};
	}
}


