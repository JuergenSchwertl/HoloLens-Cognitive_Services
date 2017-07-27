#pragma once

#ifndef COGNITIVESERVICESERROR_DEFINED
#define COGNITIVESERVICESERROR_DEFINED

// http://msdn.microsoft.com/en-us/library/aa362823(v=vs.85).aspx
// BitsMsg.h defines the codes as BG_E_HTTP_ERROR_400 0x80190190
// so using the same numbering scheme
#define BG_E_HTTP_ERROR_BASE 0x80190000



namespace CognitiveServicesLib
{
	namespace Errors
	{
		public ref class ErrorResponse sealed
		{
		private:
			Platform::String^ m_Code;

		public:
			property Platform::String^ Code
			{
				Platform::String^ get() { return m_Code; }
				void set(Platform::String^ _Code) { m_Code = _Code; }
			}

		private:
			Platform::String^ m_Message;
		public:
			property Platform::String^ Message
			{
				Platform::String^ get() { return m_Message; }
				void set(Platform::String^ _Message) { m_Message = _Message; }
			}

		public:
			ErrorResponse();
			ErrorResponse(Platform::String^ _JsonError);
		};



		/*public ref class InvalidHttpResponseException : Platform::Exception
		{
		private:
			CognitiveServicesLib::Errors::ErrorResponse^ m_Response;

		public:
			property CognitiveServicesLib::Errors::ErrorResponse^ Response
			{
				CognitiveServicesLib::Errors::ErrorResponse^ get() { return m_Response; }
				void set(CognitiveServicesLib::Errors::ErrorResponse^ _Response) { m_Response = _Response;  }
			}


		public:
			InvalidHttpResponseException(Windows::Web::Http::HttpStatusCode _Status, ErrorResponse^ _ErrorResponse);
			static InvalidHttpResponseException^ Create(Windows::Web::Http::HttpStatusCode _Status, Platform::String^ _JsonResponse);
		};*/
	}
}

#endif
