#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_

#include <cstdint>
#include <memory>
#include <vector>

namespace graph
{
    typedef int64_t SizeG;
    typedef int64_t Node;

    class Graph
    {
    protected:
        SizeG node_count;
        Graph() = delete;
        explicit Graph(const Graph &other) = delete;
        Graph &operator=(const Graph &other) = delete;

    public:
        explicit Graph(SizeG node_count);
        explicit Graph(Graph &&source);
        SizeG get_node_count() const;
        virtual std::vector<Node> get_neighbors(Node u) const = 0;
    };

    typedef std::shared_ptr<const Graph> GraphCPtr;
    typedef std::shared_ptr<Graph> GraphPtr;
} //namespace graph

#endif