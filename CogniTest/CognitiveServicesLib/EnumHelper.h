#pragma once
#ifndef DEFINED_ENUMHELPER
#define DEFINED_ENUMHELPER

namespace CognitiveServicesLib
{
	template <class E> struct EnumKeyJsonName
	{
		E EnumKey;
		LPCTSTR JsonName;
	};

	template<class E> class EnumHelper
	{
	public:
		static E parse(Platform::String^ strValue, const EnumKeyJsonName<E> ckvJsonNamesArray[], size_t nArraySize)
		{
			if (strValue != nullptr)
			{
				LPCTSTR lpszValue = strValue->Data();
				size_t nMaxLength = (size_t)strValue->Length();
				for (size_t nIndex = 0; nIndex < nArraySize; nIndex++)
					if (wcsncmp(lpszValue, ckvJsonNamesArray[nIndex].JsonName, nMaxLength) == 0)
						return ckvJsonNamesArray[nIndex].EnumKey;
			}
			return (E)0;
		}

		static LPCTSTR c_str(E value, const EnumKeyJsonName<E> ckvJsonNamesArray[], size_t nArraySize)
		{
			// quick check if enums have continuous values starting with 1
			size_t nIndex = (size_t)value - 1;
			if ((nIndex >= 0) && (nIndex < nArraySize)) // index within array boundaries?
				if (ckvJsonNamesArray[nIndex].EnumKey == value) // value same as enum key at index entry
					return ckvJsonNamesArray[nIndex].JsonName;

			// non continuous array require linear search
			for (nIndex = 0; nIndex < nArraySize; nIndex++)
				if (ckvJsonNamesArray[nIndex].EnumKey == value)
					return ckvJsonNamesArray[nIndex].JsonName;

			return nullptr;
		}

		static Platform::String^ toString(E value, const EnumKeyJsonName<E> ckvJsonNamesArray[], size_t nArraySize)
		{
			LPCTSTR strValue = c_str(value, ckvJsonNamesArray, nArraySize);
			if (strValue != nullptr)
			{
				return ref new Platform::String(strValue);
			}
			
			return nullptr;
		}

	};

	//public enum class TuTu
	//{
	//	Long = 1,
	//	Short,
	//	Mini
	//};

	//class TutuHelper 
	//{
	//	static const EnumKeyJsonName<CognitiveServicesLib::TuTu> ckvJsonNames[];

	//protected:
	//	static CognitiveServicesLib::TuTu Parse(Platform::String^ strValue);
	//};
}



//const CognitiveServicesLib::EnumKeyJsonName<CognitiveServicesLib::TuTu> CognitiveServicesLib::TutuHelper::ckvJsonNames[] =
//{
//	{ CognitiveServicesLib::TuTu::Long, L"Long" },
//	{ CognitiveServicesLib::TuTu::Short, L"Short" },
//	{ CognitiveServicesLib::TuTu::Mini, L"Mini" },
//};
//
//CognitiveServicesLib::TuTu CognitiveServicesLib::TutuHelper::Parse(Platform::String^ strValue)
//{
//	auto t = sizeof(ckvJsonNames);
//	return(CognitiveServicesLib::EnumHelper<CognitiveServicesLib::TuTu>::parse(strValue, ckvJsonNames, sizeof(ckvJsonNames)));
//};
#endif

