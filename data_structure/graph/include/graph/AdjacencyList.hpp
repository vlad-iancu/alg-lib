#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_ADJACENCY_LIST_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_ADJACENCY_LIST_H_

#include <vector>

#include <graph/Graph.hpp>

namespace graph
{
    class AdjacencyList : public Graph
    {
    private:
        std::vector<int> *G;

    public:
        AdjacencyList(SizeG node_count);
        AdjacencyList(AdjacencyList &&source);
        ~AdjacencyList();
        //Graph overrides
        std::vector<int> get_neighbors(SizeG u);
    };

}

#endif