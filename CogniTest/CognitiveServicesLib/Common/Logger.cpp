#include "pch.h"
#include "Logger.h"

using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;

int Logger::formatOutput(LPWSTR *ppBuffer, LPCWSTR __function, LPCWSTR __message)
{
	LPWSTR pBuffer = (LPWSTR)malloc(BUF_LEN * sizeof(wchar_t));
	register LPWSTR dst = *ppBuffer = pBuffer;
	register LPCWSTR src;
	int iRemaining = BUF_LEN;
	const WCHAR chNull = L'0';
	SYSTEMTIME time;
	GetSystemTime(&time);
	*dst++ = L'[';
	*dst++ = chNull + (WCHAR)(time.wHour / 10);
	*dst++ = chNull + (WCHAR)(time.wHour % 10);
	*dst++ = L':';
	*dst++ = chNull + (WCHAR)(time.wMinute / 10);
	*dst++ = chNull + (WCHAR)(time.wMinute % 10);
	*dst++ = L':';
	*dst++ = chNull + (WCHAR)(time.wSecond / 10);
	*dst++ = chNull + (WCHAR)(time.wSecond % 10);
	*dst++ = L':';
	*dst++ = chNull + (WCHAR)((time.wMilliseconds / 100) % 10);
	*dst++ = chNull + (WCHAR)((time.wMilliseconds / 10) % 10);
	*dst++ = chNull + (WCHAR)(time.wMilliseconds % 10);
	*dst++ = L']';
	*dst++ = L' ';
	*dst = L'0';
	iRemaining -= (dst - pBuffer);

	if ((src = __function) != nullptr)
	{
		while ((*dst++ = *src++) != 0 && --iRemaining > 0); // copy function name (incl. trailling NUL char)
		dst--; //correct ptr to point to NUL char

		if (iRemaining < 4) // cannot add "()\0"
		{
			*dst = L'\0';
			return (dst - pBuffer);
		}

		*dst++ = L'(';
		*dst++ = L')';
		*dst++ = L' ';
		*dst = L'\0'; // still point to NUL char
		iRemaining -= 3;
	}

	if ((src = __message) != nullptr)
	{
		while ((*dst++ = *src++) != 0 && --iRemaining > 0); // copy message (incl. trailling NUL char)
		*--dst = L'\0'; //correct ptr to point to NUL char or at last char copied when iRemaining == 0
	}

	if (iRemaining >= 3)
	{
		*dst++ = L'\r';
		*dst++ = L'\n';
		*dst = L'\0';
	}

	return (dst - pBuffer);
}

void Logger::Message(LPCWSTR __function, LPCWSTR __message)
{
	if (Windows::ApplicationModel::DesignMode::DesignModeEnabled)
		return;

	LPWSTR pBuffer;
	int iLength = Logger::formatOutput(&pBuffer, __function, __message);

	OutputDebugString(pBuffer);

	free(pBuffer);
}

void Logger::Message(LPCWSTR __function, Platform::String^ __message)
{
	if (Windows::ApplicationModel::DesignMode::DesignModeEnabled)
		return;

	if (__message != nullptr)
		Logger::Message(__function, __message->Data());
}

void Logger::Message(LPCWSTR __function, Windows::Foundation::Uri^ __uri)
{
	if (Windows::ApplicationModel::DesignMode::DesignModeEnabled)
		return;

	if (__uri != nullptr)
		Logger::Message(__function, __uri->ToString());
}


void Logger::StdException(LPCWSTR __function, std::exception& e)
{
	if (Windows::ApplicationModel::DesignMode::DesignModeEnabled)
		return;

	LPWSTR pBuffer;
	int iLength = Logger::formatOutput(&pBuffer, __function, L"EXCEPTION : ");

	OutputDebugString(pBuffer);
	OutputDebugString((LPCWSTR)e.what());

	free(pBuffer);
}

void Logger::Exception(LPCWSTR __function, Platform::Exception^ e, LPCWSTR __message)
{
	if (Windows::ApplicationModel::DesignMode::DesignModeEnabled)
		return;

	LPWSTR pBuffer;
	int iLength = Logger::formatOutput(&pBuffer, __function, __message);

	OutputDebugString(pBuffer);
	OutputDebugString(e->Message->Data());

	free(pBuffer);
}