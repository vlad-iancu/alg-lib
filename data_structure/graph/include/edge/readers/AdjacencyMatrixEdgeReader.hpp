#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_ADJACENCY_LIST_READER_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_ADJACENCY_LIST_READER_H_

#include <edge/readers/EdgeReader.hpp>
#include <graph/AdjacencyMatrix.hpp>

namespace graph
{
    class AdjacencyMatrixEdgeReader : public EdgeReader
    {
    private:
        struct MatrixIndex
        {
            SizeG count;
            Node i, j;
            MatrixIndex(SizeG count) : count(count), i(0), j(0) {}
            bool next();
            bool valid() const;
        };
        const AdjacencyMatrix &mat;
        EdgePtr _current_edge;
        bool _can_read = true;
        MatrixIndex index;
        void next_edge(bool include_current);
    public:
        AdjacencyMatrixEdgeReader(const AdjacencyMatrix &mat);

        virtual bool increment();

        virtual EdgePtr current_edge() const;

        virtual bool can_read() const
        {
            return _can_read;
        }
    };
} // namespace graph

#endif
