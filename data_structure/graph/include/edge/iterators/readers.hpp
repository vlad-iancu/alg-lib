#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_READERS_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_READERS_H_

#include <edge/iterators/EdgeInputIterator.hpp>
#include <edge/readers/EdgeStreamReader.hpp>

namespace graph
{
    template<typename TEdge>
    EdgeInputIterator read_edges(std::istream& in)
    {
        return EdgeInputIterator(std::make_shared<EdgeStreamReader<TEdge>>(in));
    }
}

#endif