#include "pch.h"
#include "OutputFormat.h"

using namespace Platform;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Speech;

const EnumKeyString<OutputFormat> OutputFormatHelper::OutputFormatMap[8] =
{
	{ OutputFormat::Ssml_16khz_16bit_mono_tts, L"ssml-16khz-16bit-mono-tts" },
	{ OutputFormat::Raw_16khz_16bit_mono_pcm, L"raw-16khz-16bit-mono-pcm" },
	{ OutputFormat::Audio_16khz_16kbps_mono_siren, L"audio-16khz-16kbps-mono-siren" },
	{ OutputFormat::Riff_16khz_16kbps_mono_siren, L"riff-16khz-16kbps-mono-siren" },
	{ OutputFormat::Riff_16khz_16bit_mono_pcm, L"riff-16khz-16bit-mono-pcm" },
	{ OutputFormat::Audio_16khz_128kbitrate_mono_mp3, L"audio-16khz-128kbitrate-mono-mp3" },
	{ OutputFormat::Audio_16khz_64kbitrate_mono_mp3, L"audio-16khz-64kbitrate-mono-mp3" },
	{ OutputFormat::Audio_16khz_32kbitrate_mono_mp3, L"audio-16khz-32kbitrate-mono-mp3" },
};

String ^ OutputFormatHelper::ToString(OutputFormat format)
{
	String^ result = nullptr;
	if ( ((int)format >= 0) && 
		 ((int)format < (sizeof(OutputFormatMap) / sizeof(EnumKeyString<OutputFormat>))))
	{
		result = ref new String(OutputFormatMap[(int)format].String);
	}
	return result;
}
