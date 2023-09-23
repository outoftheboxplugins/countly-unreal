#include "CountlyLog.h"


#include "countly/logger_module.hpp"

DEFINE_LOG_CATEGORY(LogCountly);

void OnCppSdkLog(cly::LogLevel Level, const std::string& Message)
{
	const FString LogMessage = UTF8_TO_TCHAR(Message.c_str());
	switch (Level)
	{
	case cly::LogLevel::DEBUG:
		UE_LOG(LogCountly, Verbose, TEXT("[CPP-SDK] %s"), *LogMessage);
		break;
	case cly::LogLevel::INFO:
		UE_LOG(LogCountly, Display, TEXT("[CPP-SDK] %s"), *LogMessage);
		break;
	case cly::LogLevel::WARNING:
		UE_LOG(LogCountly, Warning, TEXT("[CPP-SDK] %s"), *LogMessage);
		break;
	case cly::LogLevel::ERROR:
		UE_LOG(LogCountly, Error, TEXT("[CPP-SDK] %s"), *LogMessage);
		break;
	case cly::LogLevel::FATAL:
		UE_LOG(LogCountly, Fatal, TEXT("[CPP-SDK] %s"), *LogMessage);
		break;
	default:
		checkNoEntry();
	}
}