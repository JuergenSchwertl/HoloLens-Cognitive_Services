#include "pch.h"
#include "IAuthorizationProvider.h"
#include "Speech\AuthorizationProvider.h"
#include "Speech\OutputFormat.h"
#include "Speech\VoiceFont.h"
#include "Speech\SpeechClient.h"

using namespace concurrency;
using namespace Platform;
using namespace Windows::Foundation;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace CognitiveServicesLib::Speech;
using namespace Windows::Storage::Streams;
using namespace Windows::Web::Http;
using namespace Windows::Web::Http::Headers;

Platform::String^ SpeechClient::m_cstrSpeechendpoint = L"https://speech.platform.bing.com";
Platform::String^ SpeechClient::m_cstrSynthesizeMethod = L"/synthesize";


task<HttpRequestMessage^> SpeechClient::buildHttpRequestWithHeadersAsync(HttpMethod^ method, Uri^ uri)
{
	__LOGFUNC;

	HttpRequestMessage^ request = ref new HttpRequestMessage(method, uri);
	auto headers = request->Headers;
	headers->Append(ref new String(HttpHeaderName::X_Microsoft_OutputFormat), OutputFormatHelper::ToString(m_OutputFormat));
	headers->Append(ref new String(HttpHeaderName::X_Search_AppId), m_AppId);
	headers->Append(ref new String(HttpHeaderName::X_Search_ClientId), m_ClientId);
	headers->Append(ref new String(HttpHeaderName::User_Agent), L"CognitiveServicesLib");

	// since authorization requires a roundtrip to the authentication server, teh web requesdt may still be ongoing
	String^ authorization = co_await this->m_AuthorizationProvider->GetAuthorizationTokenAsync();
	headers->Append(ref new String(HttpHeaderName::Authorization), authorization);

	__LOGMSG(headers->ToString()->Data());
	co_return request;
}

IHttpContent^ buildRequestContent(Platform::String^ TextToSpeak)
{
	__LOGFUNC;

	HttpStringContent^ requestContent = ref new HttpStringContent(TextToSpeak);
	auto headers = requestContent->Headers;
	headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(ref new String(ContentTypes::ApplicationSsmlXml));

	unsigned long long ullContentLength;
	if (requestContent->TryComputeLength(&ullContentLength))
	{
		headers->ContentLength = ullContentLength;
	}
	__LOGMSG(headers->ToString()->Data());

	return requestContent;
}


task<IInputStream^> SpeechClient::synthesize(String^ TextToSpeak)
{
	__LOGFUNC;

	Uri^ uri = ref new Uri(m_cstrSpeechendpoint, m_cstrSynthesizeMethod);
	HttpRequestMessage^ request = co_await buildHttpRequestWithHeadersAsync(HttpMethod::Post, uri);
	request->Content = buildRequestContent( TextToSpeak );

	HttpResponseMessage^ response = co_await m_httpClient->SendRequestAsync( request );

	IHttpContent^ content = response->Content;

	if (!response->IsSuccessStatusCode)
	{
		String^ strErrorResponse = co_await content->ReadAsStringAsync();
		__LOGMSG(strErrorResponse->Data());
		throw ref new Platform::FailureException(strErrorResponse);
	}

	IInputStream^ stream = nullptr;
	String^ strContentType = content->Headers->ContentType->MediaType;
	__LOGMSG(strContentType->Data());
	stream = co_await content->ReadAsInputStreamAsync();

	co_return stream;
}




SpeechClient::SpeechClient(String^ SubscriptionKey, String^ AppId, String^ ClientId) :
	m_SubscriptionKey( SubscriptionKey ),
	m_AppId( AppId ),
	m_ClientId( ClientId ),
	m_VoiceFont( Speech::VoiceFont::DE_DE_Female_Hedda),
	m_OutputFormat( Speech::OutputFormat::Audio_16khz_32kbitrate_mono_mp3 )
{
	m_AuthorizationProvider = ref new AuthorizationProvider(SubscriptionKey);
	m_httpClient = ref new HttpClient();
}


SpeechClient::~SpeechClient()
{
}

IAsyncOperation<IInputStream ^>^ SpeechClient::TextToSpeech(Platform::String ^ TextToSpeak)
{
	auto action = create_async([=]() {
		return synthesize(TextToSpeak);
	});
	return action;
}
