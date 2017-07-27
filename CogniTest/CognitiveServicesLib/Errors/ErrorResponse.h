#pragma once

#ifndef COGNITIVESERVICESERROR_DEFINED
#define COGNITIVESERVICESERROR_DEFINED

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
	}
}

#endif
