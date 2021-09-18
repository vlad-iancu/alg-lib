#include <algorithm>

#include <graph/AdjacencyMatrix.hpp>
#include <edge/readers/AdjacencyMatrixEdgeReader.hpp>

namespace graph
{
    AdjacencyMatrix::AdjacencyMatrix(SizeG node_count) : Graph(node_count)
    {
        G = new Node *[node_count];
        for (Node i = 0; i < node_count; i++)
        {
            G[i] = new Node[node_count]{0};
        }
    }

    AdjacencyMatrix::AdjacencyMatrix(AdjacencyMatrix &&source) : Graph(std::move(source.node_count))
    {
        G = source.G;
        source.G = nullptr;
    }

    AdjacencyMatrix::~AdjacencyMatrix()
    {
        for (Node i = 0; i < node_count; i++)
        {
            delete G[i];
        }
        delete G;
    }

    AdjacencyMatrix &AdjacencyMatrix::operator=(AdjacencyMatrix &&source)
    {
        if (this != &source)
        {
            for (Node i = 0; i < node_count; i++)
                delete G[i];
            node_count = std::move(source.node_count);
            G = std::move(source.G);
        }

        return *this;
    }

    std::vector<Node> AdjacencyMatrix::get_neighbors(Node u) const
    {
        valid_node(u);
        std::vector<Node> result;
        for(Node v = 0; v < node_count; v++)
        {
            if(G[u][v])
            {
                result.push_back(v);
            }
        }
        return result;
    }

    std::vector<Node> AdjacencyMatrix::get_interior_neighbors(Node u) const
    {
        valid_node(u);
        std::vector<Node> result;
        for (Node v = 0; v < node_count; v++)
        {
            if (G[v][u])
            {
                result.push_back(v);
            }
        }
        return result;
    }

    std::vector<EdgePtr> AdjacencyMatrix::get_neighbor_edges(Node u) const
    {
        valid_node(u);
        std::vector<EdgePtr> result;
        for (Node v = 0; v < node_count; v++)
        {
            if (G[u][v])
            {
                result.push_back(
                    std::make_shared<Edge>(u, v));
            }
        }
        return result;
    }

    std::vector<EdgePtr> AdjacencyMatrix::get_interior_edges(Node u) const
    {
        valid_node(u);
        std::vector<EdgePtr> result;
        for (Node v = 0; v < node_count; v++)
        {
            if (G[v][u])
            {
                result.push_back(
                    std::make_shared<Edge>(v, u));
            }
        }
        return result;
    }

    EdgeInputIterator AdjacencyMatrix::edge_iterator() const
    {
        return EdgeInputIterator(std::make_shared<AdjacencyMatrixEdgeReader>(*this));
    }

    void AdjacencyMatrix::add_edge(Node u, Node v, bool ignore)
    {
        valid_nodes(u, v);
        if (!ignore && has_edge(u, v))
            throw edge_already_exists();
        G[u][v] = 1;
    }

    bool AdjacencyMatrix::has_edge(Node u, Node v) const
    {
        valid_nodes(u, v);
        return G[u][v];
    }

    void AdjacencyMatrix::remove_edge(Node u, Node v, bool ignore)
    {
        valid_nodes(u, v);
        if (!ignore && !has_edge(u, v))
            throw edge_not_found();
        G[u][v] = 0;
    }

    void AdjacencyMatrix::insert_edge(EdgePtr edge, bool ignore)
    {
        valid_nodes(edge->from, edge->to);
        add_edge(edge->from, edge->to, ignore);
    }

    Node AdjacencyMatrix::get(Node i, Node j) const
    {
        valid_nodes(i, j);
        return G[i][j];
    }

    void AdjacencyMatrix::set(Node i, Node j, Node value)
    {
        valid_nodes(i, j);
        G[i][j] = value;
    }
} // namespace graph
