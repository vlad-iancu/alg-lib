#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_EDGE_LIST_READER_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_EDGE_LIST_READER_H_

#include <graph/EdgeList.hpp>
#include <graph/types.hpp>

#include <edge/readers/EdgeReader.hpp>

namespace graph
{
    class EdgeListEdgeReader : public EdgeReader
    {
    private:
        const EdgeList &graph;
        bool _can_read;
        SizeE index;

    public:
        EdgeListEdgeReader(const EdgeList &graph);

        bool increment();

        EdgePtr current_edge() const;

        bool can_read() const;
    };

} // namespace graph

#endif