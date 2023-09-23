#include "Countly.h"

#include <Framework/Application/SlateApplication.h>
#include <Modules/ModuleManager.h>

#include "CountlyAnalyticsProvider.h"
#include "CountlyLog.h"
#include "GeneralProjectSettings.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"

#include <countly.hpp>

TSharedPtr<IAnalyticsProvider> FCountlyModule::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const
{
	return AnalyticsProvider;
}

void FCountlyModule::StartupModule()
{
	AnalyticsProvider = MakeShared<FCountlyAnalyticsProvider>();

	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication& Application = FSlateApplication::Get();
		Application.OnPreShutdown().AddRaw(this, &FCountlyModule::OnApplicationShutdown);
	}

	cly::Countly& Countly = cly::Countly::getInstance();
	Countly.setLogger(&OnCppSdkLog);

	//Countly.RecordEvent("MyCustomEvent", 123);
	//Countly.RecordEvent("MyCustomEvent", 17);
	//Countly.RecordEvent("MyCustomEvent", 34);
	//Countly.RecordEvent("AnotherCustomEvent", 644, 13.3);
}

void FCountlyModule::ShutdownModule()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication& Application = FSlateApplication::Get();
		Application.OnPreShutdown().RemoveAll(this);
	}
}

void FCountlyModule::OnApplicationShutdown()
{
	if (AnalyticsProvider.IsValid())
	{
		AnalyticsProvider->EndSession();
	}

	AnalyticsProvider.Reset();
}

IMPLEMENT_MODULE(FCountlyModule, Countly)
