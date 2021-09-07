#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_EDGE_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_EDGE_H_

#include <fstream>
#include <memory>

namespace graph
{
    struct Edge
    {
        int from;
        int to;

        virtual void read(std::istream &input)
        {
            input >> from >> to;
        }

        virtual Edge reverse() const
        {
            Edge e;
            e.to = from;
            e.from = to;
            return e;
        }

        bool operator==(const Edge &other)
        {
            return from == other.from && to == other.to;
        }

        bool operator!=(const Edge &other)
        {
            return !(*this == other);
        }
    };

    typedef std::shared_ptr<Edge> EdgePtr;
    typedef std::shared_ptr<const Edge> EdgeCptr;
} // namespace graph
#endif