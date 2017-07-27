#pragma once

#ifndef LOGGER_DEFINED
#define LOGGER_DEFINED

#define BUF_LEN 1024

#define __LOGMSG(param) Logger::Message(__FUNCTIONW__, param)
#define __LOGFUNC Logger::Message(__FUNCTIONW__, (LPCWSTR) nullptr)
#define __LOG_EXCEPTION(e) Logger::Exception(__FUNCTIONW__, e, (LPCWSTR) nullptr)
#define __LOG_STD_EXCEPTION(e) Logger::StdException(__FUNCTIONW__, e)


namespace CognitiveServicesLib
{
	namespace Common
	{
		class Logger
		{
		private:
			static int Logger::formatOutput(LPWSTR *ppBuffer, LPCWSTR __function, LPCWSTR __message);

		public:
			static void Message(LPCWSTR __function, LPCWSTR __message);
			[Windows::Foundation::Metadata::DefaultOverload]
			static void Message(LPCWSTR __function, Platform::String^ __message);
			static void Message(LPCWSTR __function, Windows::Foundation::Uri^ __uri);
			static void StdException(LPCWSTR __function, std::exception& e);
			static void Exception(LPCWSTR __function, Platform::Exception^ e, LPCWSTR __message);
		};
	}
}

#endif


