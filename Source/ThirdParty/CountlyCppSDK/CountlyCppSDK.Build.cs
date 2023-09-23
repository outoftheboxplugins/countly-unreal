// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class CountlyCppSDK : ModuleRules
{
	public CountlyCppSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			if (Target.Architecture == UnrealArch.Arm64)
			{
				//TODO: Change to match other naming convention when GitHub adds arm-64 macos runners
				string Folder = Path.Combine(ModuleDirectory, "Binaries", "Mac", "Arm64");

				PublicDelayLoadDLLs.Add(Path.Combine(Folder, "libcountly.dylib"));
				RuntimeDependencies.Add(Path.Combine(Folder, "libcountly.dylib"));
			}
		}
	}
}
