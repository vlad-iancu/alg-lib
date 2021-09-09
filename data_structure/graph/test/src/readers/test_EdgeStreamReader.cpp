#include <fstream>

#include <gtest/gtest.h>
#include <readers/EdgeStreamReaderTest.hpp>

#include <edge/iterators/readers.hpp>
#include <edge/Edge.hpp>
#include <graph/types.hpp>

namespace test
{
    TEST_F(EdgeStreamReaderTest, BaseCase)
    {
        std::string path = get_path("BaseCase.txt");
        std::ifstream in(path);
        std::vector<graph::Edge> edges(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end());
        EXPECT_EQ(5, edges.size());

        EXPECT_EQ((edges[0]), graph::Edge(1, 2));
        EXPECT_EQ((edges[1]), graph::Edge(3, 4));
        EXPECT_EQ((edges[2]), graph::Edge(5, 6));
        EXPECT_EQ((edges[3]), graph::Edge(-1, 7));
        EXPECT_EQ((edges[4]), graph::Edge(3, 8));
        in.close();
    }
    TEST_F(EdgeStreamReaderTest, NegativeEdgeCount)
    {
        std::string path = get_path("NegativeCount.txt");
        std::ifstream in(path);
        try
        {
            std::vector<graph::Edge> edges(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end());
            FAIL();
        }
        catch (const std::exception)
        {
            FAIL();
        }
        catch (const graph::invalid_edge_count &e)
        {
            SUCCEED();
        }
        in.close();
    }
    TEST_F(EdgeStreamReaderTest, UnavailableStream)
    {
        try
        {
            std::string path = get_path("BaseCase.txt");
            std::ifstream in(path);
            in.close();
            std::vector<graph::Edge> edges(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end());
            FAIL();
        }
        catch (const graph::edge_stream_eof &e)
        {
            SUCCEED();
        }
        catch(const std::exception &e)
        {
            FAIL();
        }
    }
    TEST_F(EdgeStreamReaderTest, EmptyFile)
    {
        try
        {
            std::string path = get_path("EmptyFile.txt");
            std::ifstream in(path);
            std::vector<graph::Edge> edges(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end());
            FAIL();
        }
        catch (const graph::edge_stream_eof &e)
        {
            SUCCEED();
        }
        catch(const std::exception &e)
        {
            FAIL();
        }
    }
}