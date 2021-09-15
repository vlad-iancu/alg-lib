#include <graph/AdjacencyList.hpp>

#include <algorithm>
#include <edge/readers/AdjacencyListEdgeReader.hpp>

namespace graph
{
    AdjacencyList::AdjacencyList(SizeG node_count) : Graph(node_count)
    {
        G = new std::vector<Node>[node_count];
    }

    AdjacencyList::AdjacencyList(AdjacencyList &&source) : Graph(std::move(source.node_count))
    {
        G = source.G;
        source.G = nullptr;
    }

    AdjacencyList::~AdjacencyList()
    {
        delete[] G;
    }

    AdjacencyList &AdjacencyList::operator=(AdjacencyList &&source)
    {
        if (this != &source)
        {
            delete[] G;
            node_count = std::move(source.node_count);
            G = std::move(source.G);
        }

        return *this;
    }

    EdgeInputIterator AdjacencyList::edge_iterator() const
    {
        EdgeReaderPtr reader = std::shared_ptr<EdgeReader>(new AdjacencyListEdgeReader(*this, 0, 0));
        return EdgeInputIterator(reader);
    }

    std::vector<Node> AdjacencyList::get_neighbors(Node u) const
    {
        valid_node(u);
        return G[u];
    }

    std::vector<EdgePtr> AdjacencyList::get_neighbor_edges(Node u) const
    {
        valid_node(u);
        std::vector<EdgePtr> result;
        std::transform(
            G[u].begin(),
            G[u].end(),
            std::back_inserter(result),
            [u](const int &v)
            {
                return std::make_shared<Edge>(u, v);
            });
        return result;
    }

    std::vector<EdgePtr> AdjacencyList::get_interior_edges(Node u) const
    {
        valid_node(u);
        std::vector<EdgePtr> result;
        for (int v = 0; v < node_count; v++)
        {
            if (has_edge(v, u))
            {
                result.push_back(std::make_shared<Edge>(v, u));
            }
        }
        return result;
    }

    std::vector<Node> AdjacencyList::get_interior_neighbors(Node u) const
    {
        valid_node(u);
        std::vector<Node> result;
        for (int v = 0; v < node_count; v++)
        {
            if (has_edge(v, u))
            {
                result.push_back(v);
            }
        }
        return result;
    }

    void AdjacencyList::add_edge(Node u, Node v)
    {
        valid_nodes(u, v);
        if (std::find(G[u].begin(), G[u].end(), v) != G[u].end())
            throw edge_already_exists();
        G[u].push_back(v);
    }

    bool AdjacencyList::has_edge(Node u, Node v) const
    {
        valid_nodes(u, v);
        return std::find(G[u].begin(), G[u].end(), v) != G[u].end();
    }

    void AdjacencyList::remove_edge(Node u, Node v)
    {
        valid_nodes(u, v);
        if (!has_edge(u, v))
            throw edge_not_found();
        G[u].erase(std::find(G[u].begin(), G[u].end(), v));
    }

    void AdjacencyList::insert_edge(EdgePtr edge)
    {
        add_edge(edge->from, edge->to);
    }

}