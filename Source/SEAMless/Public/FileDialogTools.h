// Copyright 2023 Digital Catapult

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileDialogTools.generated.h"

/**
 * 
 */
UCLASS()
class SEAMLESS_API UFileDialogTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * Opens file dialog (file picker)
	 *
	 * @param title					The title of the file dialog
	 * @param multiFileSelection	If true this is a mult-file selection 
	 * @param defaultDirectory		The start directory of the dialog
	 * @param fileTypes				Selectable file types Ex: PLY files (*.ply)|*.ply|LAS files (*.las)|*.las
	 * @param selectedFiles			Selected files
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open File Dialog", Keywords = "File,Dialog"), Category = "SEAMless | OpenDialog")
	static void OpenFileDialog
	(
		FString title, 
		bool multiFileSelection,
		FString defaultDirectory, 
		FString fileTypes,	//TEXT("PLY files (*.ply)|*.ply|LAS files (*.las)|*.las"),
		TArray<FString>& selectedFiles
	);

	/**
	 * Opens folder dialog (folder picker)
	 *
	 * @param title					The title of the folder dialog
	 * @param defaultDirectory		The start directory of the dialog 
	 * @param selectedFolder		Selected folder
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open Folder Dialog", Keywords = "Folder,Dialog"), Category = "SEAMless | OpenDialog")
	static void OpenFolderDialog
	(
		FString title,
		FString defaultDirectory, 
		FString& selectedFolder
	);
};
