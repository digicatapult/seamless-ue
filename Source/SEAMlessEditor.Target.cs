// Copyright 2023 Digital Catapult

using UnrealBuildTool;
using System.Collections.Generic;

public class SEAMlessEditorTarget : TargetRules
{
	public SEAMlessEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "SEAMless" } );
	}
}
