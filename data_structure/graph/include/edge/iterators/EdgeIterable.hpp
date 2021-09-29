#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_ITERABLE_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_ITERABLE_H_

#include <edge/iterators/EdgeInputIterator.hpp>

namespace graph
{
    class EdgeIterable
    {
    private:
        EdgeInputIterator it;

    public:
        EdgeIterable(EdgeInputIterator it) : it(it) {}
        EdgeInputIterator begin() { return it; }
        EdgeInputIterator end() { return EdgeInputIterator::end(); }
    };
}
#endif