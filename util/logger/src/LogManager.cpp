#include <LogManager.hpp>

#include <iostream>
#include <vector>
#include <cstdarg>
#include <chrono>

void log_m(logger::LogLevel level, const std::string &domain, const std::string &component, const char *file, int line, const std::string &fmt, ...)
{

    va_list args1;
    va_list args2;
    va_copy(args2, args1);
    va_start(args1, fmt);
    int size = vsprintf(nullptr, fmt.c_str(), args1);
    va_end(args1);

    char msg[size];
    va_start(args2, fmt);
    vsprintf(msg, fmt.c_str(), args2);
    va_end(args2);

    logger::LogEntry entry(
        level, domain, component, std::string(file), line, msg, std::chrono::steady_clock::now()
    );
    
}
