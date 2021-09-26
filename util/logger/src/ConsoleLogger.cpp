#include <ConsoleLogger.hpp>
#include <iostream>

namespace logger
{
    ConsoleLogger::ConsoleLogger(LogFormatter formatter): formatter(formatter) {

    }
    void ConsoleLogger::consume_log(LogEntryCPtr entry)
    {
        std::cout << formatter(entry) << std::endl;
    }
} // namespace logger
