#include "pch.h"
#include "IAuthorizationProvider.h"
#include "Speech/AuthorizationProvider.h"

using namespace Concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace CognitiveServicesLib::Speech;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Web::Http;
using namespace Windows::System::Threading;

String^ AuthorizationProvider::m_FetchTokenUri = L"https://api.cognitive.microsoft.com/sts/v1.0";
int AuthorizationProvider::m_IntervalInMinutes = 9;

#define TICKS_PER_SECOND 10000000LL
#define TICKS_PER_MINUTE 60LL * TICKS_PER_SECOND


AuthorizationProvider::AuthorizationProvider(Platform::String^ SubscriptionKey) :
	m_AuthorizationToken( nullptr ),
	m_SubscriptionKey( SubscriptionKey ),
	m_CancellationTokenSource( Concurrency::cancellation_token_source() )
{
	if ((SubscriptionKey == nullptr) || (SubscriptionKey->IsEmpty()))
	{
		throw ref new InvalidArgumentException(L"Invalid or missing SubscriptionKey");
	}
	m_FetchTask = FetchTokenAsync();
	setTimer();
}

AuthorizationProvider::~AuthorizationProvider()
{
	if (m_Timer != nullptr)
	{
		m_Timer->Cancel();
		m_Timer = nullptr;
	}
	m_CancellationTokenSource.cancel();
	
}

void AuthorizationProvider::setTimer()
{
	auto timerDelegate = [this](ThreadPoolTimer^ timer)
	{
		m_FetchTask = FetchTokenAsync();
	};

	TimeSpan interval;
	interval.Duration = (long long)m_IntervalInMinutes * TICKS_PER_MINUTE;
	m_Timer = ThreadPoolTimer::CreatePeriodicTimer(ref new TimerElapsedHandler(timerDelegate), interval);
}


IAsyncOperation<String^>^ AuthorizationProvider::GetAuthorizationTokenAsync()
{
	auto action = create_async([this]() {
		return m_FetchTask;
	});
	return action;
}


task<String^> AuthorizationProvider::FetchTokenAsync()
{
	HttpClient^ httpClient = ref new HttpClient();
	auto uri = ref new Uri(m_FetchTokenUri, L"/issueToken");
	httpClient->DefaultRequestHeaders->Append(ref new String(HttpHeaderName::OcpApimSubscriptionKey), m_SubscriptionKey);
	auto t = create_task( httpClient->PostAsync(uri, nullptr), m_CancellationTokenSource.get_token() )
	.then([httpClient,this](HttpResponseMessage^ httpResponse) {
		return httpResponse->Content->ReadAsStringAsync();
	}, m_CancellationTokenSource.get_token())
	.then([httpClient, this](String^ strResult) {
		m_AuthorizationToken = strResult;
		return strResult;
	}, m_CancellationTokenSource.get_token());
	return t;
}