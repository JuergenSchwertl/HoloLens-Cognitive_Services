#include "pch.h"
#include "ErrorResponse.h"

using namespace Platform;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Errors;
using namespace Windows::Data::Json;

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