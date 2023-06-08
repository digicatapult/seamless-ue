// Copyright 2023 Digital Catapult


#include "FileDialogTools.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"

void UFileDialogTools::OpenFileDialog(FString title,bool multiFileSelection, FString defaultDirectory,  FString fileTypes, TArray<FString>& selectedFiles)
{ 
	void* windowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	FDesktopPlatformModule::Get()->OpenFileDialog(windowHandle, title, defaultDirectory, FString(""), fileTypes, multiFileSelection, selectedFiles);
} 

void UFileDialogTools::OpenFolderDialog(FString title, FString defaultDirectory, FString& selectedFolder)
{
	void* windowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle(); 
	FDesktopPlatformModule::Get()->OpenDirectoryDialog(windowHandle, title, defaultDirectory, selectedFolder);
}