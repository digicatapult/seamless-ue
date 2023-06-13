// Copyright 2023 Digital Catapult

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProcessPipe.h"
#include "ExternalProcessRun.generated.h"

/**
 * Runs an external application (.exe or .bat)
 */
UCLASS()
class SEAMLESS_API UExternalProcessRun : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	 * Trigger .bat files
	 *
	 * @param batPath		Path to bat file
	 * @param args			Arguments to call the bat file with
	 * @param out id		Id of the process (used for tracking if it's still running)
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Run process", Keywords = "run,pricess,bat,exe"), Category = "SEAMless | ExternalRun")
	static void RunProcess
	(
		FString batPath,
		TArray<FString> args,
		int32& id, 
		UProcessPipe* pipe = nullptr
	);

	/**
	 * Checks if a process is running
	 *
	 * @param id		The process id
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Process Running", Keywords = "process,running"), Category = "SEAMless | ExternalRun")
	static bool IsProcessRunning(int32 id)
	{
		return FPlatformProcess::IsApplicationRunning(id);
	} 
};
