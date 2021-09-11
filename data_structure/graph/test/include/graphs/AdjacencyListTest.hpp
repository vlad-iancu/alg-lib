#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_TEST_EDGE_STREAM_READER_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_TEST_EDGE_STREAM_READER_H_

#include <filesystem>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

namespace test
{
    namespace fs = std::filesystem;

    class AdjacencyListTest : public testing::Test
    {
    protected:
        std::string get_path(const std::string& name)
        {
            auto baseDir = fs::current_path();
            auto parentDir = fs::current_path().parent_path();
            while (baseDir.has_parent_path())
            {
                if (fs::exists(baseDir.append("tests")))
                {
                    return baseDir.append("graphs").append(name);
                }
                baseDir = parentDir;
                parentDir = baseDir.parent_path(); //Apparently I can't assign baseDir to baseDir.parent_path() directly
            }
            throw std::invalid_argument("File not found");
        }
    };
} //namespace test

#endif