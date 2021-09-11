#ifndef ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_STREAM_READER_H_
#define ALG_LIB_DATA_STRUCTURE_GRAPH_EDGE_STREAM_READER_H_

#include <fstream>

#include <edge/readers/EdgeReader.hpp>
#include <graph/types.hpp>

namespace graph
{
    class edge_stream_eof;

    template <typename TEdge>
    class StreamEdgeReader : public EdgeReader
    {
    private:
        SizeE count;
        SizeE read;
        std::istream &in;
        EdgePtr edge;
        bool _can_read;

    public:
        StreamEdgeReader(std::istream &in, SizeE count) : in(in),
                                                          count(count),
                                                          read(0),
                                                          _can_read(true)
        {

            if (count < 0)
            {
                _can_read = false;
                throw invalid_edge_count();
            }
            increment();
        }

        explicit StreamEdgeReader(std::istream &in) : in(in),
                                                      read(0),
                                                      _can_read(true)
        {
            if (!(in >> count))
            {
                _can_read = false;
                throw edge_stream_eof();
            }
            if (count < 0)
            {
                _can_read = false;
                throw invalid_edge_count();
            }
            increment();
        }

        bool increment()
        {
            if (read >= count)
            {
                _can_read = false;
                return false;
            }
            edge = std::make_shared<TEdge>();
            bool could_read = edge->read(in);
            if (!could_read)
            {
                throw edge_stream_eof();
            }

            read++;

            return read <= count;
        }

        EdgePtr current_edge() const
        {
            return edge;
        }

        bool can_read() const
        {
            return _can_read;
        }
    };

    class edge_stream_eof : std::exception
    {
        virtual const char *what() const noexcept
        {
            return "EdgeReader encountered EOF while trying to read edges";
        }
    };

} //namespace graph
#endif