#include <graph/EdgeList.hpp>
#include <edge/readers/EdgeListEdgeReader.hpp>
#include <algorithm>

namespace graph
{
    EdgeList::EdgeList(SizeG node_count) : Graph(node_count) {}
    EdgeList::EdgeList(EdgeList &&source) : Graph(std::move(source.node_count))
    {
        _edges = std::move(source._edges);
    }

    std::vector<Node> EdgeList::get_neighbors(Node u) const
    {
        valid_node(u);
        std::vector<Node> result;
        std::vector<EdgePtr> temp;
        std::copy_if(
            _edges.begin(),
            _edges.end(),
            std::back_inserter(temp),
            [u](const EdgePtr &edge)
            {
                return edge->from == u;
            });
        std::transform(
            temp.begin(),
            temp.end(),
            std::back_inserter(result),
            [u](const EdgePtr &edge)
            {
                return edge->to;
            });
        return result;
    }

    std::vector<Node> EdgeList::get_interior_neighbors(Node u) const
    {
        valid_node(u);
        std::vector<Node> result;
        std::vector<EdgePtr> temp;
        std::copy_if(
            _edges.begin(),
            _edges.end(),
            std::back_inserter(temp),
            [u](const EdgePtr &edge)
            {
                return edge->to == u;
            });
        std::transform(
            temp.begin(),
            temp.end(),
            std::back_inserter(result),
            [u](const EdgePtr &edge)
            {
                return edge->from;
            });

        return result;
    }

    std::vector<EdgePtr> EdgeList::get_neighbor_edges(Node u) const
    {
        valid_node(u);
        std::vector<EdgePtr> result;
        std::copy_if(
            _edges.begin(),
            _edges.end(),
            std::back_inserter(result),
            [u](const EdgePtr &edge)
            {
                return edge->from == u;
            });

        return result;
    }

    std::vector<EdgePtr> EdgeList::get_interior_edges(Node u) const
    {
        valid_node(u);
        std::vector<EdgePtr> result;
        std::copy_if(
            _edges.begin(),
            _edges.end(),
            std::back_inserter(result),
            [u](const EdgePtr &edge)
            {
                return edge->to == u;
            });

        return result;
    }

    EdgeInputIterator EdgeList::edge_iterator() const
    {
        return EdgeInputIterator(std::make_shared<EdgeListEdgeReader>(*this));
    }

    void EdgeList::add_edge(Node u, Node v)
    {
        valid_nodes(u, v);
        if (has_edge(u, v))
            throw edge_already_exists();
        _edges.push_back(std::make_shared<Edge>(u, v));
    }

    bool EdgeList::has_edge(Node u, Node v) const
    {
        valid_nodes(u, v);
        for (SizeE i = 0; i < _edges.size(); i++)
        {
            if (*(_edges[i]) == Edge{u, v})
            {
                return true;
            }
        }
        return false;
    }

    void EdgeList::remove_edge(Node u, Node v)
    {
        valid_nodes(u, v);
        for (auto it = _edges.begin(); it != _edges.end(); it++)
        {
            if (*(*it) == Edge{u, v})
            {
                _edges.erase(it);
                return;
            }
        }
        throw edge_not_found();
    }

    void EdgeList::insert_edge(EdgePtr edge)
    {
        add_edge(edge->from, edge->to);
    }

    EdgePtr EdgeList::get(SizeE index) const
    {
        return _edges[index];
    }

    SizeE EdgeList::edge_count() const
    {
        return _edges.size();
    }

} // namespace graph
