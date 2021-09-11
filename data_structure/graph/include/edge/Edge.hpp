#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_EDGE_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_EDGE_H_

#include <fstream>
#include <memory>
#include <graph/types.hpp>

namespace graph
{
    struct Edge
    {
        Node from;
        Node to;
        Edge() = default;
        Edge(Node from, Node to) : from(from), to(to) {}
        virtual bool read(std::istream& input)
        {
            return static_cast<bool>(input >> from >> to);
        }

        virtual void write(std::ostream& output)
        {
            output << from << to;
        }

        virtual Edge reverse() const
        {
            Edge e;
            e.to = from;
            e.from = to;
            return e;
        }

        bool operator==(const Edge& other) const
        {
            return from == other.from && to == other.to;
        }

        bool operator!=(const Edge& other) const
        {
            return !(*this == other);
        }
    };

    typedef std::shared_ptr<Edge> EdgePtr;
    typedef std::shared_ptr<const Edge> EdgeCPtr;
} // namespace graph
#endif