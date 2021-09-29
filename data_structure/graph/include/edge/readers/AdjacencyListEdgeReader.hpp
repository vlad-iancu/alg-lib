#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_ADJACENCY_LIST_READER_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_ADJACENCY_LIST_READER_H_

#include <memory>

#include <edge/readers/EdgeReader.hpp>

#include <graph/Graph.hpp>
#include <graph/types.hpp>
#include <graph/AdjacencyList.hpp>

namespace graph
{
    class AdjacencyListEdgeReader : public EdgeReader
    {
    private:
        const AdjacencyList &G;
        Node current_node;
        std::vector<EdgePtr> neighbors;
        Node current_neighbor;
        bool _can_read;

    public:
        explicit AdjacencyListEdgeReader(
            const AdjacencyList &G,
            Node current_node = 0,
            Node current_neighbor = 0);

        bool increment() override;

        EdgePtr current_edge() const override;

        bool can_read() const override;
    };
} //namespace graph
#endif