#ifndef ALG_LIB_DATA_STRUCUTRE_GRAPH_EDGE_LIST_H_
#define ALG_LIB_DATA_STRUCUTRE_GRAPH_EDGE_LIST_H_

#include <vector>

#include <graph/Graph.hpp>
#include <edge/Edge.hpp>

namespace graph
{
    class EdgeList : public Graph
    {
    private:
        std::vector<EdgePtr> _edges;

    public:
        explicit EdgeList(SizeG node_count);
        explicit EdgeList(EdgeList &&source);

        //Graph overrides
        std::vector<Node> get_neighbors(Node u) const;
        std::vector<Node> get_interior_neighbors(Node u) const;

        std::vector<EdgePtr> get_neighbor_edges(Node u) const;
        std::vector<EdgePtr> get_interior_edges(Node u) const;

        EdgeInputIterator edge_iterator() const;

        void add_edge(Node u, Node v);
        bool has_edge(Node u, Node v) const;
        void remove_edge(Node u, Node v);

        void insert_edge(EdgePtr edge);

        //Object methods
        EdgePtr get(SizeE index) const;
        SizeE edge_count() const;
    };
} // namespace graph

#endif
