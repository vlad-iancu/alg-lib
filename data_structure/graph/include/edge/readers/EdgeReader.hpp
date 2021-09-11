#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_READER_PROVIDER_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_READER_PROVIDER_H_

#include <memory>
#include <edge/Edge.hpp>
namespace graph
{
    class EdgeReader
    {
    public:
        virtual bool increment() = 0;
        virtual EdgePtr current_edge() const = 0;
        virtual bool can_read() const = 0;
    };

    typedef std::shared_ptr<EdgeReader> EdgeReaderPtr;

    class invalid_edge_count : std::exception
    {
    public:
        virtual const char* what() const noexcept
        {
            return "The edge count must be a non-negative integer";
        }
    };

}
#endif