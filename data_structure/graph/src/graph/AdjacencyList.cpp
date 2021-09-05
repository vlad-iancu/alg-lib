#include <graph/AdjacencyList.hpp>

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
            node_count = source.node_count;
            G = source.G;
            source.G = nullptr;
            source.node_count = 0;
        }

        return *this;
    }

    std::vector<Node> AdjacencyList::get_neighbors(Node u) const
    {
        return G[u];
    }
}