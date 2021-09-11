#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_WRITER_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_WRITER_H_

#include <edge/Edge.hpp>
#include <memory>

namespace graph
{
    class EdgeWriter
    {
    public:
        virtual EdgePtr& get_edge() = 0;
        virtual void increment() = 0;
    };

    typedef std::shared_ptr<EdgeWriter> EdgeWriterPtr;
}
#endif