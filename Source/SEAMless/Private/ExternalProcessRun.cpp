// Copyright 2023 Digital Catapult


#include "ExternalProcessRun.h"

void UExternalProcessRun::RunProcess(FString batPath, TArray<FString> args, int32& id, UProcessPipe* pipe) // priority: 2 fastest, -2 slowest
{
	if (pipe) pipe->StartProcReader(); 

	FString combinedArgs = "";
	for (int32 i = 0; i < args.Num(); i++)
	{
		if (i != 0) combinedArgs = combinedArgs + " ";
		combinedArgs = combinedArgs + args[i];
	}
	uint32 uintid = 0;
	FPlatformProcess::CreateProc(*batPath, *combinedArgs, false, true, true, &uintid, 2, nullptr, (pipe && pipe->IsValid()) ? pipe->WriteProcessPipe : nullptr);
	id = uintid;
}