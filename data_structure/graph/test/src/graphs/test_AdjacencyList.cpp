#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <graphs/AdjacencyListTest.hpp>

#include <fstream>

#include <graph/AdjacencyList.hpp>

#include <edge/iterators/readers.hpp>
#include <edge/iterators/writers.hpp>

namespace test
{
TEST_F(AdjacencyListTest, BaseCase)
{
    std::ifstream in(get_path("BaseCase.txt"));
    graph::SizeG n;
    in >> n;

    graph::GraphPtr adjacencyList = std::make_shared<graph::AdjacencyList>(n);
    std::copy(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end(), graph::edge_inserter(adjacencyList));

    EXPECT_EQ(3, adjacencyList->get_neighbors(0).size());
    EXPECT_TRUE(adjacencyList->has_edge(0, 2));
    EXPECT_TRUE(adjacencyList->has_edge(0, 4));
    EXPECT_TRUE(adjacencyList->has_edge(0, 5));

    EXPECT_EQ(2, adjacencyList->get_neighbors(1).size());
    EXPECT_TRUE(adjacencyList->has_edge(1, 5));
    EXPECT_TRUE(adjacencyList->has_edge(1, 4));

    EXPECT_EQ(2, adjacencyList->get_neighbors(2).size());
    EXPECT_TRUE(adjacencyList->has_edge(2, 3));
    EXPECT_TRUE(adjacencyList->has_edge(2, 4));

    EXPECT_EQ(1, adjacencyList->get_neighbors(3).size());
    EXPECT_TRUE(adjacencyList->has_edge(3, 6));

    EXPECT_EQ(1, adjacencyList->get_neighbors(4).size());
    EXPECT_TRUE(adjacencyList->has_edge(4, 5));

    EXPECT_EQ(0, adjacencyList->get_neighbors(5).size());

    EXPECT_EQ(0, adjacencyList->get_neighbors(6).size());

    EXPECT_EQ(2, adjacencyList->get_neighbors(7).size());
    EXPECT_TRUE(adjacencyList->has_edge(7, 1));
    EXPECT_TRUE(adjacencyList->has_edge(7, 6));

    in.close();
}

TEST_F(AdjacencyListTest, EmptyGraph)
{
    std::ifstream in(get_path("ZeroNode.txt"));
    graph::SizeG n;
    in >> n;
    EXPECT_THROW(
    {
        graph::GraphPtr G = std::make_shared<graph::AdjacencyList>(n);
    },
    graph::invalid_size);
}

TEST_F(AdjacencyListTest, AddEdgeBaseCase)
{
    graph::GraphPtr G = std::make_shared<graph::AdjacencyList>(2);
    G->add_edge(0, 1);
    G->add_edge(1, 0);
    EXPECT_TRUE(G->has_edge(0, 1));
    EXPECT_TRUE(G->has_edge(1, 0));
    EXPECT_EQ(1, G->get_neighbors(1).size());
    EXPECT_EQ(1, G->get_neighbors(0).size());
}

TEST_F(AdjacencyListTest, AddEdgeNegativeNode)
{
    EXPECT_THROW({

        graph::GraphPtr G = std::make_shared<graph::AdjacencyList>(2);
        G->add_edge(0, -1);
        G->add_edge(1, 0);
        EXPECT_TRUE(G->has_edge(0, 1));
        EXPECT_TRUE(G->has_edge(1, 0));
        EXPECT_EQ(1, G->get_neighbors(1).size());
        EXPECT_EQ(1, G->get_neighbors(0).size());
    }, graph::invalid_node);
}

TEST_F(AdjacencyListTest, AddEdgeNodeOverflow)
{
    EXPECT_THROW
    (
    {
        graph::GraphPtr G = std::make_shared<graph::AdjacencyList>(2);
        G->add_edge(2, 1);
    },
    graph::invalid_node
    );
}

TEST_F(AdjacencyListTest, HasExistingEdge)
{
    graph::GraphPtr graph = std::make_shared<graph::AdjacencyList>(2);
    graph->add_edge(0, 1);
    EXPECT_TRUE(graph->has_edge(0, 1));
}

TEST_F(AdjacencyListTest, HasNonExistingEdge)
{
    graph::GraphPtr graph = std::make_shared<graph::AdjacencyList>(2);
    graph->add_edge(0, 1);
    EXPECT_FALSE(graph->has_edge(1, 0));
}

TEST_F(AdjacencyListTest, RemoveExistingEdge)
{
    graph::GraphPtr graph = std::make_shared<graph::AdjacencyList>(2);
    graph->add_edge(0, 1);
    EXPECT_NO_THROW(
    {
        graph->remove_edge(0, 1);
    });
}

TEST_F(AdjacencyListTest, RemoveNonExistingEdge)
{
    graph::GraphPtr graph = std::make_shared<graph::AdjacencyList>(2);
    graph->add_edge(0, 1);
    EXPECT_THROW(
    {
        graph->remove_edge(1, 0);
    }, graph::edge_not_found);
}

TEST_F(AdjacencyListTest, GetNeighborsBaseCase)
{
    std::ifstream in(get_path("BaseCase.txt"));
    graph::SizeG count;
    in >> count;
    graph::GraphPtr graph = std::make_shared<graph::AdjacencyList>(count);
    std::copy
    (
        graph::read_edges<graph::Edge>(in),
        graph::EdgeInputIterator::end(),
        graph::edge_inserter(graph)
    );

    EXPECT_THAT
    (
        graph->get_neighbors(0),
        testing::UnorderedElementsAre(2, 4, 5)
    );
    EXPECT_THAT
    (
        graph->get_neighbors(1),
        testing::UnorderedElementsAre(4, 5)
    );
    EXPECT_THAT
    (
        graph->get_neighbors(2),
        testing::UnorderedElementsAre(3, 4)
    );
    EXPECT_THAT
    (
        graph->get_neighbors(3),
        testing::UnorderedElementsAre(6)
    );
    EXPECT_THAT
    (
        graph->get_neighbors(4),
        testing::UnorderedElementsAre(5)
    );
    EXPECT_EQ(graph->get_neighbors(5).size(), 0);
    EXPECT_EQ(graph->get_neighbors(6).size(), 0);

    EXPECT_THAT
    (
        graph->get_neighbors(7),
        testing::UnorderedElementsAre(6, 1)
    );
    in.close();
}

TEST_F(AdjacencyListTest, GetNeighborsNonExistingNode)
{
    graph::GraphPtr graph = std::make_shared<graph::AdjacencyList>(3);
    EXPECT_THROW
    (
    {
        graph->get_neighbors(3);
    },
    graph::invalid_node
    );
}
} //namespace test

