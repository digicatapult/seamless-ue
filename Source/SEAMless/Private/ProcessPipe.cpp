// Copyright 2023 Digital Catapult


#include "ProcessPipe.h"


bool UProcessPipe::StartProcReader()
{
	if (IsValid()) return true;
	return FPlatformProcess::CreatePipe(ReadProcessPipe, WriteProcessPipe);
}
void UProcessPipe::StopProcReader()
{
	if (IsValid())
	{
		FPlatformProcess::ClosePipe(ReadProcessPipe, WriteProcessPipe);
		ReadProcessPipe = nullptr;
		WriteProcessPipe = nullptr;
	}
}
bool UProcessPipe::ReadProcessOutput(FString& PipeContents)
{
	PipeContents = "";

	if (!IsValid()) return false;
	PipeContents = FPlatformProcess::ReadPipe(ReadProcessPipe);
	return true;
}
bool UProcessPipe::IsValid()
{
	return ReadProcessPipe != nullptr && WriteProcessPipe != nullptr;
}

void UProcessPipe::BeginDestroy()
{
	Super::BeginDestroy();
	StopProcReader();
}
