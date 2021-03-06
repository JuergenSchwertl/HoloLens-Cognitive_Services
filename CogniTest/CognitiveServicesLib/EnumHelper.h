#pragma once
#ifndef DEFINED_ENUMHELPER
#define DEFINED_ENUMHELPER

namespace CognitiveServicesLib
{
	///<summary>
	///EnumKeyJsonName template struct contains E keys and string values
	///</summary>
	template <class E> struct EnumKeyJsonName
	{
		E EnumKey;
		LPCTSTR JsonName;
	};

	///<summary>
	///EnumKeyString template struct contains E keys and string values
	///</summary>
	template <class E> struct EnumKeyString
	{
		E EnumKey;
		LPCTSTR String;
	};

	///<summary>
	///EnumHelper template class to parse and stringify enum class E using enumHelper class ETH
	///that contains a static <seealso cref="EnumKeyJsonName" /> ckvJsonNames list with E keys and string values
	///</summary>
	template<class E, class ETH> class EnumHelper
	{
	public:
		static E parse(Platform::String^ strValue)
		{
			size_t nArraySize = sizeof(ETH::ckvJsonNames) / sizeof(EnumKeyJsonName<E>);

			if (strValue != nullptr)
			{
				LPCTSTR lpszValue = strValue->Data();
				size_t nMaxLength = (size_t)strValue->Length();
				for (size_t nIndex = 0; nIndex < nArraySize; nIndex++)
					if (wcsncmp(lpszValue, ETH::ckvJsonNames[nIndex].JsonName, nMaxLength) == 0)
						return ETH::ckvJsonNames[nIndex].EnumKey;
			}
			return (E)0;
		}

		static Platform::IBox<E>^ parse_nullable(Platform::String^ strValue)
		{
			Platform::Box<CognitiveServicesLib::Glasses>^ boxValue = nullptr;

			if (strValue != nullptr)
			{
				E value = parse(strValue);
				if ((int)value != 0)
				{
					boxValue = ref new Platform::Box<E>(value);
				}
			}
			return(boxValue);
		}

		static LPCTSTR c_str(E value)
		{
			size_t nArraySize = sizeof(ETH::ckvJsonNames) / sizeof(EnumKeyJsonName<E>);

			// quick check if enums have continuous values starting with 1
			size_t nIndex = (size_t)value - 1;
			if ((nIndex >= 0) && (nIndex < nArraySize)) // index within array boundaries?
				if (ETH::ckvJsonNames[nIndex].EnumKey == value) // value same as enum key at index entry
					return ETH::ckvJsonNames[nIndex].JsonName;

			// non continuous array require linear search
			for (nIndex = 0; nIndex < nArraySize; nIndex++)
				if (ETH::ckvJsonNames[nIndex].EnumKey == value)
					return ETH::ckvJsonNames[nIndex].JsonName;

			return Common::Globals::cstrEmptyString;
		}

		static Platform::String^ toString(E value)
		{
			LPCTSTR strValue = c_str(value);
			return ref new Platform::String(strValue);
		}

	};
}



//	public enum class TuTu
//	{
//		Long = 1,
//		Short,
//		Mini
//	};
//
//	class TuTuHelper : EnumHelper<CognitiveServicesLib::TuTu, CognitiveServicesLib::TuTuHelper>
//	{
//	public:
//		static const EnumKeyJsonName<CognitiveServicesLib::TuTu> ckvJsonNames[];
//	};
//}



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

