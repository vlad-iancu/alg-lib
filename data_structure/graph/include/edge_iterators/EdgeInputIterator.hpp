#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_INPUT_ITERATOR_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_INPUT_ITERATOR_H_

#include <iterator>
#include <type_traits>
#include <fstream>

#include <edge/Edge.hpp>

namespace graph
{
    template <typename T>
    constexpr bool IsEdge = false;

    template <>
    constexpr bool IsEdge<Edge> = true;

    template <typename T, typename std::enable_if<std::is_base_of<Edge, T>::value>::type * = nullptr>
    class EdgeInputIterator
    {
    private:
        typedef EdgeInputIterator Iterator public : using iterator_category = std::input_iterator_tag;
        T edge;
        using difference_type = std::ptrdiff_t;
        using value_type = Edge;
        using pointer = T *;
        using reference = T &;

        reference operator*() const { return edge; }
        pointer operator->() { return &edge; }

        virtual Iterator &operator++() = 0;
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator &it1, const Iterator &it2);
        friend bool operator!=(const Iterator &it1, const Iterator &it2);
    };
}
#endif