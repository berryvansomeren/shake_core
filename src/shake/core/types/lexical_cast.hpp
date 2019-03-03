#ifndef LEXICAL_CAST_HPP
#define LEXICAL_CAST_HPP

#include "shake/core/data_structures/string.hpp"

namespace shake {

//----------------------------------------------------------------
// Used to cast things to strings
template<typename T>
inline std::string lexical_cast ( const T& t ) { return std::to_string( t ); }

//----------------------------------------------------------------
// Used to cast strings to things
template<typename R>    inline R        lexical_cast            ( const std::string& s );
template<>              inline int      lexical_cast<int>       ( const std::string& s )    { return std::stoi( s ); }
template<>              inline float    lexical_cast<float>     ( const std::string& s )    { return std::stof( s ); }
template<>              inline double   lexical_cast<double>    ( const std::string& s )    { return std::stod( s ); }

} // namespace shake

#endif // LEXICAL_CAST_HPP
