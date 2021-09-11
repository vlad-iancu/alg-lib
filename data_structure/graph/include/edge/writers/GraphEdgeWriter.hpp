#ifndef ALG_LIB_DATA_STRUCTURE_ADJACENCY_LIST_EDGE_WRITER_H_
#define ALG_LIB_DATA_STRUCTURE_ADJACENCY_LIST_EDGE_WRITER_H_

#include <edge/writers/EdgeWriter.hpp>
#include <graph/Graph.hpp>

namespace graph
{
    class GraphEdgeWriter : public EdgeWriter
    {
    private:
        GraphPtr G;
        EdgePtr edge;
    public:
        GraphEdgeWriter(GraphPtr G) : G(G) {}

        EdgePtr& get_edge()
        {
            return edge;
        }

        void increment()
        {
            G->insert_edge(edge);
        }

    };

} // namespace graph


#endif