#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_

#include <memory>
#include <vector>

#include <graph/types.hpp>
#include <edge/iterators/EdgeInputIterator.hpp>
#include <edge/iterators/EdgeIterable.hpp>
#include <edge/Edge.hpp>

namespace graph
{
    /**
     * Abstract base class that serves creating graphs.
     * 
     * In order to create a custom Graph, the user has to implement:
     * get_neighbors(Node u)
     * get_interior_neighbors(Node u)
     * get_neighbor_edges(Node u)
     * get_interior_edges(Node u)
     * edge_iterator()
     * add_edge(Node u, Node v, bool)
     * has_edge(Node u, Node v)
     * remove_edge(Node u, Node v, bool)
     * edges()
     * insert_edge(EdgePtr, bool)
     */
    class Graph
    {
    protected:
        SizeG node_count;
        Graph() = delete;
        explicit Graph(const Graph &other) = delete;
        Graph &operator=(const Graph &other) = delete;
        void valid_nodes(Node u, Node v) const;
        void valid_node(Node u) const;

    public:
        explicit Graph(SizeG node_count);
        explicit Graph(Graph &&source);

        SizeG get_node_count() const;

        virtual std::vector<Node> get_neighbors(Node u) const = 0;
        virtual std::vector<Node> get_interior_neighbors(Node u) const = 0;

        virtual std::vector<EdgePtr> get_neighbor_edges(Node u) const = 0;
        virtual std::vector<EdgePtr> get_interior_edges(Node u) const = 0;

        virtual EdgeInputIterator edge_iterator() const = 0;

        virtual void add_edge(Node u, Node v, bool ignore = true) = 0;
        virtual bool has_edge(Node u, Node v) const = 0;
        virtual void remove_edge(Node u, Node v, bool ignore = true) = 0;

        EdgeIterable edges() const;
        virtual void insert_edge(EdgePtr edge, bool ignore = true) = 0;
    };

    typedef std::shared_ptr<Graph> GraphPtr;

    typedef std::shared_ptr<const Graph> GraphCPtr;

    class invalid_size : std::exception
    {
    public:
        virtual const char *what() const noexcept
        {
            return "N must be a non negative integer";
        }
    };

    class invalid_node : std::exception
    {
    public:
        virtual const char *what() const noexcept
        {
            return "Node must be a number between 0 and N, where N is the number of nodes in the graph";
        }
    };
    class edge_not_found : std::exception
    {
    public:
        virtual const char *what() const noexcept
        {
            return "Edge does not exist";
        }
    };
    class edge_already_exists : std::exception
    {
        virtual const char *what() const noexcept
        {
            return "Edge alreay exists";
        }
    };

} //namespace graph

#endif