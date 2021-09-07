#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_STREAM_READER_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_STREAM_READER_H_

#include <fstream>

#include <edge/readers/EdgeReader.hpp>

namespace graph
{
    template<typename TEdge>
    class EdgeStreamReader : public EdgeReader<TEdge>
    {
    private:
        int count;
        int read;
        std::istream& in;
        TEdge edge;
    public:
        EdgeStreamReader(std::istream& in, int count) :
            in(in),
            count(count),
            read(0)
        {}

        explicit EdgeStreamReader(std::istream& in) :
            in(in),
            read(0)
        {
            in >> count;
        }

        bool increment()
        {
            if(read >= count) return false;
            edge.read(in);
            read++;
            return read < count;
        }

        TEdge current_edge() const
        {
            return edge;
        }
    };
} //namespace graph
#endif