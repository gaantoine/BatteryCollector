// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BatteryCollector : ModuleRules
{
	public BatteryCollector(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
