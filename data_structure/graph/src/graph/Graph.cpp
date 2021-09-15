#include <graph/Graph.hpp>
#include <edge/iterators.hpp>

namespace graph
{
    Graph::Graph(SizeG node_count) : node_count(node_count)
    {
        if (node_count <= 0)
            throw invalid_size();
    }

    SizeG Graph::get_node_count() const { return node_count; }

    Graph::Graph(Graph &&source) : node_count(std::move(source.node_count)) {}

    void Graph::valid_nodes(Node u, Node v) const
    {
        if (u >= node_count || v >= node_count)
        {
            throw invalid_node();
        }
        if (u < 0 || v < 0)
            throw invalid_node();
    }

    void Graph::valid_node(Node u) const
    {
        if (u >= node_count || u < 0)
            throw invalid_node();
    }

    EdgeIterable Graph::edges() const
    {
        return EdgeIterable(edge_iterator());
    }
} //namespace graph