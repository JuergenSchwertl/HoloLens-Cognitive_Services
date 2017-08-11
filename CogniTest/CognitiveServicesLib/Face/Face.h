#pragma once

namespace CognitiveServicesLib
{
	ref class Face sealed
	{
	public:
		Face();
		static Face^ FromJson(Windows::Data::Json::JsonObject^ jsonObject);

#pragma region Properties
	private:
		DEFINE_PROPERTY_VARIABLES(Face, Platform::String^, FaceId, L"faceId")
		DEFINE_PROPERTY_VARIABLES(Face, CognitiveServicesLib::FaceRectangle^, FaceRectangle, L"faceRectangle")
		DEFINE_PROPERTY_VARIABLES(Face, CognitiveServicesLib::FaceLandmarks^, FaceLandmarks, L"faceLandmarks")
		//DEFINE_PROPERTY_VARIABLES(Face, FaceAttributes^, FaceAttributes, L"faceAttributes")

	public:
		/// <summary>Gets or sets the face identifier.</summary>
		/// <value>The face identifier.</value>
		property Platform::String^ FaceId { Platform::String^	get(); void set(Platform::String^ value); }

		/// <summary>Gets or sets the face rectangle.</summary>
		/// <value>The face rectangle.</value>
		property CognitiveServicesLib::FaceRectangle^ FaceRectangle { CognitiveServicesLib::FaceRectangle^ get(); void set(CognitiveServicesLib::FaceRectangle^ value ); }

		/// <summary>Gets or sets the face landmarks.</summary>
		/// <value>The face landmarks.</value>
		property CognitiveServicesLib::FaceLandmarks^ FaceLandmarks { CognitiveServicesLib::FaceLandmarks^ get(); void set(CognitiveServicesLib::FaceLandmarks^ value ); }

		///// <summary>Gets or sets the face attributes.</summary>
		///// <value>The face attributes.</value>
		//property CognitiveServicesLib::FaceAttributes^ FaceAttributes { CognitiveServicesLib::FaceAttributes^ get(); void set( CognitiveServicesLib::FaceAttributes^ value ); }


#pragma endregion

	};
}

