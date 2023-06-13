// Copyright 2023 Digital Catapult

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h" 
#include "ProcessPipe.generated.h"

/**
 * Creates a process pipe (to read command line output in engine)
 */
UCLASS(Blueprintable, BlueprintType)
class UProcessPipe : public UObject
{
	GENERATED_BODY()

public: 
	UFUNCTION(BlueprintCallable, Category = "SEAMless | PipeCreator")
	bool StartProcReader();

	UFUNCTION(BlueprintCallable, Category = "SEAMless | PipeCreator")
	void StopProcReader(); 
	 
	UFUNCTION(BlueprintCallable, Category = "SEAMless | PipeCreator")
	bool ReadProcessOutput(FString& output); 

	UFUNCTION(BlueprintPure, Category = "SEAMless | PipeCreator")
	bool IsValid(); 

public:
	void* ReadProcessPipe = nullptr;
	void* WriteProcessPipe = nullptr;

	virtual void BeginDestroy() override; 
}; 