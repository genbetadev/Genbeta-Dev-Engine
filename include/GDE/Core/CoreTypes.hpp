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
	
/// Nivel o tipo de Log
enum LogLevel
{
	Debug = 0,
	Info = 1,
	Warning = 2,
	Error = 3
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


/// Almacena el número de línea, nombre de archivo y nombre de función.
struct SourceContext
{
	SourceContext (const char *file, unsigned int line, const char *function)
	: file(file)
	, line(line)
	, function(function)
	{ }

	const char *file;
	const int line;
	const char *function;
};


typedef void (*LogHandler) (std::ostream &os,
									 GDE::LogLevel level,
									 const std::string &message,
									 const std::string &date,
									 const std::string &time,
									 const GDE::SourceContext &context
									);

} // namespace GDE

#endif // GDE_CORE_TYPES_HPP
