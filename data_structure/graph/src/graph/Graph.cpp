#include <graph/Graph.hpp>

namespace graph
{
    Graph::Graph(SizeG node_count): node_count(node_count) {}
    SizeG Graph::get_node_count() { return node_count; }

} //namespace graph