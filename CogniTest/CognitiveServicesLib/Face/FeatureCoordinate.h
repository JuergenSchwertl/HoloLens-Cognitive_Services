#pragma once
#define DEFINE_PROPERTY(proptype, propname) \
private: \
	proptype m_##propname ; \
	/*static const wchar_t m_NameOf_##propname []; */ \
public: \
	property proptype propname { \
		proptype get(){ return m_##propname ;} \
		void set(proptype val){ m_##propname = val;} \
	};

//#define POPEL(tt,nn) \
//private: \
//	tt nn; \

namespace CognitiveServicesLib
{
	public ref class FeatureCoordinate sealed
	{
	private:
		//static const wchar_t m_X_Name[];

	public:
		FeatureCoordinate();

		DEFINE_PROPERTY(double, X)
		DEFINE_PROPERTY(double, Y)

	};
}

