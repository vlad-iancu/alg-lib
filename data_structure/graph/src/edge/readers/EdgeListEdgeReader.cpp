#include <edge/readers/EdgeListEdgeReader.hpp>

namespace graph
{
    EdgeListEdgeReader::EdgeListEdgeReader(const EdgeList &graph)
        : graph(graph),
          _can_read(true),
          index(0)
    {
        if (graph.edge_count() == 0)
            _can_read = false;
    }

    bool EdgeListEdgeReader::increment()
    {
        if (index >= graph.edge_count())
            return false;
        index++;
        _can_read = index < graph.edge_count();
        return _can_read;
    }

    EdgePtr EdgeListEdgeReader::current_edge() const
    {
        return graph.get(index);
    }

    bool EdgeListEdgeReader::can_read() const
    {
        return _can_read;
    }

} // namespace graph
