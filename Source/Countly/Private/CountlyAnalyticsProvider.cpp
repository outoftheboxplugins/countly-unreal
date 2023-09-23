
#include "CountlyAnalyticsProvider.h"


#include "GeneralProjectSettings.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"

FCountlyAnalyticsProvider::FCountlyAnalyticsProvider() :
	Countly(cly::Countly::getInstance()) 
{
}

bool FCountlyAnalyticsProvider::StartSession(const TArray<FAnalyticsEventAttribute>& Attributes)
{
	if(UserId.IsEmpty())
	{
		SetUserID(FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower));	
	}

	const std::string Os = TCHAR_TO_UTF8(*UGameplayStatics::GetPlatformName());
	const std::string OsVersion = TCHAR_TO_UTF8(*FPlatformMisc::GetOSVersion());
	const std::string Device = TCHAR_TO_UTF8(*FGenericPlatformMisc::GetDeviceMakeAndModel());

	const FIntPoint Res = GEngine->GetGameUserSettings()->GetDesktopResolution();
	const std::string Resolution = TCHAR_TO_UTF8(*Res.ToString());
	const std::string Carrier = "TODO";
	const std::string AppVersion = TCHAR_TO_UTF8(*GetDefault<UGeneralProjectSettings>()->ProjectVersion);
	Countly.SetMetrics(Os, OsVersion, Device, Resolution, Carrier, AppVersion);

	const FString GenericDeviceId = UserId;
	const std::string DeviceId = TCHAR_TO_UTF8(*GenericDeviceId);
	Countly.setDeviceID(DeviceId);

	//TODO: Extract AppKey, Host and port and minUpdatePeriod (interval) to config
	Countly.Start("704628f8ea2a067f53c7876d4ad5093bd8eeac02", "http://192.168.1.183", 80);
	Countly.SetMinUpdatePeriod(2000);
	return true;
}

void FCountlyAnalyticsProvider::EndSession()
{
	Countly.Stop();
}

bool FCountlyAnalyticsProvider::SetSessionID(const FString& InSessionID)
{
	SessionId = InSessionID;

	//TODO: Set it on the singleton instance too.
	return true;
}

FString FCountlyAnalyticsProvider::GetSessionID() const
{
	return SessionId;
}

void FCountlyAnalyticsProvider::FlushEvents()
{
}

void FCountlyAnalyticsProvider::SetUserID(const FString& InUserID)
{
	UserId = InUserID;

	//TODO: Set it on the singleton instance too.
}

FString FCountlyAnalyticsProvider::GetUserID() const
{
	return UserId;
}

void FCountlyAnalyticsProvider::RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes)
{
	Countly.RecordEvent("Test", 1);
}