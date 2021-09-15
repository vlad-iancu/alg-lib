#include <algorithm>

#include <edge/iterators.hpp>

namespace graph
{
    EdgeOutputIterator edge_inserter(GraphPtr graph)
    {
        return EdgeOutputIterator(std::make_shared<GraphEdgeWriter>(graph));
    }

    void copy(EdgeInputIterator in, EdgeOutputIterator out)
    {
        std::copy(in, EdgeInputIterator::end(), out);
    }
} //namespace graph
