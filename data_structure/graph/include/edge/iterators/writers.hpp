#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_WRITERS_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_WRITERS_H_

#include <edge/iterators/EdgeOutputIterator.hpp>
#include <edge/writers/GraphEdgeWriter.hpp>
#include <graph/Graph.hpp>

namespace graph
{
    EdgeOutputIterator edge_inserter(GraphPtr graph)
    {
        return EdgeOutputIterator(std::make_shared<GraphEdgeWriter>(graph));
    }
} //namespace graph

#endif