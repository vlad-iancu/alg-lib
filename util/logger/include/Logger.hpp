#ifndef ALG_LIB_LOGGER_LOGGER_H_
#define ALG_LIB_LOGGER_LOGGER_H_

#include <set>
#include <string>
#include <LogEntry.hpp>
#include <LogLevel.hpp>
#include <algorithm>
#include <memory>
#include <formatter/LogFormatter.hpp>

namespace logger
{
    class Logger
    {
    private:
        std::set<Domain> domain_filters;
        std::set<Component> component_filters;
        std::set<logger::LogLevel> level_filters;

    protected:
        virtual void consume_log(LogEntryCPtr entry) = 0;

    public:
        void log(LogEntryCPtr entry);
        void add_component_filter(const Component &filter);
        void add_domain_filter(const Domain &filter);
        void add_level_filter(const logger::LogLevel &filter);
    };

    typedef std::shared_ptr<Logger> LoggerPtr;
} // namespace logger

#endif