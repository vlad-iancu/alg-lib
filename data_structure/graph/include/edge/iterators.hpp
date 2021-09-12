#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_ITERATORS_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_ITERATORS_H_

#include <edge/iterators/EdgeOutputIterator.hpp>
#include <edge/writers/GraphEdgeWriter.hpp>
#include <edge/iterators/EdgeInputIterator.hpp>
#include <edge/readers/StreamEdgeReader.hpp>

#include <graph/Graph.hpp>

namespace graph
{
    template <typename TEdge>
    EdgeInputIterator read_edges(std::istream &in)
    {
        return EdgeInputIterator(std::make_shared<StreamEdgeReader<TEdge>>(in));
    }
    EdgeOutputIterator edge_inserter(GraphPtr graph);
} // namespace graph

#endif