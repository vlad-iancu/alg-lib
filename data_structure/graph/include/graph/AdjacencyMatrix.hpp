#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_ADJACENCY_MATRIX_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_ADJACENCY_MATRIX_H_

#include <vector>

#include <graph/Graph.hpp>
#include <graph/types.hpp>

#include <edge/Edge.hpp>

namespace graph
{
    class AdjacencyMatrix : public Graph
    {
    private:
        Node **G;
        AdjacencyMatrix &operator=(const AdjacencyMatrix &other) = delete;
        explicit AdjacencyMatrix(const AdjacencyMatrix &other) = delete;

    public:
        explicit AdjacencyMatrix(SizeG node_count);
        explicit AdjacencyMatrix(AdjacencyMatrix &&source);
        AdjacencyMatrix &operator=(AdjacencyMatrix &&source);
        ~AdjacencyMatrix();

        //Graph overrides
        virtual std::vector<Node> get_neighbors(Node u) const;
        virtual std::vector<Node> get_interior_neighbors(Node u) const;

        virtual std::vector<EdgePtr> get_neighbor_edges(Node u) const;
        virtual std::vector<EdgePtr> get_interior_edges(Node u) const;

        virtual EdgeInputIterator edge_iterator() const;

        virtual void add_edge(Node u, Node v, bool ignore = true);
        virtual bool has_edge(Node u, Node v) const;
        virtual void remove_edge(Node u, Node v, bool ignore = true);

        virtual void insert_edge(EdgePtr edge, bool ignore = true);

        //Object methods
        virtual Node get(Node i, Node j) const;
        virtual void set(Node i, Node j, Node value);
    };
}
#endif