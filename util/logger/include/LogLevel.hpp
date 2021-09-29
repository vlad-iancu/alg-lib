#ifndef ALG_LIB_LOGGER_LOG_LEVEL
#define ALG_LIB_LOGGER_LOG_LEVEL

namespace logger
{

    typedef enum LogLevel
    {
        INFO = 0,
        WARN = 1,
        VERBOSE = 2,
        ERROR = 3,
        PANIC = 4,
    } LogLevel;
}

#endif