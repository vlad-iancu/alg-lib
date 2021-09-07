#ifndef ALG_LIB_DATA_STRUCTURE_EDGE_READER_PROVIDER_H_
#define ALG_LIB_DATA_STRUCTURE_EDGE_READER_PROVIDER_H_

#include <memory>

namespace graph
{
    template<typename TEdge>
    class EdgeReader
    {
    public:
        virtual bool increment() = 0;
        virtual TEdge current_edge() const = 0;
    };

    template <typename TEdge>
    using EdgeReaderPtr = std::shared_ptr<EdgeReader<TEdge>>;
}
#endif