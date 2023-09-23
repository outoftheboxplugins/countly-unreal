#pragma once

#include <Logging/LogMacros.h>

DECLARE_LOG_CATEGORY_EXTERN(LogCountly, Log, All)

namespace cly
{
	enum class LogLevel;
}

void OnCppSdkLog(cly::LogLevel Level, const std::string &Message);
