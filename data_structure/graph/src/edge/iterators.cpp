#include <edge/iterators.hpp>

namespace graph
{
    EdgeOutputIterator edge_inserter(GraphPtr graph)
    {
        return EdgeOutputIterator(std::make_shared<GraphEdgeWriter>(graph));
    }
} //namespace graph
