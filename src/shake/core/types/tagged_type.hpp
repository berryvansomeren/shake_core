#ifndef TAGGED_TYPE_HPP
#define TAGGED_TYPE_HPP

#include "shake/core/types/macro_property.hpp"

namespace shake {

//----------------------------------------------------------------
// Used to create strongly typed aliases.
// Simply create a tag type like struct FooTag { };
// and use it to tag an already existing type, to avoid accidental mixups
template<typename Value_T, typename Tag_T>
class tagged_type
{
public:
    using value_type    = Value_T;
    using reference     = value_type&;
    using tag_type      = Tag_T;

public:
    explicit tagged_type( const Value_T& value )
        : m_value { value }
    { }

    reference operator*() { return m_value; }

    value_type* operator->() { return &m_value; }

private:
    PROPERTY_R( value_type, value )
};

//----------------------------------------------------------------
// We need to overwrite the equals operator
// because it is used for example by reverse_iterator
template<typename Value_T, typename Tag_T>
bool operator == ( const tagged_type<Value_T, Tag_T>& lhs, const tagged_type<Value_T, Tag_T>& rhs)
{
    return lhs.get_value() == rhs.get_value();
}

//----------------------------------------------------------------
// We need to overwrite the less than operator
// because we intend to use tagged types a map keys
template<typename Value_T, typename Tag_T>
bool operator < ( const tagged_type<Value_T, Tag_T>& lhs, const tagged_type<Value_T, Tag_T>& rhs)
{
    return lhs.get_value() < rhs.get_value();
}

} // namespace shake

#endif // TAGGED_TYPE_HPP
