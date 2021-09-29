#include <LogEntry.hpp>

namespace logger
{
    LogLevel LogEntry::level() const
    {
        return _level;
    }

    Domain LogEntry::domain() const
    {
        return _domain;
    }

    Component LogEntry::component() const
    {
        return _component;
    }

    std::string LogEntry::filename() const
    {
        return _filename;
    }

    int LogEntry::line() const
    {
        return _line;
    }

    std::string LogEntry::level_str() const
    {
        if (_level > 4 || _level < 0)
            throw invalid_log_level_exception(_level);
        return level_names[_level];
    }

    std::string LogEntry::message() const
    {
        return _message;
    }

    std::string LogEntry::level_names[5]{"INFO", "WARN", "VERBOSE", "ERROR", "PANIC"};
} // namespace logger
