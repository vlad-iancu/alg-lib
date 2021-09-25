#include <gtest/gtest.h>
#include <ConsoleLogger.hpp>
#include <LogEntry.hpp>
#include <gmock/gmock.h>

namespace test
{
    class LoggerTest : public ::testing::Test
    {
    protected:
        class MockLogger : public logger::ConsoleLogger
        {
        public:
            MOCK_METHOD(void, consume_log, (logger::LogEntryCPtr), (override));
        };
    };

} //namespace test
