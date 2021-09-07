#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_INPUT_ITERATOR_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_INPUT_ITERATOR_H_

#include <edge/readers/EdgeReader.hpp>
#include <memory>

namespace graph
{
    template<typename TEdge>
    class EdgeInputIterator
    {
    private:
        EdgeReaderPtr<TEdge> reader;
        bool can_read;
        EdgeInputIterator() = default;
    public:
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = TEdge;
        using pointer = TEdge*;
        using reference = TEdge&;

        explicit EdgeInputIterator(EdgeReaderPtr<TEdge> reader) :
            reader(reader),
            can_read(true)
        {
            (*this)++;
        }

        value_type operator*()
        {
            return reader->current_edge();
        }

        pointer operator->()
        {
            return &reader->current_edge();
        }

        EdgeInputIterator<TEdge>& operator++()
        {
            can_read = reader->increment();
            return *this;
        }

        EdgeInputIterator<TEdge> operator++(int)
        {
            EdgeInputIterator<TEdge> tmp(*this);
            can_read = reader->increment();
            return tmp;
        }

        bool operator==(const EdgeInputIterator<TEdge>& it) const
        {
            if (!can_read && !it.can_read)
                return true;
            if (can_read != it.can_read)
                return false;
            return it.reader->current_edge() == reader->current_edge();
        }

        bool operator!=(const EdgeInputIterator<TEdge>& it) const
        {
            return !(it == *this);
        }

        static EdgeInputIterator<TEdge> end()
        {
            EdgeInputIterator<TEdge> it;
            it.can_read = false;
            return it;
        }
    };

} // namespace graph

#endif