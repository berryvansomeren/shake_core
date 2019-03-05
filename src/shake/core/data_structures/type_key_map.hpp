#ifndef TYPE_KEY_MAP_HPP
#define TYPE_KEY_MAP_HPP

#include <unordered_map>

#include "shake/core/types/type_id.hpp"

namespace shake {

//----------------------------------------------------------------
template< Value_T >
class TypeKeyMap
{
public:
    using key_type      = type_id::TypeId;
    using value_type    = Value_T;
    using pair_type     = std::pair<const left_type, const right_type>;

public:

    template<typename Key_T>
    void emplace( const value_type& value )
    {
        m_map.emplace( type_id::get<Key_T>(), value );
    }

    template<typename Key_T>
    Value_T at()
    {
        return m_map.at( type_id::get<Key_T>() );
    }

private:
    std::unordered_map<key_type, value_type> m_map;
};

} // namespace shake

#endif // TYPE_KEY_MAP_HPP
