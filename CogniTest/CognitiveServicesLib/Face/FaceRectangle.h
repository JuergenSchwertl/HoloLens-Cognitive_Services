#pragma once

namespace CognitiveServicesLib
{
	public ref class FaceRectangle sealed
	{
	public:
		FaceRectangle();

		static FaceRectangle^ FromJson(Windows::Data::Json::JsonObject^);

#pragma region Properties
	private:
		DEFINE_PROPERTY_VARIABLES(FaceRectangle, int, Width, L"width")
		DEFINE_PROPERTY_VARIABLES(FaceRectangle, int, Height, L"height")
		DEFINE_PROPERTY_VARIABLES(FaceRectangle, int, Left, L"left")
		DEFINE_PROPERTY_VARIABLES(FaceRectangle, int, Top, L"top")

	public:

		///<summary>Gets or sets the width in pixel</summary>
		///<value>The width of the face rectangle</value>
		property int Width { int get(); void set(int); }

		///<summary>Gets or sets the height in pixel</summary>
		///<value>The height of the face rectangle</value>
		property int Height { int get(); void set(int); }

		///<summary>Gets or sets the left in pixel</summary>
		///<value>The left of the face rectangle</value>
		property int Left { int get(); void set(int); }

		///<summary>Gets or sets the top in pixel</summary>
		///<value>The top of the face rectangle</value>
		property int Top { int get(); void set(int); }

#pragma endregion
	};
}

