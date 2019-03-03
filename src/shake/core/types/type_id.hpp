#ifndef TYPE_ID_HPP
#define TYPE_ID_HPP

//#include <cstddef>

#include <typeindex>
#include <typeinfo>

namespace shake {

// TypeId is put into a namespace because you generally never want to use a raw type_id.
// Instead, you probably want to create a strongly typed alias,
// to limit the kinds of types you expect.
namespace type_id {

using TypeId = std::type_index;

//----------------------------------------------------------------
// Used to get a unique identifier for each type.
// Every time the function is called with the same template parameter,
// the same static type id is returned.
template <typename T>
static TypeId get()
{
    return std::type_index( std::type_index( typeid(T) ) );
}

//----------------------------------------------------------------
// Alternative implementation below,
// which could be useful in case we need a consecutive index sequence,
// for example because we use the type_index to index an array.
/*
using TypeId = size_t;

//----------------------------------------------------------------
// hidden counter to keep track of next type id
namespace detail {

TypeId g_next_type_id { 0 };

} // namespace detail

//----------------------------------------------------------------
// Used to get a unique identifier for each type.
// Every time the function is called with the same template parameter,
// the same static type id is returned.
template <typename T>
static TypeId get()
{
    static const TypeId id = detail::g_next_type_id;
    detail::g_next_type_id++;
    return id;
}
*/

} // namespace type_id
} // namespace shake

#endif // TYPE_ID_HPP
