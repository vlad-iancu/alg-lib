#ifndef ALG_LIB_LOGGER_LOGGER_H_
#define ALG_LIB_LOGGER_LOGGER_H_

#include <set>
#include <string>
#include <logger/LogEntry.hpp>
#include <algorithm>

namespace logger
{
    class Logger
    {
    private:
        std::set<Domain> domain_filters;
        std::set<Component> component_filters;

    protected:
        virtual void consume_log(LogEntryCPtr entry) = 0;

    public:
        void log(LogEntryCPtr entry)
        ;
        void add_component_filter(const std::string &filter);
        void add_domain_filter(const std::string &filter);
    };
} // namespace logger

#endif