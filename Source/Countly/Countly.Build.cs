// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Countly : ModuleRules
{
	public Countly(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new[] {
			"Core", 
			"CoreUObject",
			"Analytics",
			"Slate",
			"HTTP",
			"Engine",
			"EngineSettings",
		});
		
		PrivateDependencyModuleNames.AddRange(new [] {
			"CountlyCppSDK", 
		});

		PrivateIncludePaths.Add("ThirdParty/CountlyCppSDK/Include");
	}
}
