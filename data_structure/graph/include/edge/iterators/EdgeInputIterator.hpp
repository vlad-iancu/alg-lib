#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_INPUT_ITERATOR_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_INPUT_ITERATOR_H_

#include <edge/readers/EdgeReader.hpp>
#include <memory>
#include <iostream>
#include <iterator>

namespace graph
{
    class EdgeInputIterator: public std::iterator<std::input_iterator_tag, EdgePtr>
    {
    private:
        EdgeReaderPtr reader;
        bool can_read;
        EdgeInputIterator() = default;
    public:

        explicit EdgeInputIterator(EdgeReaderPtr reader) :
            reader(reader),
            can_read(true)
        {}

        EdgePtr operator*()
        {
            return reader->current_edge();
        }

        EdgePtr operator->()
        {
            return reader->current_edge();
        }

        EdgeInputIterator operator++()
        {
            can_read = reader->increment();
           // std::cout << "can_read = " << can_read << std::endl;
            return *this;
        }

        EdgeInputIterator operator++(int)
        {
          //  std::cout << "Incrementing the iterator: ";
            EdgeInputIterator tmp(*this);
            can_read = reader->increment();
          //  std::cout << "can_read = " << can_read << std::endl;
            return tmp;
        }

        bool operator==(const EdgeInputIterator& it) const
        {
            if (!can_read && !it.can_read)
                return true;
            if (can_read != it.can_read)
                return false;
            return (*it.reader->current_edge()) == (*reader->current_edge());
        }

        bool operator!=(const EdgeInputIterator& it) const
        {
            return !(it == *this);
        }

        static EdgeInputIterator end()
        {
            EdgeInputIterator it;
            it.can_read = false;
            return it;
        }
    };

} // namespace graph

#endif