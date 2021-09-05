#include <graph/AdjacencyList.hpp>

namespace graph
{
    AdjacencyList::AdjacencyList(SizeG node_count): Graph(node_count)
    {
        G = new std::vector<int>[node_count];
    }

    AdjacencyList::AdjacencyList(AdjacencyList &&source): Graph(source.node_count)
    {
        G = source.G;
        source.G = nullptr;
    }

    AdjacencyList::~AdjacencyList()
    {
        delete[] G;
    }
}