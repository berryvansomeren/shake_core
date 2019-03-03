#ifndef INDEX_RANGE_HPP
#define INDEX_RANGE_HPP

#include <cstdint>
#include <iterator>

#include "core/ranges/range.hpp"

namespace shake {

//----------------------------------------------------------------
// Index iterator simply provides iterates from a begin index to an end index
// You could also create an index sequence,
// but this way you don;t have to keep a vector of indices in memory.
class IndexIterator
{
public:
    using index_t = std::size_t;

public:
    // iterator traits
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = index_t;
    using difference_type   = std::ptrdiff_t;
    using pointer           = index_t*;
    using reference         = index_t&;

public:

    explicit
    IndexIterator( index_t  index ) : m_current_index { index } { }

    const index_t& get_internal_index() const { return m_current_index; }

    IndexIterator&  operator++()       { ++m_current_index; return *this; }
    IndexIterator   operator++(int)    { IndexIterator result = *this; ++(*this); return result; }

    bool operator==(IndexIterator other) const { return get_internal_index() == other.get_internal_index(); }
    bool operator!=(IndexIterator other) const { return !(*this == other); }

    value_type operator*() const
    {
        return m_current_index; // should be replaced with std::invoke in c++17
    }

private:
    index_t m_current_index;
};

//----------------------------------------------------------------
using IndexRange = Range<IndexIterator>;

//----------------------------------------------------------------
IndexRange create_index_range
(
    const size_t& begin_index,
    const size_t& end_index
)
{
    return IndexRange
    {
        IndexIterator( begin_index ),
        IndexIterator( end_index )
    };
}

//----------------------------------------------------------------
IndexRange create_index_range
(
    const size_t& end_index
)
{
    return create_index_range( 0, end_index );
}



} // namespace shake

#endif // INDEX_RANGE_HPP
