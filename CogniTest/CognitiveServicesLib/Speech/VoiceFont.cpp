#include "pch.h"
#include "VoiceFont.h"

using namespace std;
using namespace Platform;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Speech;

const wchar_t VoiceFontHelper::VoiceFontHeader[] = L"Microsoft Server Speech Text to Speech Voice ";
const VoiceFontMapEntry VoiceFontHelper::VoiceFontMap[SUPPORTED_VOICEFONTS] =
{
{VoiceFont::AR_EG_Female_Hoda,			L"(ar-EG, Hoda)"			,L"ar-EG", L"Female" },
{ VoiceFont::AR_SA_Male_Naayf,			L"(ar-SA, Naayf)"			,L"ar-SA", L"Male" },
{ VoiceFont::CA_ES_Female_HerenaRUS,	L"(ca-ES, HerenaRUS)"		,L"ca-ES", L"Female" },
{ VoiceFont::CS_CZ_Male_Vit,			L"(cs-CZ, Vit)"				,L"cs-CZ", L"Male" },
{ VoiceFont::DA_DK_Female_HelleRUS,		L"(da-DK, HelleRUS)"		,L"da-DK", L"Female" },
{ VoiceFont::DE_AT_Male_Michael,		L"(de-AT, Michael)"			,L"de-AT", L"Male" },
{ VoiceFont::DE_CH_Male_Karsten,		L"(de-CH, Karsten)"			,L"de-CH", L"Male" },
{ VoiceFont::DE_DE_Female_Hedda,		L"(de-DE, Hedda) "			,L"de-DE", L"Female" },
{ VoiceFont::DE_DE_Female_HeddaRUS,		L"(de-DE, HeddaRUS)"		,L"de-DE", L"Female" },
{ VoiceFont::DE_DE_Male_Stefan_Apollo,	L"(de-DE, Stefan, Apollo) "	,L"de-DE", L"Male" },
{ VoiceFont::EL_GR_Male_Stefanos,		L"(el-GR, Stefanos)"		,L"el-GR", L"Male" },
{ VoiceFont::EN_AU_Female_Catherine,	L"(en-AU, Catherine) "		,L"en-AU", L"Female" },
{ VoiceFont::EN_AU_Female_HayleyRUS,	L"(en-AU, HayleyRUS)"		,L"en-AU", L"Female" },
{ VoiceFont::EN_CA_Female_Linda,		L"(en-CA, Linda)"			,L"en-CA", L"Female" },
{ VoiceFont::EN_CA_Female_HeatherRUS,	L"(en-CA, HeatherRUS)"		,L"en-CA", L"Female" },
{ VoiceFont::EN_GB_Female_Susan_Apollo,	L"(en-GB, Susan, Apollo)"	,L"en-GB", L"Female" },
{ VoiceFont::EN_GB_Female_HazelRUS,		L"(en-GB, HazelRUS)"		,L"en-GB", L"Female" },
{ VoiceFont::EN_GB_Male_George_Apollo,	L"(en-GB, George, Apollo)"	,L"en-GB", L"Male" },
{ VoiceFont::EN_IE_Male_Shaun,			L"(en-IE, Shaun)"			,L"en-IE", L"Male" },
{ VoiceFont::EN_IN_Female_Heera_Apollo,	L"(en-IN, Heera, Apollo)"	,L"en-IN", L"Female" },
{ VoiceFont::EN_IN_Female_PriyaRUS,		L"(en-IN, PriyaRUS)"		,L"en-IN", L"Female" },
{ VoiceFont::EN_IN_Male_Ravi_Apollo,	L"(en-IN, Ravi, Apollo) "	,L"en-IN", L"Male" },
{ VoiceFont::EN_US_Female_ZiraRUS,		L"(en-US, ZiraRUS)"			,L"en-US", L"Female" },
{ VoiceFont::EN_US_Female_JessaRUS,		L"(en-US, JessaRUS)"		,L"en-US", L"Female" },
{ VoiceFont::EN_US_Male_BenjaminRUS,	L"(en-US, BenjaminRUS)"		,L"en-US", L"Male" },
{ VoiceFont::ES_ES_Female_Laura_Apollo,	L"(es-ES, Laura, Apollo)"	,L"es-ES", L"Female" },
{ VoiceFont::ES_ES_Female_HelenaRUS,	L"(es-ES, HelenaRUS)"		,L"es-ES", L"Female" },
{ VoiceFont::ES_ES_Male_Pablo_Apollo,	L"(es-ES, Pablo, Apollo)"	,L"es-ES", L"Male" },
{ VoiceFont::ES_MX_Female_HildaRUS,		L"(es-MX, HildaRUS)"		,L"es-MX", L"Female" },
{ VoiceFont::ES_MX_Male_Raul_Apollo,	L"(es-MX, Raul, Apollo)"	,L"es-MX", L"Male" },
{ VoiceFont::FI_FI_Female_HeidiRUS,		L"(fi-FI, HeidiRUS)"		,L"fi-FI", L"Female" },
{ VoiceFont::FR_CA_Female_Caroline,		L"(fr-CA, Caroline)"		,L"fr-CA", L"Female" },
{ VoiceFont::FR_CA_Female_HarmonieRUS,	L"(fr-CA, HarmonieRUS)"		,L"fr-CA", L"Female" },
{ VoiceFont::FR_CH_Male_Guillaume,		L"(fr-CH, Guillaume)"		,L"fr-CH", L"Male" },
{ VoiceFont::FR_FR_Female_Julie_Apollo,	L"(fr-FR, Julie, Apollo)"	,L"fr-FR", L"Female" },
{ VoiceFont::FR_FR_Female_HortenseRUS,	L"(fr-FR, HortenseRUS)"		,L"fr-FR", L"Female" },
{ VoiceFont::FR_FR_Male_Paul_Apollo,	L"(fr-FR, Paul, Apollo)"	,L"fr-FR", L"Male" },
{ VoiceFont::HE_IL_Male_Asaf,			L"(he-IL, Asaf)"			,L"he-IL", L"Male" },
{ VoiceFont::HI_IN_Female_Kalpana_Apollo,L"(hi-IN, Kalpana, Apollo)"	,L"hi-IN", L"Female" },
{ VoiceFont::HI_IN_Female_Kalpana,		L"(hi-IN, Kalpana)"			,L"hi-IN", L"Female" },
{ VoiceFont::HI_IN_Male_Hemant,			L"(hi-IN, Hemant)"			,L"hi-IN", L"Male" },
{ VoiceFont::HU_HU_Male_Szabolcs,		L"(hu-HU, Szabolcs)"		,L"hu-HU", L"Male" },
{ VoiceFont::ID_ID_Male_Andika,			L"(id-ID, Andika)"			,L"id-ID", L"Male" },
{ VoiceFont::IT_IT_Male_Cosimo_Apollo,	L"(it-IT, Cosimo, Apollo)"	,L"it-IT", L"Male" },
{ VoiceFont::JA_JP_Female_Ayumi_Apollo,	L"(ja-JP, Ayumi, Apollo)"	,L"ja-JP", L"Female" },
{ VoiceFont::JA_JP_Male_Ichiro_Apollo,	L"(ja-JP, Ichiro, Apollo)"	,L"ja-JP", L"Male" },
{ VoiceFont::JA_JP_Female_HarukaRUS,	L"(ja-JP, HarukaRUS)"		,L"ja-JP", L"Female" },
{ VoiceFont::JA_JP_Female_LuciaRUS,		L"(ja-JP, LuciaRUS)"		,L"ja-JP", L"Female" },
{ VoiceFont::JA_JP_Male_EkaterinaRUS,	L"(ja-JP, EkaterinaRUS)"	,L"ja-JP", L"Male" },
{ VoiceFont::KO_KR_Female_HeamiRUS,		L"(ko-KR, HeamiRUS)"		,L"ko-KR", L"Female" },
{ VoiceFont::NB_NO_Female_HuldaRUS,		L"(nb-NO, HuldaRUS)"		,L"nb-NO", L"Female" },
{ VoiceFont::NL_NL_Female_HannaRUS,		L"(nl-NL, HannaRUS)"		,L"nl-NL", L"Female" },
{ VoiceFont::PL_PL_Female_PaulinaRUS,	L"(pl-PL, PaulinaRUS)"		,L"pl-PL", L"Female" },
{ VoiceFont::PT_BR_Female_HeloisaRUS,	L"(pt-BR, HeloisaRUS)"		,L"pt-BR", L"Female" },
{ VoiceFont::PT_BR_Male_Daniel_Apollo,	L"(pt-BR, Daniel, Apollo)"	,L"pt-BR", L"Male" },
{ VoiceFont::PT_PT_Female_HeliaRUS,		L"(pt-PT, HeliaRUS)"		,L"pt-PT", L"Female" },
{ VoiceFont::RO_RO_Male_Andrei,			L"(ro-RO, Andrei)"			,L"ro-RO", L"Male" },
{ VoiceFont::RU_RU_Female_Irina_Apollo,	L"(ru-RU, Irina, Apollo)"	,L"ru-RU", L"Female" },
{ VoiceFont::RU_RU_Male_Pavel_Apollo,	L"(ru-RU, Pavel, Apollo)"	,L"ru-RU", L"Male" },
{ VoiceFont::SK_SK_Male_Filip,			L"(sk-SK, Filip)"			,L"sk-SK", L"Male" },
{ VoiceFont::SV_SE_Female_HedvigRUS,	L"(sv-SE, HedvigRUS)"		,L"sv-SE", L"Female" },
{ VoiceFont::TH_TH_Male_Pattara,		L"(th-TH, Pattara)"			,L"th-TH", L"Male" },
{ VoiceFont::TR_TR_Female_SedaRUS,		L"(tr-TR, SedaRUS)"			,L"tr-TR", L"Female" },
{ VoiceFont::ZH_CN_Female_HuihuiRUS,	L"(zh-CN, HuihuiRUS)"		,L"zh-CN", L"Female" },
{ VoiceFont::ZH_CN_Female_Yaoyao_Apollo,L"(zh-CN, Yaoyao, Apollo)"	,L"zh-CN", L"Female" },
{ VoiceFont::ZH_CN_Male_Kangkang_Apollo,L"(zh-CN, Kangkang, Apollo)",L"zh-CN", L"Male" },
{ VoiceFont::ZH_HK_Female_Tracy_Apollo,	L"(zh-HK, Tracy, Apollo)"	,L"zh-HK", L"Female" },
{ VoiceFont::ZH_HK_Female_TracyRUS,		L"(zh-HK, TracyRUS)"		,L"zh-HK", L"Female" },
{ VoiceFont::ZH_HK_Male_Danny_Apollo,	L"(zh-HK, Danny, Apollo)"	,L"zh-HK", L"Male" },
{ VoiceFont::ZH_TW_Female_Yating_Apollo,L"(zh-TW, Yating, Apollo)"	,L"zh-TW", L"Female" },
{ VoiceFont::ZH_TW_Female_HanHanRUS,	L"(zh-TW, HanHanRUS)"		,L"zh-TW", L"Female" },
{ VoiceFont::ZH_TW_Male_Zhiwei_Apollo,	L"(zh-TW, Zhiwei, Apollo)"	,L"zh-TW", L"Male"},
};


Platform::String^ VoiceFontHelper::GetFontName(VoiceFont font)
{
	Platform::String^ strFontName = nullptr;
	if (((int)font >= 0) && ((int)font < SUPPORTED_VOICEFONTS))
	{
		std::wostringstream ssName;
		ssName << VoiceFontHeader << VoiceFontMap[(int)font].FontName;
		strFontName = ref new Platform::String(ssName.str().c_str());
	}
	return strFontName;
}

Platform::String^ VoiceFontHelper::GetLanguage(VoiceFont font)
{
	if (((int)font >= 0) && ((int)font < SUPPORTED_VOICEFONTS))
	{
		return ref new Platform::String(VoiceFontMap[(int)font].Language);
	}
	else
	{
		return nullptr;
	}
}

Platform::String^ VoiceFontHelper::GetGender(VoiceFont font)
{
	if (((int)font >= 0) && ((int)font < SUPPORTED_VOICEFONTS))
	{
		return ref new Platform::String(VoiceFontMap[(int)font].Gender);
	}
	else
	{
		return nullptr;
	}
}

Platform::String^ VoiceFontHelper::ToString(VoiceFont font)
{
	return GetFontName(font);
}

