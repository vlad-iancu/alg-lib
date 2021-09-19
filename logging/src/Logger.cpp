#include <logger/Logger.hpp>

namespace logger
{
    void Logger::add_component_filter(const Component &filter)
    {
    }

    void Logger::add_domain_filter(const Domain &filter)
    {
    }

    void Logger::log(LogEntryCPtr entry)
    {
        if (domain_filters.size())
            if (
                std::find(
                    domain_filters.begin(),
                    domain_filters.end(),
                    entry->domain()) == domain_filters.end())
            {
                return;
            }
        if (component_filters.size())
            if (
                std::find(
                    component_filters.begin(),
                    component_filters.end(),
                    entry->component()) == component_filters.end())
            {
                return;
            }
        consume_log(entry);
    }
} // namespace logger
