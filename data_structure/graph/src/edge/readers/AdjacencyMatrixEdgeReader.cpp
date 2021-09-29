#include <edge/readers/AdjacencyMatrixEdgeReader.hpp>
#include <edge/Edge.hpp>

namespace graph
{
    AdjacencyMatrixEdgeReader::AdjacencyMatrixEdgeReader(const AdjacencyMatrix &mat) : mat(mat), index(MatrixIndex(mat.get_node_count()))
    {
        next_edge(true);
        if (_can_read)
            _current_edge = std::make_shared<Edge>(index.i, index.j);
    }

    void AdjacencyMatrixEdgeReader::next_edge(bool include_current)
    {
        if (include_current && mat.has_edge(index.i, index.j))
        {
            return;
        }

        while (index.next())
        {
            if (mat.has_edge(index.i, index.j))
            {
                return;
            }
        }
        _can_read = false;
    }

    bool AdjacencyMatrixEdgeReader::increment()
    {
        if (!index.valid())
        {
            _can_read = false;
            return false;
        }
        next_edge(false);
        if (!index.valid())
        {
            _can_read = false;
            return false;
        }
        _current_edge = std::make_shared<graph::Edge>(index.i, index.j);
        return true;
    }

    EdgePtr AdjacencyMatrixEdgeReader::current_edge() const
    {
        return _current_edge;
    }

    bool AdjacencyMatrixEdgeReader::MatrixIndex::valid() const
    {
        return i < count && j < count;
    }

    bool AdjacencyMatrixEdgeReader::MatrixIndex::next()
    {
        j++;
        if (j >= count)
        {
            j = 0;
            i++;
        }
        return i < count;
    }
} // namespace graph
