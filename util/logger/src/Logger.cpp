#include <Logger.hpp>

namespace logger
{
    void Logger::add_component_filter(const Component &filter)
    {
        component_filters.insert(filter);
    }

    void Logger::add_domain_filter(const Domain &filter)
    {
        domain_filters.insert(filter);
    }

    void Logger::add_level_filter(const LogEntry::LogLevel &filter)
    {
        if (filter > 4 || filter < 0)
            throw invalid_log_level_exception(filter);
        level_filters.insert(filter);
    }

    void Logger::log(LogEntryCPtr entry)
    {
        if (!domain_filters.empty())
            if (
                std::find(
                    domain_filters.begin(),
                    domain_filters.end(),
                    entry->domain()) == domain_filters.end())
            {
                return;
            }
        if (!component_filters.empty())
            if (
                std::find(
                    component_filters.begin(),
                    component_filters.end(),
                    entry->component()) == component_filters.end())
            {
                return;
            }
        if (!level_filters.empty())
            if (
                std::find(
                    level_filters.begin(),
                    level_filters.end(),
                    entry->level()) == level_filters.end())
            {
                return;
            }
        consume_log(entry);
    }
} // namespace logger
