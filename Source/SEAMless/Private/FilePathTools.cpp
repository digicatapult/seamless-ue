// Copyright 2023 Digital Catapult


#include "FilePathTools.h" 
#include "HAL/FileManager.h"


void UFilePathTools::ListFoldersInDirectory(FString directory, TArray<FString>& folders)
{ 
    directory = directory + "*";
    IFileManager::Get().FindFiles(folders, *directory, false, true);
}

void UFilePathTools::ListFilesInDirectory(FString directory, FString extension, TArray<FString>& files)
{ 
    IFileManager::Get().FindFiles(files, *directory, *extension);
}
  
bool UFilePathTools::MakeDir(FString directory)
{
    return IFileManager::Get().MakeDirectory(*directory, false);
}

bool UFilePathTools::CopyFile(FString sourceFilePath, FString destFilePath)
{
    return IFileManager::Get().Copy(*destFilePath, *sourceFilePath, false, true) == COPY_OK;
}