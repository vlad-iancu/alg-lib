#include <graph/Graph.hpp>

namespace graph
{
    Graph::Graph(SizeG node_count) : node_count(node_count)
    {
        if (node_count <= 0)
            throw invalid_size();
    }
    SizeG Graph::get_node_count() const { return node_count; }
    Graph::Graph(Graph &&source) : node_count(std::move(source.node_count)) {}
} //namespace graph