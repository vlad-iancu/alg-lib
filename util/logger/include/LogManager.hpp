#ifndef ALG_LIB_LOGGER_LOG_MANAGER_H_
#define ALG_LIB_LOGGER_LOG_MANAGER_H_

#include <Logger.hpp>
#include <LogLevel.hpp>
#include <string>

#define L_INFO logger::INFO
#define L_WARN logger::WARN
#define L_VERBOSE logger::VERBOSE
#define L_ERROR logger::ERROR
#define L_PANIC logger::PANIC

#define LOG_INFO(domain, component, format, ...) log_m(L_INFO, domain, component, __FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define LOG_WARN(domain, component, format, ...) log_m(L_WARN, domain, component, __FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define LOG_VERBOSE(domain, component, format, ...) log_m(L_VERBOSE, domain, component, __FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define LOG_ERROR(domain, component, format, ...) log_m(L_ERROR, domain, component, __FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define LOG_PANIC(domain, component, format, ...) log_m(L_PANIC, domain, component, __FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)

void register_logger(logger::LoggerPtr logger);

void log_m(logger::LogLevel level, const std::string &domain, const std::string &component, const char *file, int line, const std::string &fmt, ...);

#endif