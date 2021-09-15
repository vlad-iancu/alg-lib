#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <graphs/GraphTest.hpp>
#include <graph/AdjacencyMatrix.hpp>

namespace test
{

    typedef GraphTest<graph::AdjacencyMatrix> AdjacencyMatrixGraphTest;
    TEST_F(AdjacencyMatrixGraphTest, GetBaseCase)
    {
        std::shared_ptr<graph::AdjacencyMatrix> graph = std::make_shared<graph::AdjacencyMatrix>(5);
        graph->set(0, 1, 1);
        EXPECT_EQ(1, graph->get(0, 1));
    }
    TEST_F(AdjacencyMatrixGraphTest, GetNegativeNode)
    {
        std::shared_ptr<graph::AdjacencyMatrix> graph = std::make_shared<graph::AdjacencyMatrix>(5);
        graph->set(0, 1, 1);
        EXPECT_THROW(
            {
                graph->get(0, -1);
            },
            graph::invalid_node);
    }
    TEST_F(AdjacencyMatrixGraphTest, GetOverflowNode)
    {
        std::shared_ptr<graph::AdjacencyMatrix> graph = std::make_shared<graph::AdjacencyMatrix>(5);
        graph->set(0, 1, 1);
        EXPECT_THROW(
            {
                graph->get(0, 5);
            },
            graph::invalid_node);
    }
    TEST_F(AdjacencyMatrixGraphTest, SetBaseCase)
    {
        std::shared_ptr<graph::AdjacencyMatrix> graph = std::make_shared<graph::AdjacencyMatrix>(5);
        graph->set(0, 1, 1);
        EXPECT_EQ(1, graph->get(0, 1));
    }
    TEST_F(AdjacencyMatrixGraphTest, SetNegativeNode)
    {
        std::shared_ptr<graph::AdjacencyMatrix> graph = std::make_shared<graph::AdjacencyMatrix>(5);
        EXPECT_THROW(
            {
                graph->set(-1, 0, 3);
            },
            graph::invalid_node
        );
    }
    TEST_F(AdjacencyMatrixGraphTest, SetOverflowNode)
    {
        std::shared_ptr<graph::AdjacencyMatrix> graph = std::make_shared<graph::AdjacencyMatrix>(5);
        EXPECT_THROW(
            {
                graph->set(5, 0, 3);
            },
            graph::invalid_node
        );
    }

}
