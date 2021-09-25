#ifndef ALG_LIB_LOGGER_CONSOLE_LOGGER_H_
#define ALG_LIB_LOGGER_CONSOLE_LOGGER_H_

#include <Logger.hpp>
#include <LogEntry.hpp>

namespace logger
{
    class ConsoleLogger : public Logger
    {
    protected:
        void consume_log(LogEntryCPtr entry);
    };
} // namespace logger

#endif