#include <iostream>

#include <graph/AdjacencyList.hpp>

int main()
{
    graph::AdjacencyList g1(5);
    graph::AdjacencyList g2(std::move(g1));
    std::cout << g2.get_node_count() << std::endl;

    return 0;
}