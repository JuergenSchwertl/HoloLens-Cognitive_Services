﻿using System;
using System.Collections.Generic;
using System.IO;
//using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using CognitiveServicesLib;
using CognitiveServicesLib.Speech;
using Windows.Storage.Streams;

// Die Elementvorlage "Leere Seite" wird unter https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x407 dokumentiert.

namespace CogniTestCS
{
    /// <summary>
    /// Eine leere Seite, die eigenständig verwendet oder zu der innerhalb eines Rahmens navigiert werden kann.
    /// </summary>
    public sealed partial class MainPage : Page
    {

        FaceClient m_FaceClient;
        SpeechClient m_SpeechClient;
        List<FaceAttributeOptions> m_FaceAttributeList;

        private void InitializeFaceClient()
        {
            m_FaceClient = new FaceClient(AzureRegions.WestEurope, "c36cbe9c22c3409a9e5ee9f56bb5c543");
            m_FaceAttributeList = new List<FaceAttributeOptions>(){
                FaceAttributeOptions.Age,
                FaceAttributeOptions.Gender,
                FaceAttributeOptions.HeadPose,
                FaceAttributeOptions.Smile,
                FaceAttributeOptions.FacialHair,
                FaceAttributeOptions.Glasses,
                FaceAttributeOptions.Emotion,
                FaceAttributeOptions.Hair,
                FaceAttributeOptions.Makeup,
                FaceAttributeOptions.Occlusion,
                FaceAttributeOptions.Accessories,
                FaceAttributeOptions.Blur,
                FaceAttributeOptions.Exposure,
                FaceAttributeOptions.Noise
            };
        }

        private void InitializeSpeechClient()
        {
            m_SpeechClient = new SpeechClient("cc8ed65702864541bfdf6e4a1992f817", "1216AE2105044930980B516FE1356618", "FC48480ED6AE4669A2C08D551DDB438A");
            m_SpeechClient.OutputFormat = OutputFormat.Audio_16khz_32kbitrate_mono_mp3;
            m_SpeechClient.VoiceFont = VoiceFont.DE_DE_Female_Hedda;
        }

        public MainPage()
        {
            this.InitializeComponent();
            this.InitializeFaceClient();
            this.InitializeSpeechClient();
        }


        private async void BtnSpeak_Click(object sender, RoutedEventArgs e)
        {
            IRandomAccessStream stream = await m_SpeechClient.TextToSpeech("Franz fährt im komplett verwahrlosten Taxi quer durch Bayern.");
            if (stream != null)
            {
                MediaPlayer.SetSource(stream, "audio/mpeg");
                // https://blogs.msdn.microsoft.com/mcsuksoldev/2014/07/12/video-streaming-with-a-custom-irandomaccessstream-on-windows-and-windows-phone-universal-app/
                MediaPlayer.Play();
            }

        }

        private async void BtnFakeDetect_Click(object sender, RoutedEventArgs e)
        {
            IList<Face> faceList = await m_FaceClient.FakeDetectAsync("");
            Face face = faceList[0];
            String strFaceData = face.ToString();

            LblResult.Text = strFaceData;

            //byte[] ImageData = new byte[1000];
            //IList<Face> faceList = await m_FaceClient.DetectFromImageAsync(ImageData.AsBuffer(), true, true, m_FaceAttributeList);

            //List<byte> Img = new List<byte>(1000);
            //IList<Face> faceList2 = await m_FaceClient.DetectFromImageAsync(Img.ToArray().AsBuffer(), true, true, m_FaceAttributeList);

        }

        private async void BtnDetectFromFile_Click(object sender, RoutedEventArgs e)
        {
            Uri uriTestImage =  new Uri("ms-appx:///Assets/Juergen_Schwertl.jpg");
            IList<Face> faceList = await m_FaceClient.DetectFromUriAsync(uriTestImage, true, false, m_FaceAttributeList);
            Face face = faceList[0];
            String strText = "";

            //LblResult.Text = face.ToString();

            strText += (face.FaceAttributes.Gender == "male") ? "Der Mann " : "Die Frau ";
            strText += "ist etwa ";
            strText += ( (int)face.FaceAttributes.Age).ToString();
            strText += " Jahre alt und sieht ";

            if (face.FaceAttributes.Emotion.Happiness > 0.7)
            {
                strText += "glücklich";
            }
            else if (face.FaceAttributes.Emotion.Surprise > 0.7)
            {
                strText += "überrascht";
            }
            else if (face.FaceAttributes.Emotion.Sadness > 0.7)
            {
                strText += "traurig";
            }
            else if (face.FaceAttributes.Emotion.Fear > 0.7)
            {
                strText += "ängstlich";
            }
            else if (face.FaceAttributes.Emotion.Anger > 0.7)
            {
                strText += "ärgerlich";
            }
            else
            {
                strText += "neutral";
            }
            strText += " aus ";
            if( face.FaceAttributes.Glasses != null )
            {
                strText += " und trägt ";
                switch(face.FaceAttributes.Glasses)
                {
                    case Glasses.NoGlasses:
                        strText += "keine Brille";
                        break;
                    case Glasses.ReadingGlasses:
                        strText += "eine Lesebrille";
                        break;
                    case Glasses.Sunglasses:
                        strText += "eine Sonnenbrille";
                        break;
                    case Glasses.SwimmingGoggles:
                        strText += "eine Tauchermaske";
                        break;
                }
            }

            IRandomAccessStream stream = await m_SpeechClient.TextToSpeech(strText);
            if (stream != null)
            {
                MediaPlayer.SetSource(stream, "audio/mpeg");
                MediaPlayer.Play();
            }

        }
    }
}
