#pragma once
namespace CognitiveServicesLib
{
	namespace Speech
	{
		public enum class OutputFormat : int
		{
			Ssml_16khz_16bit_mono_tts = 0,
			Raw_16khz_16bit_mono_pcm,
			Audio_16khz_16kbps_mono_siren,
			Riff_16khz_16kbps_mono_siren,
			Riff_16khz_16bit_mono_pcm,
			Audio_16khz_128kbitrate_mono_mp3,
			Audio_16khz_64kbitrate_mono_mp3,
			Audio_16khz_32kbitrate_mono_mp3
		};

		class OutputFormatHelper
		{
		private:
			static const EnumKeyString<CognitiveServicesLib::Speech::OutputFormat> OutputFormatMap[8];
		public:
			static Platform::String^ ToString(OutputFormat format);
		};

	}
}
