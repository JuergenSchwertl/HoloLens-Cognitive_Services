#include "pch.h"
#include "ErrorResponse.h"
#include <BitsMsg.h>
using namespace Platform;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Errors;
using namespace Windows::Data::Json;

// http://msdn.microsoft.com/en-us/library/aa362823(v=vs.85).aspx
// BitsMsg.h defines the codes as BG_E_HTTP_ERROR_400 0x80190190
// so using the same numbering scheme
#define BG_E_HTTP_ERROR_BASE 0x80190000


ErrorResponse::ErrorResponse() :
	m_Code(nullptr),
	m_Message(nullptr)
{
}

ErrorResponse::ErrorResponse(String^ _JsonError)
{
	JsonObject^ jsonResponse = JsonObject::Parse(_JsonError);
	if (jsonResponse->HasKey(L"error"))
	{
		JsonObject^ jsonErrObj = jsonResponse->GetNamedObject(L"error");
		Code = jsonErrObj->GetNamedString(L"code");
		Message = jsonErrObj->GetNamedString(L"message");
	}
}
//
//InvalidHttpResponseException::InvalidHttpResponseException(Windows::Web::Http::HttpStatusCode _Status,  ErrorResponse^ _ErrorResponse) :
//	Platform::Exception::Exception(BG_E_HTTP_ERROR_BASE | (int)_Status,_ErrorResponse->Message),
//	m_Response(_ErrorResponse)
//{
//}
//
//InvalidHttpResponseException^ InvalidHttpResponseException::Create(Windows::Web::Http::HttpStatusCode _Status, Platform::String^_JsonResponse)
//{
//	ErrorResponse^ err = ref new ErrorResponse(_JsonResponse);
//	Platform::InvalidArgumentException()
//
//	return ref new InvalidHttpResponseException(_Status, err);
//}