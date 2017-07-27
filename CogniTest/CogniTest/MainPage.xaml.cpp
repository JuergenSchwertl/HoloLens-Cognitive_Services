//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"

#include "MainPage.xaml.h"

using namespace CogniTest;

using namespace Concurrency;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace CognitiveServicesLib;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	m_FaceClient = ref new FaceClient(AzureRegions::WestEurope, L"c36cbe9c22c3409a9e5ee9f56bb5c543");
	InitializeComponent();
}


void CogniTest::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Uri^ uriTestImage = ref new Uri(L"msappx:////Assets/JuergenSchwertl.jpg");
	create_task(m_FaceClient->DetectAsync(uriTestImage)).then([=](Platform::String^ result) {
		LblResult->Text = result;
	}, task_continuation_context::use_current());
}
