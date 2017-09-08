#pragma once

#define SUPPORTED_VOICEFONTS 72

namespace CognitiveServicesLib
{

	namespace Speech
	{
		///<summary>
		///supported voice locales and voice fonts 
		///<seealso cref="https://docs.microsoft.com/en-us/azure/cognitive-services/speech/api-reference-rest/bingvoiceoutput#SupLocales" />
		///</summary
		public enum class VoiceFont : int
		{
			AR_EG_Female_Hoda = 0,
			AR_SA_Male_Naayf,
			CA_ES_Female_HerenaRUS,
			CS_CZ_Male_Vit,
			DA_DK_Female_HelleRUS,
			DE_AT_Male_Michael,
			DE_CH_Male_Karsten,
			DE_DE_Female_Hedda,
			DE_DE_Female_HeddaRUS,
			DE_DE_Male_Stefan_Apollo,
			EL_GR_Male_Stefanos,
			EN_AU_Female_Catherine,
			EN_AU_Female_HayleyRUS,
			EN_CA_Female_Linda,
			EN_CA_Female_HeatherRUS,
			EN_GB_Female_Susan_Apollo,
			EN_GB_Female_HazelRUS,
			EN_GB_Male_George_Apollo,
			EN_IE_Male_Shaun,
			EN_IN_Female_Heera_Apollo,
			EN_IN_Female_PriyaRUS,
			EN_IN_Male_Ravi_Apollo,
			EN_US_Female_ZiraRUS,
			EN_US_Female_JessaRUS,
			EN_US_Male_BenjaminRUS,
			ES_ES_Female_Laura_Apollo,
			ES_ES_Female_HelenaRUS,
			ES_ES_Male_Pablo_Apollo,
			ES_MX_Female_HildaRUS,
			ES_MX_Male_Raul_Apollo,
			FI_FI_Female_HeidiRUS,
			FR_CA_Female_Caroline,
			FR_CA_Female_HarmonieRUS,
			FR_CH_Male_Guillaume,
			FR_FR_Female_Julie_Apollo,
			FR_FR_Female_HortenseRUS,
			FR_FR_Male_Paul_Apollo,
			HE_IL_Male_Asaf,
			HI_IN_Female_Kalpana_Apollo,
			HI_IN_Female_Kalpana,
			HI_IN_Male_Hemant,
			HU_HU_Male_Szabolcs,
			ID_ID_Male_Andika,
			IT_IT_Male_Cosimo_Apollo,
			JA_JP_Female_Ayumi_Apollo,
			JA_JP_Male_Ichiro_Apollo,
			JA_JP_Female_HarukaRUS,
			JA_JP_Female_LuciaRUS,
			JA_JP_Male_EkaterinaRUS,
			KO_KR_Female_HeamiRUS,
			NB_NO_Female_HuldaRUS,
			NL_NL_Female_HannaRUS,
			PL_PL_Female_PaulinaRUS,
			PT_BR_Female_HeloisaRUS,
			PT_BR_Male_Daniel_Apollo,
			PT_PT_Female_HeliaRUS,
			RO_RO_Male_Andrei,
			RU_RU_Female_Irina_Apollo,
			RU_RU_Male_Pavel_Apollo,
			SK_SK_Male_Filip,
			SV_SE_Female_HedvigRUS,
			TH_TH_Male_Pattara,
			TR_TR_Female_SedaRUS,
			ZH_CN_Female_HuihuiRUS,
			ZH_CN_Female_Yaoyao_Apollo,
			ZH_CN_Male_Kangkang_Apollo,
			ZH_HK_Female_Tracy_Apollo,
			ZH_HK_Female_TracyRUS,
			ZH_HK_Male_Danny_Apollo,
			ZH_TW_Female_Yating_Apollo,
			ZH_TW_Female_HanHanRUS,
			ZH_TW_Male_Zhiwei_Apollo
		};

		struct VoiceFontMapEntry
		{
			VoiceFont EnumKey;
			LPCTSTR FontName;
			LPCTSTR Language;
			LPCTSTR Gender;
		};


		class VoiceFontHelper
		{
			private:
				static const wchar_t VoiceFontHeader[];
				static const VoiceFontMapEntry VoiceFontMap[SUPPORTED_VOICEFONTS];

			public:
				static Platform::String^ ToString(VoiceFont font);
				static Platform::String^ GetFontName(VoiceFont font);
				static Platform::String^ GetLanguage(VoiceFont font);
				static Platform::String^ GetGender(VoiceFont font);
		};

	}
}
