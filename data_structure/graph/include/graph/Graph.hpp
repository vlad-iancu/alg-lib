#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_

#include <vector>

namespace graph
{
    typedef unsigned long long SizeG;

    class Graph
    {
    protected:
        SizeG node_count;
        Graph() = delete;
        Graph(const Graph &other) = delete;
        Graph &operator=(const Graph &other) = delete;
    public:
        Graph(SizeG node_count);
        SizeG get_node_count();
        virtual std::vector<int> get_neighbors(int u) = 0;
    };
} //namespace graph

#endif