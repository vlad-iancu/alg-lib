#ifndef ALG_LIB_DATA_STRUCTURE_STREAM_EDGE_WRITER_H_
#define ALG_LIB_DATA_STRUCTURE_STREAM_EDGE_WRITER_H_

#include <edge/Edge.hpp>
#include <edge/writers/EdgeWriter.hpp>

namespace graph {
    class StreamEdgeWriter : public EdgeWriter
    {
    private:
        std::ostream& out;
        EdgePtr edge;
        
    public:
        StreamEdgeWriter(std::ostream& out) :
            out(out)
        {}

        void write(EdgePtr edg)
        {
            edge = edg;
        }

        void increment()
        {
            edge->write(out);
        }
    };
} //namespace graph

#endif