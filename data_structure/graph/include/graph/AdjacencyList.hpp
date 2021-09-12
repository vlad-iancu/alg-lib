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

    protected:
        void valid_nodes(Node u, Node v) const;
        void valid_node(Node u) const;

    public:
        explicit AdjacencyList(SizeG node_count);
        explicit AdjacencyList(AdjacencyList &&source);
        AdjacencyList &operator=(AdjacencyList &&source);
        ~AdjacencyList();

        //Graph overrides
        virtual std::vector<Node> get_neighbors(Node u) const;
        virtual std::vector<EdgePtr> get_neighbor_edges(Node u) const;
        virtual EdgeInputIterator edge_iterator() const;

        virtual void add_edge(Node u, Node v);
        virtual bool has_edge(Node u, Node v) const;
        virtual void remove_edge(Node u, Node v);

        virtual void insert_edge(EdgePtr edge);
    };
}

#endif