#include <iostream>

#include <edge/iterators/EdgeInputIterator.hpp>
#include <edge/readers/EdgeStreamReader.hpp>
#include <edge/readers/EdgeReader.hpp>
#include <edge/Edge.hpp>

int main()
{
    graph::EdgeReaderPtr<graph::Edge> reader = std::make_shared<graph::EdgeStreamReader<graph::Edge>>(std::cin);
    graph::EdgeInputIterator<graph::Edge> it(reader);
    while(it != graph::EdgeInputIterator<graph::Edge>::end())
    {
        std::cout << "Here is the edge:" << (*it).from << " " << (*it).to << std::endl;
        it++;
    }
}