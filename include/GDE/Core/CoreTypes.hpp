#ifndef GDE_CORE_TYPES_HPP
#define GDE_CORE_TYPES_HPP

#include <map>
#include <string>

namespace GDE
{
	
// Fowards Declarations
class App;
class Scene;
class SceneManager;
class ConfigReader;
class ConfigCreate;
	
// Tipos de Log
enum LogType
{
	infoLevel = 0,
	debugLevel = 1,
	errorLevel = 2,
	warningLevel = 3
};

/// Enumaración con los posibles valores de retorno de la Aplicación
enum StatusType
{
	// Values from -99 to 99 are common Error and Good status responses
	StatusAppMissingAsset = -4,  ///< Application failed due to missing asset file
	StatusAppStackEmpty = -3,  ///< Application States stack is empty
	StatusAppInitFailed = -2,  ///< Application initialization failed
	StatusError = -1,  ///< General error status response
	StatusAppOK = 0,  ///< Application quit without error
	StatusNoError = 0,  ///< General no error status response
	StatusFalse = 0,  ///< False status response
	StatusTrue = 1,  ///< True status response
	StatusOK = 1   ///< OK status response

	// Values from +-100 to +-199 are reserved for File status responses
};

/// Tipo de dato para identidicar las escenas
typedef std::string sceneID;


/// Declare NameValue typedef which is used for config section maps
typedef std::map<const std::string, const std::string> typeNameValue;

/// Declare NameValueIter typedef which is used for name,value pair maps
typedef std::map<const std::string, const std::string>::iterator typeNameValueIter;

} // namespace GDE

#endif // GDE_CORE_TYPES_HPP
