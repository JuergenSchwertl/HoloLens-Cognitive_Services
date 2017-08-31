#include "pch.h"
#include "VoiceFont.h"

using namespace std;
using namespace Platform;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Speech;

const wchar_t VoiceFontHelper::VoiceFontHeader[] = L"Microsoft Server Speech Text to Speech Voice ";
const EnumKeyString<CognitiveServicesLib::Speech::VoiceFont> VoiceFontHelper::VoiceFontMap[72] =
{
	{VoiceFont::AR_EG_Female_Hoda,			L"(ar-EG, Hoda)"				   },
	{VoiceFont::AR_SA_Male_Naayf,			L"(ar-SA, Naayf)"				   },
	{VoiceFont::CA_ES_Female_HerenaRUS,		L"(ca-ES, HerenaRUS)"			   },
	{VoiceFont::CS_CZ_Male_Vit,				L"(cs-CZ, Vit)"					   },
	{VoiceFont::DA_DK_Female_HelleRUS,		L"(da-DK, HelleRUS)"				   },
	{VoiceFont::DE_AT_Male_Michael,			L"(de-AT, Michael)"				   },
	{VoiceFont::DE_CH_Male_Karsten,			L"(de-CH, Karsten)"				   },
	{VoiceFont::DE_DE_Female_Hedda,			L"(de-DE, Hedda) "				   },
	{VoiceFont::DE_DE_Female_HeddaRUS,		L"(de-DE, HeddaRUS)"				   },
	{VoiceFont::DE_DE_Male_Stefan_Apollo,	L"(de-DE, Stefan, Apollo) "		   },
	{VoiceFont::EL_GR_Male_Stefanos,		L"(el-GR, Stefanos)"				   },
	{VoiceFont::EN_AU_Female_Catherine,		L"(en-AU, Catherine) "			   },
	{VoiceFont::EN_AU_Female_HayleyRUS,		L"(en-AU, HayleyRUS)"			   },
	{VoiceFont::EN_CA_Female_Linda,			L"(en-CA, Linda)"				   },
	{VoiceFont::EN_CA_Female_HeatherRUS,	L"(en-CA, HeatherRUS)"			   },
	{VoiceFont::EN_GB_Female_Susan_Apollo,	L"(en-GB, Susan, Apollo)"		   },
	{VoiceFont::EN_GB_Female_HazelRUS,		L"(en-GB, HazelRUS)"				   },
	{VoiceFont::EN_GB_Male_George_Apollo,	L"(en-GB, George, Apollo)"		   },
	{VoiceFont::EN_IE_Male_Shaun,			L"(en-IE, Shaun)"				   },
	{VoiceFont::EN_IN_Female_Heera_Apollo,	L"(en-IN, Heera, Apollo)"		   },
	{VoiceFont::EN_IN_Female_PriyaRUS,		L"(en-IN, PriyaRUS)"				   },
	{VoiceFont::EN_IN_Male_Ravi_Apollo,		L"(en-IN, Ravi, Apollo) "		   },
	{VoiceFont::EN_US_Female_ZiraRUS,		L"(en-US, ZiraRUS)"				   },
	{VoiceFont::EN_US_Female_JessaRUS,		L"(en-US, JessaRUS)"				   },
	{VoiceFont::EN_US_Male_BenjaminRUS,		L"(en-US, BenjaminRUS)"			   },
	{VoiceFont::ES_ES_Female_Laura_Apollo,	L"(es-ES, Laura, Apollo)"		   },
	{VoiceFont::ES_ES_Female_HelenaRUS,		L"(es-ES, HelenaRUS)"			   },
	{VoiceFont::ES_ES_Male_Pablo_Apollo,	L"(es-ES, Pablo, Apollo)"		   },
	{VoiceFont::ES_MX_Female_HildaRUS,		L"(es-MX, HildaRUS)"				   },
	{VoiceFont::ES_MX_Male_Raul_Apollo,		L"(es-MX, Raul, Apollo)"			   },
	{VoiceFont::FI_FI_Female_HeidiRUS,		L"(fi-FI, HeidiRUS)"				   },
	{VoiceFont::FR_CA_Female_Caroline,		L"(fr-CA, Caroline)"				   },
	{VoiceFont::FR_CA_Female_HarmonieRUS,	L"(fr-CA, HarmonieRUS)"			   },
	{VoiceFont::FR_CH_Male_Guillaume,		L"(fr-CH, Guillaume)"			   },
	{VoiceFont::FR_FR_Female_Julie_Apollo,	L"(fr-FR, Julie, Apollo)"		   },
	{VoiceFont::FR_FR_Female_HortenseRUS,	L"(fr-FR, HortenseRUS)"			   },
	{VoiceFont::FR_FR_Male_Paul_Apollo,		L"(fr-FR, Paul, Apollo)"			   },
	{VoiceFont::HE_IL_Male_Asaf,			L"(he-IL, Asaf)"					   },
	{VoiceFont::HI_IN_Female_Kalpana_Apollo,L"(hi-IN, Kalpana, Apollo)"		   },
	{VoiceFont::HI_IN_Female_Kalpana,		L"(hi-IN, Kalpana)"				   },
	{VoiceFont::HI_IN_Male_Hemant,			L"(hi-IN, Hemant)"				   },
	{VoiceFont::HU_HU_Male_Szabolcs,		L"(hu-HU, Szabolcs)"				   },
	{VoiceFont::ID_ID_Male_Andika,			L"(id-ID, Andika)"				   },
	{VoiceFont::IT_IT_Male_Cosimo_Apollo,	L"(it-IT, Cosimo, Apollo)"		   },
	{VoiceFont::JA_JP_Female_Ayumi_Apollo,	L"(ja-JP, Ayumi, Apollo)"		   },
	{VoiceFont::JA_JP_Male_Ichiro_Apollo,	L"(ja-JP, Ichiro, Apollo)"		   },
	{VoiceFont::JA_JP_Female_HarukaRUS,		L"(ja-JP, HarukaRUS)"			   },
	{VoiceFont::JA_JP_Female_LuciaRUS,		L"(ja-JP, LuciaRUS)"				   },
	{VoiceFont::JA_JP_Male_EkaterinaRUS,	L"(ja-JP, EkaterinaRUS)"			   },
	{VoiceFont::KO_KR_Female_HeamiRUS,		L"(ko-KR, HeamiRUS)"				   },
	{VoiceFont::NB_NO_Female_HuldaRUS,		L"(nb-NO, HuldaRUS)"				   },
	{VoiceFont::NL_NL_Female_HannaRUS,		L"(nl-NL, HannaRUS)"				   },
	{VoiceFont::PL_PL_Female_PaulinaRUS,	L"(pl-PL, PaulinaRUS)"			   },
	{VoiceFont::PT_BR_Female_HeloisaRUS,	L"(pt-BR, HeloisaRUS)"			   },
	{VoiceFont::PT_BR_Male_Daniel_Apollo,	L"(pt-BR, Daniel, Apollo)"		   },
	{VoiceFont::PT_PT_Female_HeliaRUS,		L"(pt-PT, HeliaRUS)"				   },
	{VoiceFont::RO_RO_Male_Andrei,			L"(ro-RO, Andrei)"				   },
	{VoiceFont::RU_RU_Female_Irina_Apollo,	L"(ru-RU, Irina, Apollo)"		   },
	{VoiceFont::RU_RU_Male_Pavel_Apollo,	L"(ru-RU, Pavel, Apollo)"		   },
	{VoiceFont::SK_SK_Male_Filip,			L"(sk-SK, Filip)"				   },
	{VoiceFont::SV_SE_Female_HedvigRUS,		L"(sv-SE, HedvigRUS)"			   },
	{VoiceFont::TH_TH_Male_Pattara,			L"(th-TH, Pattara)"				   },
	{VoiceFont::TR_TR_Female_SedaRUS,		L"(tr-TR, SedaRUS)"				   },
	{VoiceFont::ZH_CN_Female_HuihuiRUS,		L"(zh-CN, HuihuiRUS)"			   },
	{VoiceFont::ZH_CN_Female_Yaoyao_Apollo,	L"(zh-CN, Yaoyao, Apollo)"		   },
	{VoiceFont::ZH_CN_Male_Kangkang_Apollo,	L"(zh-CN, Kangkang, Apollo)"		   },
	{VoiceFont::ZH_HK_Female_Tracy_Apollo,	L"(zh-HK, Tracy, Apollo)"		   },
	{VoiceFont::ZH_HK_Female_TracyRUS,		L"(zh-HK, TracyRUS)"				   },
	{VoiceFont::ZH_HK_Male_Danny_Apollo,	L"(zh-HK, Danny, Apollo)"		   },
	{VoiceFont::ZH_TW_Female_Yating_Apollo,	L"(zh-TW, Yating, Apollo)"		   },
	{VoiceFont::ZH_TW_Female_HanHanRUS,		L"(zh-TW, HanHanRUS)"			   },
	{VoiceFont::ZH_TW_Male_Zhiwei_Apollo,	L"(zh-TW, Zhiwei, Apollo)"		   },
};

Platform::String^ VoiceFontHelper::ToString(VoiceFont font)
{
	Platform::String^ strFontName = nullptr;
	if ( ((int)font >= 0) && 
		 ((int)font < (sizeof(VoiceFontMap) / sizeof(EnumKeyString<VoiceFont>))))
	{
		std::wostringstream ssName;
		ssName << VoiceFontHeader << VoiceFontMap[(int)font].String;
		strFontName = ref new Platform::String(ssName.str().c_str());
	}
	return strFontName;
}

