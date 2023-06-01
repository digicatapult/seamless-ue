// Copyright 2023 Digital Catapult

using UnrealBuildTool;
using System.Collections.Generic;

public class SEAMlessTarget : TargetRules
{
	public SEAMlessTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "SEAMless" } );
	}
}
