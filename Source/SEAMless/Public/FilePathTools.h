// Copyright 2023 Digital Catapult

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FilePathTools.generated.h"  
//#include "Misc/Paths.h" 

/**
 * Blueprint nodes to help access and manipulate files from directory on Windows
 */
UCLASS()
class SEAMLESS_API UFilePathTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	 * Finds all the folders within the given directory
	 *
	 * @param directory		The absolute path to the directory to search. Ex: "C:\Projects\MyProject\"
	 * @param folders		All the folders found.
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "List Folders in Directory", Keywords = "Folders,Directory"), Category = "SEAMless | ListFoldersInDirectory")
	static void ListFoldersInDirectory
	( 
		FString directory,  
		TArray<FString>& folders
	);

	/**
	 * Finds all the folders within the given directory
	 *
	 * @param directory		The absolute path to the directory to search. Ex: "C:\Projects\MyProject\"
	 * @param extension		Optional extension for files (if empty all files are found). Ex: ".txt"
	 * @param files			All the files found.
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "List Files in Directory", Keywords = "Files,Directory"), Category = "SEAMless | ListFilesInDirectory")
	static void ListFilesInDirectory
	(
		FString directory,
		FString extension,
		TArray<FString>& files
	);

	/**
	 * Makes a new directory
	 *
	 * @param directory		The directory path to make
	 * @return				true if directory is created successfully
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Make Directory", Keywords = "Make,Directory"), Category = "SEAMless | MakeDir")
	static bool MakeDir
	(
		FString directory
	);

	/**
	 * Copies file from a source path to destination path
	 *
	 * @param sourceFilePath	The file source path	
	 * @param destFilePath		The file destination path
	 * @return					true if file was copied successfully
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Copy File", Keywords = "Copy,File"), Category = "SEAMless | CopyFile")
	static bool CopyFile
	(
		FString sourceFilePath,
		FString destFilePath
	);

};
