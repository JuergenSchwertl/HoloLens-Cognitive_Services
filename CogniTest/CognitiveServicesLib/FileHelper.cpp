#include "pch.h"
#include <debugapi.h>
#include "FileHelper.h"

using namespace concurrency;
using namespace CognitiveServicesLib;
using namespace CognitiveServicesLib::Common;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;


task<IRandomAccessStream^> FileHelper::GetInputFileStreamAsync(Platform::String ^ _FileName)
{
	StorageFolder^ cacheFolder = Windows::Storage::ApplicationData::Current->LocalCacheFolder;
	StorageFile^ storagefile = co_await cacheFolder->GetFileAsync("test");
	IRandomAccessStream^ fileStream = co_await storagefile->OpenAsync(FileAccessMode::Read);
	co_return fileStream;
}

task<IRandomAccessStream^> FileHelper::GetInputFileStreamAsync(Uri ^ _Uri)
{
	String^ str = _Uri->ToString();
	OutputDebugStringW(str->Data);

	StorageFile^ storagefile = co_await StorageFile::GetFileFromApplicationUriAsync( _Uri );
	IRandomAccessStream^ fileStream = co_await storagefile->OpenAsync(FileAccessMode::Read);
	co_return fileStream;
}


task<IRandomAccessStream^> FileHelper::GetOutputFileStreamAsync(String ^ _FileName)
{
	OutputDebugStringW(_FileName->Data);
	
	StorageFolder^ cacheFolder = Windows::Storage::ApplicationData::Current->LocalCacheFolder;
	StorageFile^ storagefile = co_await cacheFolder->CreateFileAsync("test");
	IRandomAccessStream^ fileStream = co_await storagefile->OpenAsync(FileAccessMode::ReadWrite);
	co_return fileStream;
}