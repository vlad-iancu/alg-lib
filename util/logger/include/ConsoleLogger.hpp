#ifndef ALG_LIB_LOGGER_CONSOLE_LOGGER_H_
#define ALG_LIB_LOGGER_CONSOLE_LOGGER_H_

#include <Logger.hpp>
#include <LogEntry.hpp>

namespace logger
{
    class ConsoleLogger : public Logger
    {
    private:
        LogFormatter formatter;
    protected:
        void consume_log(LogEntryCPtr entry);
    public:
        explicit ConsoleLogger(LogFormatter formatter = default_formatter);
    };
} // namespace logger

#endif