#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_ADJACENCY_LIST_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_ADJACENCY_LIST_H_

#include <vector>

#include <graph/Graph.hpp>

namespace graph
{
    class AdjacencyList : public Graph
    {
    private:
        std::vector<Node> *G;
        AdjacencyList &operator=(const AdjacencyList &other) = delete;
        explicit AdjacencyList(const AdjacencyList &other) = delete;

    public:
        explicit AdjacencyList(SizeG node_count);
        explicit AdjacencyList(AdjacencyList &&source);
        AdjacencyList &operator=(AdjacencyList &&source);
        ~AdjacencyList();

        //Graph overrides
        std::vector<Node> get_neighbors(Node u) const;
    };

}

#endif