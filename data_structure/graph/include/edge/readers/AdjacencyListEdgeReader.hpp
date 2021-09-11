#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_ADJACENCY_LIST_READER_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_ADJACENCY_LIST_READER_H_
#include <memory>

#include <edge/readers/EdgeReader.hpp>
#include <graph/Graph.hpp>
#include <graph/AdjacencyList.hpp>

namespace graph
{
    template<typename TEdge>
    class AdjacencyListEdgeReader : public EdgeReader
    {
    private:
        const AdjacencyList& G;
        Node current_node;
        std::vector<EdgePtr> neighbors;
        Node current_neighbor;
        bool _can_read;
    public:
        explicit AdjacencyListEdgeReader
        (
            const AdjacencyList& G,
            Node current_node = 0,
            Node current_neighbor = 0
        ) : G(G),
            current_node(current_node),
            current_neighbor(current_neighbor)
        {
            while(G.get_neighbor_edges(current_node).size() == 0 && current_node < G.get_node_count())
                current_node++;

            _can_read = current_node < G.get_node_count();
            if(_can_read)
            {
                neighbors = G.get_neighbor_edges(current_node);
            }
        }

        bool increment() override
        {
            if (current_neighbor >= neighbors.size() - 1)
            {
                current_node++;
                current_neighbor = 0;
                if (current_node >= G.get_node_count())
                    return false;
                while((neighbors = G.get_neighbor_edges(current_node)).empty())
                {
                    current_node++;
                }
            }
            else
            {
                current_neighbor++;
            }

            return current_node < G.get_node_count();
        }

        EdgePtr current_edge() const override
        {
            return neighbors[current_neighbor];
        }

        bool can_read() const override
        {
            return _can_read;
        }
    };
} //namespace graph
#endif