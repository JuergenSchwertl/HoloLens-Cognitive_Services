﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class TextBlock;
                ref class CaptureElement;
                ref class Canvas;
                ref class Button;
            }
        }
    }
}

namespace CogniTest
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class MainPage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Controls::TextBlock^ LblResult;
        private: ::Windows::UI::Xaml::Controls::CaptureElement^ PreviewControl;
        private: ::Windows::UI::Xaml::Controls::Canvas^ FacesCanvas;
        private: ::Windows::UI::Xaml::Controls::Button^ BtnFile;
        private: ::Windows::UI::Xaml::Controls::Button^ BtnCamera;
        private: ::Windows::UI::Xaml::Controls::Button^ PhotoButton;
    };
}

