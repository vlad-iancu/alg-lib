#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_GRAPH_H_

#include <memory>
#include <vector>

#include <graph/types.hpp>
#include <edge/iterators/EdgeInputIterator.hpp>
#include <edge/Edge.hpp>

namespace graph
{

    class Graph
    {
    protected:
        SizeG node_count;
        Graph() = delete;
        explicit Graph(const Graph& other) = delete;
        Graph& operator=(const Graph& other) = delete;

    public:
        explicit Graph(SizeG node_count);
        explicit Graph(Graph&& source);

        SizeG get_node_count() const;

        virtual std::vector<Node> get_neighbors(Node u) const = 0;
        virtual std::vector<EdgePtr> get_neighbor_edges(Node u) const = 0;
        virtual EdgeInputIterator edge_iterator() const = 0;

        virtual void add_edge(Node u, Node v) = 0;
        virtual bool has_edge(Node u, Node v) const = 0;
        virtual void remove_edge(Node u, Node v) = 0;
    };

    typedef std::shared_ptr<Graph> GraphPtr;

    typedef std::shared_ptr<const Graph> GraphCPtr;

    class invalid_node : std::exception
    {
    public:
        virtual const char* what() const noexcept
        {
            return "Node must be a number between 0 and N, where N is the number of nodes in the graph";
        }
    };
    class edge_not_found : std::exception
    {
    public:
        virtual const char* what() const noexcept
        {
            return "Edge does not exist";
        }
    };
    class edge_already_exists : std::exception
    {
        virtual const char* what() const noexcept
        {
            return "Edge alreay exists";
        }
    };

} //namespace graph

#endif