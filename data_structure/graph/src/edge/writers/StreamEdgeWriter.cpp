#include <edge/writers/StreamEdgeWriter.hpp>

namespace graph
{
    StreamEdgeWriter::StreamEdgeWriter(std::ostream &out) : out(out) {}

    void StreamEdgeWriter::write(EdgePtr edg)
    {
        edge = edg;
    }

    void StreamEdgeWriter::increment()
    {
        edge->write(out);
    }
} // namespace graph
