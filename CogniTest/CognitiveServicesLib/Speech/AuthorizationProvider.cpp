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


///<seealso cref="https://dev.cognitive.microsoft.com/docs/services/57346a70b4769d2694911369/operations/57346edcb5816c23e4bf7421" />
String^ AuthorizationProvider::m_FetchTokenUri = L"https://api.cognitive.microsoft.com/sts/v1.0/issueToken";
int AuthorizationProvider::m_IntervalInMinutes = 9;

#define TICKS_PER_SECOND 10000000LL
#define TICKS_PER_MINUTE 60LL * TICKS_PER_SECOND


AuthorizationProvider::AuthorizationProvider(Platform::String^ SubscriptionKey) :
	m_AuthorizationToken( nullptr ),
	m_SubscriptionKey( SubscriptionKey ),
	m_CancellationTokenSource( Concurrency::cancellation_token_source() )
{
	__LOGFUNC;

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
	__LOGFUNC;

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
	__LOGFUNC;

	auto action = create_async([this]() {
		return m_FetchTask;
	});
	return action;
}


task<String^> AuthorizationProvider::FetchTokenAsync()
{
	__LOGFUNC;

	HttpClient^ httpClient = ref new HttpClient();
	auto uri = ref new Uri(m_FetchTokenUri);
	__LOGMSG(uri->ToString()->Data());

	httpClient->DefaultRequestHeaders->Append(ref new String(HttpHeaderName::OcpApimSubscriptionKey), m_SubscriptionKey);
	auto t = create_task( httpClient->PostAsync(uri, nullptr), m_CancellationTokenSource.get_token() )
	.then([httpClient,this](HttpResponseMessage^ httpResponse) {

		return httpResponse->Content->ReadAsStringAsync();
	}, m_CancellationTokenSource.get_token())
	.then([httpClient, this](String^ strResult) {
		m_AuthorizationToken = String::Concat(L"Bearer ", strResult);

		__LOGMSG( (strResult!=nullptr) ?  strResult->Data() : L"ERROR: no token aquired");

		return m_AuthorizationToken;
	}, m_CancellationTokenSource.get_token());
	return t;
}