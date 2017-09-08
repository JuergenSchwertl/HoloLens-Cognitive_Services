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
using namespace Windows::Data::Xml::Dom;

///<seealso cref="https://docs.microsoft.com/en-us/azure/cognitive-services/Speech/api-reference-rest/bingvoiceoutput" />
Platform::String^ SpeechClient::m_cstrSpeechendpoint = L"https://speech.platform.bing.com";
Platform::String^ SpeechClient::m_cstrSynthesizeMethod = L"/synthesize";


String^ SpeechClient::buildSSML(String^ TextToSpeak)
{
	Windows::Data::Xml::Dom::XmlDocument ^ xml = ref new Windows::Data::Xml::Dom::XmlDocument();
	//String^ strXml = L"<speak version='1.0' xml:lang='en-US'><voice xml:lang='en-US' xml:gender='Female' name='Microsoft Server Speech Text to Speech Voice (en-US, ZiraRUS)'>Microsoft Bing Voice Output API</voice></speak>";
	//xml->LoadXml(strXml);

	auto xmlSpeak = xml->CreateElement(L"speak");
	xmlSpeak->SetAttribute(L"version", L"1.0");
	xmlSpeak->SetAttribute(L"xml:lang", VoiceFontHelper::GetLanguage(m_VoiceFont));

	auto xmlVoice = xml->CreateElement(L"voice");
	xmlVoice->SetAttribute(L"xml:lang", VoiceFontHelper::GetLanguage(m_VoiceFont));
	xmlVoice->SetAttribute(L"xml:gender", VoiceFontHelper::GetGender(m_VoiceFont));
	xmlVoice->SetAttribute(L"xml:name", VoiceFontHelper::GetFontName(m_VoiceFont));

	auto xmlText = xml->CreateTextNode(TextToSpeak);

	xmlVoice->AppendChild(xmlText);
	xmlSpeak->AppendChild(xmlVoice);
	xml->AppendChild(xmlSpeak);

	String^ strXml = xmlSpeak->GetXml();
	//__LOGMSG(strXml->Data());
	return strXml;
}

IHttpContent^ SpeechClient::buildRequestContent(Platform::String^ TextToSpeak)
{
	__LOGFUNC;

	String^ strSSMLContent = buildSSML(TextToSpeak);
	HttpStringContent^ requestContent = ref new HttpStringContent(strSSMLContent);
	auto headers = requestContent->Headers;
	headers->ContentType = ref new Headers::HttpMediaTypeHeaderValue(ref new String(ContentTypes::ApplicationSsmlXml));

	unsigned long long ullContentLength;
	if (requestContent->TryComputeLength(&ullContentLength))
	{
		headers->ContentLength = ullContentLength;
	}

	__LOGMSG(headers->ToString()->Data());
	__LOGMSG(strSSMLContent->Data());

	return requestContent;
}

task<HttpRequestMessage^> SpeechClient::buildHttpRequestWithHeadersAsync(HttpMethod^ method, Uri^ uri, String^ TextToSpeak)
{
	__LOGFUNC;

	HttpRequestMessage^ request = ref new HttpRequestMessage(method, uri);
	auto headers = request->Headers;
	headers->Append(ref new String(HttpHeaderName::X_Microsoft_OutputFormat), OutputFormatHelper::ToString(m_OutputFormat));
	headers->Append(ref new String(HttpHeaderName::X_Search_AppId), m_AppId);
	headers->Append(ref new String(HttpHeaderName::X_Search_ClientId), m_ClientId);
	headers->Append(ref new String(HttpHeaderName::User_Agent), L"CognitiveServicesLib");

	// since authorization requires a roundtrip to the authentication server, the web request may still be ongoing
	String^ authorization = co_await this->m_AuthorizationProvider->GetAuthorizationTokenAsync();

	headers->Append(ref new String(HttpHeaderName::Authorization), authorization);

	__LOGMSG(uri->ToString()->Data());
	__LOGMSG(headers->ToString()->Data());

	request->Content = buildRequestContent(TextToSpeak);

	co_return request;
}


task<IRandomAccessStream^> SpeechClient::synthesize(String^ TextToSpeak)
{
	__LOGFUNC;

	Uri^ uri = ref new Uri(m_cstrSpeechendpoint, m_cstrSynthesizeMethod);
	HttpRequestMessage^ request = co_await buildHttpRequestWithHeadersAsync(HttpMethod::Post, uri, TextToSpeak);

	HttpResponseMessage^ response = co_await m_httpClient->SendRequestAsync( request );

	IHttpContent^ content = response->Content;

	if (!response->IsSuccessStatusCode)
	{
		std::wostringstream ss;
		ss << L"BAD REQUEST\r\nHttpStatusCode:" << (int)response->StatusCode << L", Reason:" << response->ReasonPhrase->Data();

		String^ strErrorResponse = co_await content->ReadAsStringAsync();
		if (strErrorResponse != nullptr)
		{
			ss << L", body:" << strErrorResponse->Data();
		}
		__LOGMSG(ss.str().c_str());

		String^ strError = ref new String(ss.str().c_str());
		throw ref new Platform::FailureException(strError);
	}

	IInputStream^ stream = nullptr;

	__LOGMSG(content->Headers->ToString()->Data());
	IBuffer^ buffer = co_await content->ReadAsBufferAsync();
	
	unsigned long long length;
	if (content->TryComputeLength(&length))
	{
		std::wostringstream ss;
		ss << L"Content-Length:" << length;
		__LOGMSG(ss.str().c_str());
	}

	InMemoryRandomAccessStream^ raStream = ref new InMemoryRandomAccessStream();

	co_await raStream->WriteAsync(buffer);
	co_await raStream->FlushAsync();
	raStream->Seek(0ull);
	co_return raStream;
}




SpeechClient::SpeechClient(String^ SubscriptionKey, String^ AppId, String^ ClientId) :
	m_SubscriptionKey( SubscriptionKey ),
	m_AppId( AppId ),
	m_ClientId( ClientId ),
	m_VoiceFont( Speech::VoiceFont::DE_DE_Female_Hedda),
	m_OutputFormat( Speech::OutputFormat::Audio_16khz_32kbitrate_mono_mp3 )
{
	__LOGFUNC;

	m_AuthorizationProvider = ref new AuthorizationProvider(SubscriptionKey);
	m_httpClient = ref new HttpClient();
}


SpeechClient::~SpeechClient()
{
}

IAsyncOperation<IRandomAccessStream ^>^ SpeechClient::TextToSpeech(Platform::String ^ TextToSpeak)
{
	__LOGFUNC;

	auto action = create_async([=]() {
		return synthesize(TextToSpeak);
	});
	return action;
}
