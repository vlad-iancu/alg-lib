#ifndef ALG_LIB_LOGGER_LOG_ENTRY_H_
#define ALG_LIB_LOGGER_LOG_ENTRY_H_

#include <string>
#include <memory>
#include <chrono>
#include <sstream>
#include <LogLevel.hpp>

namespace logger
{
    typedef std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> Timestamp;
    typedef std::string Domain;
    typedef std::string Component;
    
    class invalid_log_level_exception : public std::exception
    {
    private:
        int level;

    public:
        invalid_log_level_exception(int level) : level(level) {}
        virtual const char *what() const noexcept
        {
            std::stringstream sstr;
            sstr << "Invalid log level: " << level;
            return sstr.str().c_str();
        }
    };
    class LogEntry
    {
    private:
        LogLevel _level;
        Domain _domain;
        Component _component;
        std::string _filename;
        int _line;
        Timestamp _timestamp;
        std::string _message;
        static std::string level_names[5];

    public:
        LogEntry(
            LogLevel _level,
            std::string _domain,
            std::string _component,
            std::string _filename,
            int _line,
            const std::string &_message,
            Timestamp _timestamp = std::chrono::steady_clock::now()) : _level(_level),
                                                                       _domain(_domain),
                                                                       _component(_component),
                                                                       _filename(_filename),
                                                                       _line(_line),
                                                                       _timestamp(_timestamp),
                                                                       _message(_message)
        {
        }

        LogLevel level() const;

        Domain domain() const;

        Component component() const;

        std::string filename() const;

        int line() const;

        std::string level_str() const;

        std::string message() const;
    };

    typedef std::shared_ptr<LogEntry> LogEntryPtr;
    typedef std::shared_ptr<const LogEntry> LogEntryCPtr;
} //namespace logger

#endif
