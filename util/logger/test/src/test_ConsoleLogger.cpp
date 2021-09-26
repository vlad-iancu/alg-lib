#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <LoggerTest.hpp>
#include <ConsoleLogger.hpp>

namespace test
{
    TEST_F(LoggerTest, LoggerBaseCase)
    {
        testing::NiceMock<MockLogger> mock_logger;
        logger::LogEntryCPtr log = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::VERBOSE, "Dom", "MockLogger", "file.cpp", 0);
        EXPECT_CALL(mock_logger, consume_log(log)).Times(3);
        mock_logger.log(log);
        mock_logger.log(log);
        mock_logger.log(log);
    }

    TEST_F(LoggerTest, LoggerDomainFilter)
    {
        testing::NiceMock<MockLogger> mock_logger;
        logger::LogEntryCPtr log1 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::VERBOSE, "Domain1", "MockLogger", "file.cpp", 0);
        logger::LogEntryCPtr log2 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::VERBOSE, "Domain2", "MockLogger", "file.cpp", 0);
        EXPECT_CALL(mock_logger, consume_log(log1)).Times(1);
        EXPECT_CALL(mock_logger, consume_log(log2)).Times(0);
        mock_logger.add_domain_filter("Domain1");
        mock_logger.log(log1);
        mock_logger.log(log2);
    }

    TEST_F(LoggerTest, LoggerComponentFilter)
    {
        testing::NiceMock<MockLogger> mock_logger;
        logger::LogEntryCPtr log1 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::VERBOSE, "Domain1", "MockLogger1", "file.cpp", 0);
        logger::LogEntryCPtr log2 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::VERBOSE, "Domain2", "MockLogger2", "file.cpp", 0);
        EXPECT_CALL(mock_logger, consume_log(log1)).Times(1);
        EXPECT_CALL(mock_logger, consume_log(log2)).Times(0);
        mock_logger.add_component_filter("MockLogger1");
        mock_logger.log(log1);
        mock_logger.log(log2);
    }

    TEST_F(LoggerTest, LoggerValidLevelFilter)
    {
        testing::NiceMock<MockLogger> mock_logger;
        logger::LogEntryCPtr log1 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::WARN, "Domain1", "MockLogger1", "file.cpp", 0);
        logger::LogEntryCPtr log2 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::VERBOSE, "Domain2", "MockLogger2", "file.cpp", 0);
        EXPECT_CALL(mock_logger, consume_log(log1)).Times(1);
        EXPECT_CALL(mock_logger, consume_log(log2)).Times(0);
        mock_logger.add_level_filter(logger::LogEntry::LogLevel::WARN);
        mock_logger.log(log1);
        mock_logger.log(log2);
    }

    TEST_F(LoggerTest, LoggerInvalidLevelFilter)
    {
        testing::NiceMock<MockLogger> mock_logger;
        logger::LogEntryCPtr log1 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::WARN, "Domain1", "MockLogger1", "file.cpp", 0);
        logger::LogEntryCPtr log2 = std::make_shared<logger::LogEntry>(logger::LogEntry::LogLevel::VERBOSE, "Domain2", "MockLogger2", "file.cpp", 0);
        EXPECT_THROW(
            {
                mock_logger.add_level_filter((logger::LogEntry::LogLevel)1000);
            },
            logger::invalid_log_level_exception);
        mock_logger.log(log1);
        mock_logger.log(log2);
    }
}
