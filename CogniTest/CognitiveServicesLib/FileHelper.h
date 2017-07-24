#pragma once

#ifndef FileHelper_DEFINED
#define FileHelper_DEFINED

namespace CognitiveServicesLib
{
	class FileHelper
	{
	public:
		static Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> GetInputFileStreamAsync(Platform::String^ _FileName);
		static Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> GetInputFileStreamAsync(Windows::Foundation::Uri^ _Uri);
		static Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> GetOutputFileStreamAsync(Platform::String^ _FileName);

	};

}
#endif