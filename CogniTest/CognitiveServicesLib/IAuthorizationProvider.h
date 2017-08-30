#pragma once
namespace CognitiveServicesLib
{

	public interface class IAuthorizationProvider 
	{
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
		Windows::Foundation::IAsyncOperation<Platform::String^>^ GetAuthorizationTokenAsync();
	};
}

