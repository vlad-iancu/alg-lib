#ifndef ALG_LIB_LOGGER_LOG_ENTRY_H_
#define ALG_LIB_LOGGER_LOG_ENTRY_H_

#include <string>
#include <memory>
#include <chrono>

namespace logger
{
    typedef std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> Timestamp;
    typedef std::string Domain;
    typedef std::string Component;

    class LogEntry
    {
    public:
        enum LogLevel
        {
            INFO,
            WARN,
            VERBOSE,
            ERROR,
            PANIC,
        };

    private:
        LogLevel _level;
        Domain _domain;
        Component _component;
        std::string _filename;
        int _line;
        Timestamp _timestamp;

    public:
        LogEntry(
            LogLevel _level,
            std::string _domain,
            std::string _component,
            std::string _filename,
            int _line,
            Timestamp _timestamp = std::chrono::steady_clock::now()) : _level(_level),
                                                                       _domain(_domain),
                                                                       _component(_component),
                                                                       _filename(_filename),
                                                                       _line(_line),
                                                                       _timestamp(_timestamp)
        {
        }
        LogLevel level() const
        {
            return _level;
        }
        std::string domain() const
        {
            return _domain;
        }
        std::string component() const
        {
            return _component;
        }
        std::string filename() const
        {
            return _filename;
        }
        int line() const
        {
            return _line;
        }
    };

    typedef std::shared_ptr<LogEntry> LogEntryPtr;
    typedef std::shared_ptr<const LogEntry> LogEntryCPtr;
} //namespace logger

#endif
