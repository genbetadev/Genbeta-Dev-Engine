#ifndef GDE_CORE_TYPES_HPP
#define GDE_CORE_TYPES_HPP

#include <map>
#include <string>

namespace GDE { namespace Core
{
	
// Fowards Declarations
class App;
class Scene;
class SceneManager;
class ConfigReader;
class ConfigCreate;


/// Tipo de dato para identidicar las escenas
typedef std::string sceneID;


/// Declare NameValue typedef which is used for config section maps
typedef std::map<const std::string, const std::string> typeNameValue;

/// Declare NameValueIter typedef which is used for name,value pair maps
typedef std::map<const std::string, const std::string>::iterator typeNameValueIter;

} }// namespace GDE::Core

#endif // GDE_CORE_TYPES_HPP
