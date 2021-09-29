#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_OUTPUT_ITERATOR_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_OUTPUT_ITERATOR_H_

#include <iterator>

#include <edge/Edge.hpp>
#include <edge/writers/EdgeWriter.hpp>

namespace graph
{
    class EdgeOutputIterator : public std::iterator<std::output_iterator_tag, EdgePtr>
    {
    private:
        EdgeWriterPtr writer;

    public:
        EdgeOutputIterator(EdgeWriterPtr writer) : writer(writer) {}

        EdgePtr &operator*()
        {
            return writer->get_edge();
        }

        EdgeOutputIterator &operator++()
        {
            writer->increment();
            return *this;
        }

        EdgeOutputIterator operator++(int)
        {
            EdgeOutputIterator tmp(*this);
            ++(*this);
            return tmp;
        }
    };

} // namespace graph

#endif