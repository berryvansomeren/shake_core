#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <unordered_map>

#include "shake/core/contracts/contracts.hpp"

namespace shake {

template<typename Key_T, typename Value_T>
using Map = std::unordered_map<Key_T, Value_T>;

namespace map {

//----------------------------------------------------------------
// ordered map

//----------------------------------------------------------------
template<typename Key_T, typename Value_T>
inline bool has ( const std::map<Key_T, Value_T>& map, const Key_T& key )
{
    const auto it = map.find( key );
    return it != std::end( map );
}

//----------------------------------------------------------------
template<typename Key_T, typename Value_T>
inline bool erase_if_has ( std::map<Key_T, Value_T>& map, const Key_T& key )
{
    auto it = map.find( key );
    bool has = it != std::end( map );
    if ( has ) { map.erase( it ); }
    return !has;
}

//----------------------------------------------------------------
// unordered map

//----------------------------------------------------------------
template<typename Key_T, typename Value_T>
inline bool has ( const Map<Key_T, Value_T>& map, const Key_T& key )
{
    const auto it = map.find( key );
    return it != std::end( map );
}

//----------------------------------------------------------------
template<typename Key_T, typename Value_T>
inline bool erase_if_has ( Map<Key_T, Value_T>& map, const Key_T& key )
{
    auto it = map.find( key );
    bool has = it != std::end( map );
    if ( has ) { map.erase( it ); }
    return !has;
}

/*
//----------------------------------------------------------------
template<typename Key_T, typename Value_T>
inline void check_has ( const std::map<Key_T, Value_T>& map, const Key_T& key )
{
    const std::string message { "Map does not have expected key" };
    CHECK( has( map, key ), message );
}

//----------------------------------------------------------------
template<typename Key_T, typename Value_T>
inline void check_not_has ( const std::map<Key_T, Value_T>& map, const Key_T& key )
{
    const std::string message { "Map has unexpected key" };
    CHECK( !has( map, key ), message );
}
*/

} // namespace map
} // namespace shake

#endif // MAP_HPP
