#ifndef GDE_CORE_TYPES_HPP
#define GDE_CORE_TYPES_HPP

#include <map>
#include <string>

namespace GDE
{

/// Declare NameValue typedef which is used for config section maps
typedef std::map<const std::string, const std::string> typeNameValue;

/// Declare NameValueIter typedef which is used for name,value pair maps
typedef std::map<const std::string, const std::string>::iterator typeNameValueIter;

} // namespace GDE

#endif // GDE_CORE_TYPES_HPP