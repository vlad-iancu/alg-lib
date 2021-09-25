#include <ConsoleLogger.hpp>
#include <iostream>

namespace logger
{
    void ConsoleLogger::consume_log(LogEntryCPtr entry)
    {
        std::cout
            << entry->level_str() << " "
            << entry->component() << " "
            << entry->domain() << " "
            << entry->filename() << ":"
            << entry->line();
    }
} // namespace logger
