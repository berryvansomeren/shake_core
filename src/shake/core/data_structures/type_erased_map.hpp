#ifndef TYPE_ERASED_MAP_HPP
#define TYPE_ERASED_MAP_HPP

#include <any>

#include "shake/core/types/type_key_map.hpp"

namespace shake {

//----------------------------------------------------------------
class TypeErasedMap
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
    TypeKeyMap< std::any > m_map;
};

} // namespace shake

#endif // TYPE_ERASED_MAP_HPP
