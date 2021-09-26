#include <sstream>
#include <formatter/LogFormatter.hpp>

namespace logger
{
    std::string default_formatter(LogEntryCPtr entry)
    {
        std::stringstream sstr;
        sstr
            << entry->level_str() << " "
            << entry->component() << " "
            << entry->domain() << " "
            << entry->filename() << ":"
            << entry->line();

        return sstr.str();
    }
} // namespace logger
