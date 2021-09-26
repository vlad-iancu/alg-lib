#ifndef ALG_LIB_UTIL_LOG_FORMATTER_H_
#define ALG_LIB_UTIL_LOG_FORMATTER_H_

#include <LogEntry.hpp>
#include <string>
#include <functional>

namespace logger
{
    typedef std::function<std::string(LogEntryCPtr)> LogFormatter;

    std::string default_formatter(LogEntryCPtr entry);
} // namespace logger

#endif