#pragma once
namespace CognitiveServicesLib
{

	public ref class FaceLandmarks sealed
	{
	public:
		FaceLandmarks();

	internal:
		static FaceLandmarks^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties

	private:
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, PupilLeft, L"pupilLeft")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, PupilRight, L"pupilRight")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, NoseTip, L"noseTip")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, MouthLeft, L"mouthLeft")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, MouthRight, L"mouthRight")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeBrowLeftOuter, L"eyeBrowLeftOuter")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeBrowLeftInner, L"eyeBrowLeftInner")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeLeftOuter, L"eyeLeftOuter")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeLeftTop, L"eyeLeftTop")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeLeftBottom, L"eyeLeftBottom")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeLeftInner, L"eyeLeftInner")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeBrowRightInner, L"eyeBrowRightInner")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeBrowRightOuter, L"eyeBrowRightOuter")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeRightInner, L"eyeRightInner")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeRightTop, L"eyeRightTop")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeRightBottom, L"eyeRightBottom")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, EyeRightOuter, L"eyeRightOuter")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, NoseRootLeft, L"noseRootLeft")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, NoseRootRight, L"noseRootRight")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, NoseLeftAlarTop, L"noseLeftAlarTop")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, NoseRightAlarTop, L"noseRightAlarTop")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, NoseLeftAlarOutTip, L"noseLeftAlarOutTip")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, NoseRightAlarOutTip, L"noseRightAlarOutTip")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, UpperLipTop, L"upperLipTop")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, UpperLipBottom, L"upperLipBottom")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, UnderLipTop, L"underLipTop")
		DEFINE_PROPERTY_VARIABLES(FaceLandmarks, FeatureCoordinate^, UnderLipBottom, L"underLipBottom")

	public:
		///<summary>Gets or sets the pupil left</summary>
		///<value>The pupil left</value>
		property FeatureCoordinate^ PupilLeft { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }


		///<summary>Gets or sets the pupil right</summary>
		///<value>The pupil right</value>
		property FeatureCoordinate^ PupilRight { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the nose tip</summary>
		///<value>The nose tip</value>
		property FeatureCoordinate^ NoseTip { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the mouth left</summary>
		///<value>The mouth left</value>
		property FeatureCoordinate^ MouthLeft { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the mouth right</summary>
		///<value>The mouth right</value>
		property FeatureCoordinate^ MouthRight { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eybrow left outer</summary>
		///<value>The eybrow left outer</value>
		property FeatureCoordinate^ EyeBrowLeftOuter { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eybrow left inner</summary>
		///<value>The eybrow left inner</value>
		property FeatureCoordinate^ EyeBrowLeftInner { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye left outer</summary>
		///<value>The eye left outer</value>
		property FeatureCoordinate^ EyeLeftOuter { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye left top</summary>
		///<value>The eye left top</value>
		property FeatureCoordinate^ EyeLeftTop { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye left bottom</summary>
		///<value>The eye left bottom</value>
		property FeatureCoordinate^ EyeLeftBottom { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye left inner</summary>
		///<value>The eye left inner</value>
		property FeatureCoordinate^ EyeLeftInner { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eybrow right inner</summary>
		///<value>The eybrow right inner</value>
		property FeatureCoordinate^ EyeBrowRightInner { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eybrow right outer</summary>
		///<value>The eybrow right outer</value>
		property FeatureCoordinate^ EyeBrowRightOuter { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye right top</summary>
		///<value>The eye right top</value>
		property FeatureCoordinate^ EyeRightTop { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye right bottom</summary>
		///<value>The eye right bottom</value>
		property FeatureCoordinate^ EyeRightBottom { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye right inner</summary>
		///<value>The eye right inner</value>
		property FeatureCoordinate^ EyeRightInner { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the eye right outer</summary>
		///<value>The eye right outer</value>
		property FeatureCoordinate^ EyeRightOuter { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the nose root left</summary>
		///<value>The nose root left</value>
		property FeatureCoordinate^ NoseRootLeft { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the nose root right</summary>
		///<value>The nose root right</value>
		property FeatureCoordinate^ NoseRootRight { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the nose left alar top</summary>
		///<value>The nose left alar top</value>
		property FeatureCoordinate^ NoseLeftAlarTop { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the nose right alar top</summary>
		///<value>The nose right alar top</value>
		property FeatureCoordinate^ NoseRightAlarTop { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the nose left alar out tip</summary>
		///<value>The nose left alar out tip</value>
		property FeatureCoordinate^ NoseLeftAlarOutTip { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the nose right alar out tip</summary>
		///<value>The nose right alar out tip</value>
		property FeatureCoordinate^ NoseRightAlarOutTip { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the upper lip top</summary>
		///<value>The upper lip top</value>
		property FeatureCoordinate^ UpperLipTop { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the upper lip bottom</summary>
		///<value>The upper lip bottom</value>
		property FeatureCoordinate^ UpperLipBottom { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the under lip top</summary>
		///<value>The under lip top</value>
		property FeatureCoordinate^ UnderLipTop { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }

		///<summary>Gets or sets the upper lip bottom</summary>
		///<value>The under lip bottom</value>
		property FeatureCoordinate^ UnderLipBottom { FeatureCoordinate^ get(); void set(FeatureCoordinate^ value); }
#pragma endregion

	};
}


