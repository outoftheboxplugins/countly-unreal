#pragma once

#include <Interfaces/IAnalyticsProvider.h>

#include "countly.hpp"

class FCountlyAnalyticsProvider : public IAnalyticsProvider
{
public:
	FCountlyAnalyticsProvider();

private:
	// Being IAnalyticsProvider Interface
	virtual bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;
	virtual void EndSession() override;
	virtual bool SetSessionID(const FString& InSessionID) override;
	virtual FString GetSessionID() const override;
	virtual void FlushEvents() override;
	virtual void SetUserID(const FString& InUserID) override;
	virtual FString GetUserID() const override;
	virtual void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;
	// End IAnalyticsProvider Interface

	FString UserId = TEXT("");

	FString SessionId = TEXT("");

	cly::Countly& Countly;
};
