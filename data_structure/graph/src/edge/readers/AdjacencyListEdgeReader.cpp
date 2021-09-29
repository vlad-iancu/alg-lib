#include <edge/readers/AdjacencyListEdgeReader.hpp>

namespace graph
{
    AdjacencyListEdgeReader::AdjacencyListEdgeReader(
        const AdjacencyList &G,
        Node current_node,
        Node current_neighbor) : G(G),
                                 current_node(current_node),
                                 current_neighbor(current_neighbor)
    {
        while (current_node < G.get_node_count() && G.get_neighbor_edges(current_node).size() == 0)
            current_node++;

        _can_read = current_node < G.get_node_count();
        if (_can_read)
        {
            neighbors = G.get_neighbor_edges(current_node);
        }
    }

    bool AdjacencyListEdgeReader::increment()
    {
        if (current_neighbor >= neighbors.size() - 1)
        {
            current_node++;
            current_neighbor = 0;
            if (current_node >= G.get_node_count())
                return false;
            while (current_node < G.get_node_count() && (neighbors = G.get_neighbor_edges(current_node)).empty())
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

    EdgePtr AdjacencyListEdgeReader::current_edge() const
    {
        return neighbors[current_neighbor];
    }

    bool AdjacencyListEdgeReader::can_read() const
    {
        return _can_read;
    }
} // namespace graph
