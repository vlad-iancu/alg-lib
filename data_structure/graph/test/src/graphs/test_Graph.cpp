#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <graphs/GraphTest.hpp>

#include <fstream>

#include <graph/AdjacencyList.hpp>
#include <graph/AdjacencyMatrix.hpp>

#include <edge/iterators.hpp>

namespace test
{

    TYPED_TEST_SUITE_P(GraphTest);

    TYPED_TEST_P(GraphTest, BaseCase)
    {
        std::ifstream in(this->get_path("BaseCase.txt"));
        graph::SizeG n;
        in >> n;

        graph::GraphPtr graph = std::make_shared<TypeParam>(n);
        std::copy(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end(), graph::edge_inserter(graph));

        std::cout << std::endl
                  << "Node 0..." << std::endl;
        EXPECT_EQ(3, graph->get_neighbors(0).size());
        EXPECT_TRUE(graph->has_edge(0, 2));
        EXPECT_TRUE(graph->has_edge(0, 4));
        EXPECT_TRUE(graph->has_edge(0, 5));
        std::cout << std::endl
                  << "Node 1..." << std::endl;

        EXPECT_EQ(2, graph->get_neighbors(1).size());
        EXPECT_TRUE(graph->has_edge(1, 5));
        EXPECT_TRUE(graph->has_edge(1, 4));
        std::cout << std::endl
                  << "Node 2..." << std::endl;

        EXPECT_EQ(2, graph->get_neighbors(2).size());
        EXPECT_TRUE(graph->has_edge(2, 3));
        EXPECT_TRUE(graph->has_edge(2, 4));
        std::cout << std::endl
                  << "Node 3..." << std::endl;

        EXPECT_EQ(1, graph->get_neighbors(3).size());
        EXPECT_TRUE(graph->has_edge(3, 6));
        std::cout << std::endl
                  << "Node 4..." << std::endl;

        EXPECT_EQ(1, graph->get_neighbors(4).size());
        EXPECT_TRUE(graph->has_edge(4, 5));
        std::cout << std::endl
                  << "Node 5..." << std::endl;

        EXPECT_EQ(0, graph->get_neighbors(5).size());
        std::cout << std::endl
                  << "Node 6..." << std::endl;

        EXPECT_EQ(0, graph->get_neighbors(6).size());
        std::cout << std::endl
                  << "Node 7..." << std::endl;

        EXPECT_EQ(2, graph->get_neighbors(7).size());
        EXPECT_TRUE(graph->has_edge(7, 1));
        EXPECT_TRUE(graph->has_edge(7, 6));

        in.close();
    }

    TYPED_TEST_P(GraphTest, EmptyGraph)
    {
        std::ifstream in(this->get_path("ZeroNode.txt"));
        graph::SizeG n;
        in >> n;
        EXPECT_THROW(
            {
                graph::GraphPtr G = std::make_shared<TypeParam>(n);
            },
            graph::invalid_size);
        in.close();
    }

    TYPED_TEST_P(GraphTest, AddEdgeBaseCase)
    {
        graph::GraphPtr G = std::make_shared<TypeParam>(2);
        G->add_edge(0, 1);
        G->add_edge(1, 0);
        EXPECT_TRUE(G->has_edge(0, 1));
        EXPECT_TRUE(G->has_edge(1, 0));
        EXPECT_EQ(1, G->get_neighbors(1).size());
        EXPECT_EQ(1, G->get_neighbors(0).size());
    }

    TYPED_TEST_P(GraphTest, AddEdgeNegativeNode)
    {
        EXPECT_THROW(
            {
                graph::GraphPtr G = std::make_shared<TypeParam>(2);
                G->add_edge(0, -1);
                G->add_edge(1, 0);
                EXPECT_TRUE(G->has_edge(0, 1));
                EXPECT_TRUE(G->has_edge(1, 0));
                EXPECT_EQ(1, G->get_neighbors(1).size());
                EXPECT_EQ(1, G->get_neighbors(0).size());
            },
            graph::invalid_node);
    }

    TYPED_TEST_P(GraphTest, AddEdgeNodeOverflow)
    {
        EXPECT_THROW(
            {
                graph::GraphPtr G = std::make_shared<TypeParam>(2);
                G->add_edge(2, 1);
            },
            graph::invalid_node);
    }

    TYPED_TEST_P(GraphTest, HasExistingEdge)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(2);
        graph->add_edge(0, 1);
        EXPECT_TRUE(graph->has_edge(0, 1));
    }

    TYPED_TEST_P(GraphTest, HasNonExistingEdge)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(2);
        graph->add_edge(0, 1);
        EXPECT_FALSE(graph->has_edge(1, 0));
    }

    TYPED_TEST_P(GraphTest, RemoveExistingEdge)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(2);
        graph->add_edge(0, 1);
        EXPECT_NO_THROW(
            {
                graph->remove_edge(0, 1);
            });
    }

    TYPED_TEST_P(GraphTest, RemoveNonExistingEdge)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(2);
        graph->add_edge(0, 1);
        EXPECT_THROW(
            {
                graph->remove_edge(1, 0);
            },
            graph::edge_not_found);
    }

    TYPED_TEST_P(GraphTest, GetNeighborsBaseCase)
    {
        std::ifstream in(this->get_path("BaseCase.txt"));
        graph::SizeG count;
        in >> count;
        graph::GraphPtr graph = std::make_shared<TypeParam>(count);
        std::copy(
            graph::read_edges<graph::Edge>(in),
            graph::EdgeInputIterator::end(),
            graph::edge_inserter(graph));

        EXPECT_THAT(
            graph->get_neighbors(0),
            testing::UnorderedElementsAre(2, 4, 5));
        EXPECT_THAT(
            graph->get_neighbors(1),
            testing::UnorderedElementsAre(4, 5));
        EXPECT_THAT(
            graph->get_neighbors(2),
            testing::UnorderedElementsAre(3, 4));
        EXPECT_THAT(
            graph->get_neighbors(3),
            testing::UnorderedElementsAre(6));
        EXPECT_THAT(
            graph->get_neighbors(4),
            testing::UnorderedElementsAre(5));
        EXPECT_EQ(graph->get_neighbors(5).size(), 0);
        EXPECT_EQ(graph->get_neighbors(6).size(), 0);

        EXPECT_THAT(
            graph->get_neighbors(7),
            testing::UnorderedElementsAre(6, 1));
        in.close();
    }

    TYPED_TEST_P(GraphTest, GetNeighborsNonExistingNode)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(3);
        EXPECT_THROW(
            {
                graph->get_neighbors(3);
            },
            graph::invalid_node);
    }
    TYPED_TEST_P(GraphTest, GetEdgesBaseCase)
    {
        std::ifstream in(this->get_path("BaseCase.txt"));
        graph::SizeG count;
        in >> count;
        graph::GraphPtr graph = std::make_shared<TypeParam>(count);
        std::copy(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end(), graph::edge_inserter(graph));
        std::vector<graph::Edge> result;
        std::transform(
            graph->edge_iterator(),
            graph::EdgeInputIterator::end(),
            std::back_inserter(result),
            [](const graph::EdgePtr &edge)
            {
                return *edge;
            });
        for (auto ed : result)
        {
            std::cout << "(" << ed.from << "," << ed.to << ")" << std::endl;
        }
        EXPECT_THAT(result,
                    testing::UnorderedElementsAre(
                        graph::Edge{0, 2},
                        graph::Edge{0, 5},
                        graph::Edge{0, 4},
                        graph::Edge{1, 4},
                        graph::Edge{1, 5},
                        graph::Edge{2, 3},
                        graph::Edge{2, 4},
                        graph::Edge{3, 6},
                        graph::Edge{4, 5},
                        graph::Edge{7, 1},
                        graph::Edge{7, 6}));
        in.close();
    }

    TYPED_TEST_P(GraphTest, GetEdgesIsolatedGraph)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(5);
        std::vector<graph::EdgePtr> edges(graph->edge_iterator(), graph::EdgeInputIterator::end());
        EXPECT_EQ(edges.size(), 0);
    }

    TYPED_TEST_P(GraphTest, EdgeIterable)
    {
        std::ifstream in(this->get_path("BaseCase2.txt"));
        graph::SizeG count;
        in >> count;
        graph::GraphPtr graph = std::make_shared<TypeParam>(count);
        std::copy(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end(), graph::edge_inserter(graph));
        std::vector<graph::Edge> edges;

        std::transform(
            graph->edges().begin(),
            graph->edges().end(),
            std::back_inserter(edges),
            [](const graph::EdgePtr &edge)
            { return *edge; });
        EXPECT_THAT(
            edges,
            testing::UnorderedElementsAre(
                graph::Edge{0, 4},
                graph::Edge{0, 2},
                graph::Edge{0, 5},
                graph::Edge{1, 4},
                graph::Edge{1, 5},
                graph::Edge{2, 4},
                graph::Edge{2, 3},
                graph::Edge{4, 5}));
        in.close();
    }
    TYPED_TEST_P(GraphTest, GetInteriorEdgesBaseCase)
    {
        std::ifstream in(this->get_path("BaseCase2.txt"));
        graph::SizeG count;
        in >> count;
        graph::GraphPtr graph = std::make_shared<TypeParam>(count);
        std::copy(graph::read_edges<graph::Edge>(in), graph::EdgeInputIterator::end(), graph::edge_inserter(graph));

        EXPECT_EQ(0, graph->get_interior_edges(0).size());
        EXPECT_EQ(0, graph->get_interior_edges(1).size());

        EXPECT_THAT(
            graph->get_interior_edges(2),
            testing::UnorderedElementsAre(
                testing::Pointee(testing::Eq(graph::Edge{0, 2}))));

        EXPECT_THAT(
            graph->get_interior_edges(3),
            testing::UnorderedElementsAre(
                testing::Pointee(testing::Eq(graph::Edge{2, 3}))));

        EXPECT_THAT(
            graph->get_interior_edges(4),
            testing::UnorderedElementsAre(
                testing::Pointee(testing::Eq(graph::Edge{0, 4})),
                testing::Pointee(testing::Eq(graph::Edge{1, 4})),
                testing::Pointee(testing::Eq(graph::Edge{2, 4}))));

        EXPECT_THAT(
            graph->get_interior_edges(5),
            testing::UnorderedElementsAre(
                testing::Pointee(testing::Eq(graph::Edge{0, 5})),
                testing::Pointee(testing::Eq(graph::Edge{1, 5})),
                testing::Pointee(testing::Eq(graph::Edge{4, 5}))));

        in.close();
    }
    TYPED_TEST_P(GraphTest, GetInteriorEdgesIsolatedGraph)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(3);
        EXPECT_EQ(0, graph->get_interior_edges(0).size());
        EXPECT_EQ(0, graph->get_interior_edges(1).size());
        EXPECT_EQ(0, graph->get_interior_edges(2).size());
    }
    TYPED_TEST_P(GraphTest, GetInteriorNeighborsBaseCase)
    {
        std::ifstream in(this->get_path("BaseCase2.txt"));
        graph::SizeG count;
        in >> count;
        graph::GraphPtr graph = std::make_shared<TypeParam>(count);
        graph::copy(graph::read_edges<graph::Edge>(in), graph::edge_inserter(graph));
        EXPECT_EQ(0, graph->get_interior_neighbors(0).size());
        EXPECT_EQ(0, graph->get_interior_neighbors(1).size());
        EXPECT_THAT(
            graph->get_interior_neighbors(2),
            testing::UnorderedElementsAre(0));
        EXPECT_THAT(
            graph->get_interior_neighbors(3),
            testing::UnorderedElementsAre(2));
        EXPECT_THAT(
            graph->get_interior_neighbors(4),
            testing::UnorderedElementsAre(0, 1, 2));
        EXPECT_THAT(
            graph->get_interior_neighbors(5),
            testing::UnorderedElementsAre(0, 1, 4));
    }
    TYPED_TEST_P(GraphTest, GetInteriorNeighborsIsolatedGraph)
    {
        graph::GraphPtr graph = std::make_shared<TypeParam>(3);
        EXPECT_EQ(0, graph->get_interior_neighbors(0).size());
        EXPECT_EQ(0, graph->get_interior_neighbors(1).size());
        EXPECT_EQ(0, graph->get_interior_neighbors(2).size());
    }

    REGISTER_TYPED_TEST_SUITE_P(
        GraphTest,
        BaseCase,
        EmptyGraph,
        AddEdgeBaseCase,
        AddEdgeNegativeNode,
        AddEdgeNodeOverflow,
        HasExistingEdge,
        HasNonExistingEdge,
        RemoveExistingEdge,
        RemoveNonExistingEdge,
        GetNeighborsBaseCase,
        GetNeighborsNonExistingNode,
        GetEdgesBaseCase,
        GetEdgesIsolatedGraph,
        GetInteriorEdgesBaseCase,
        GetInteriorEdgesIsolatedGraph,
        GetInteriorNeighborsBaseCase,
        GetInteriorNeighborsIsolatedGraph,
        EdgeIterable);

    //For prefix convenience
    typedef graph::AdjacencyList AdjacencyList;
    typedef graph::AdjacencyMatrix AdjacencyMatrix;

    typedef testing::Types<AdjacencyList, AdjacencyMatrix> GraphTypes;
    INSTANTIATE_TYPED_TEST_SUITE_P(Graphs, GraphTest, GraphTypes);

} //namespace test
