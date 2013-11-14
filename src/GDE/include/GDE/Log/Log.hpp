#ifndef GDE_CORE_LOG_HPP
#define GDE_CORE_LOG_HPP

#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

#include "config.hpp"

namespace GDE
{
	// Tipos de Log
	enum LogType
	{
		infoLevel = 0,
		debugLevel = 1,
		errorLevel = 2,
		warningLevel = 3
	};
	
	/**
	 * Clase que ofrece funcionalidad para almacenar información en un log.
	 * 
	 * Es una clase con miembros estáticos por tanto no es necesario crear instancias
	 * de la clase.
	 * 
	 * La forma correcta de usar la clase es inicializando el módulo de la siguiente manera:
	 * 
	 * GDE::Log::init("/home/usuario/log.txt");
	 * 
	 * Una vez inicializado el módulo ya se puede escribir en el log mediante:
	 * 
	 * GDE::Log::info("AssetManager","Cargando texturas");
	 * GDE::Log::debug("AssetManager","Cargando texturas");
	 * GDE::Log::error("AssetManager","No se pudieron cargar las texturas");
	 * 
	 */
	
class GDE_API Log {
public:

    /**
     * Función para inicializar el sistema de logs. 
	 * 
	 * @param logFileName ruta del log a escribir
     */

    static void init(std::string logFileName);
    
    /**
     * Función para escribir en el log información. Para hacer uso
     * de dicha función hay que inicializar previamente el sistema.
     * 
     * @param tag Etiqueta de la línea a escribir.
     * @param text texto a escribir.
     */
     
    static void info(std::string tag, std::string text);
    
    /**
     * Función para escribir en el log información de depuración. Para hacer uso
     * de dicha función hay que inicializar previamente el sistema.
     * 
     * @param tag Etiqueta de la línea a escribir.
     * @param text texto a escribir.
     */
     
    static void debug(std::string tag, std::string text);
    
    /**
     * Función para escribir en el log errores. Para hacer uso
     * de dicha función hay que inicializar previamente el sistema.
     * 
     * @param tag Etiqueta de la línea a escribir.
     * @param text texto a escribir.
     */
     
    static void error(std::string tag, std::string text);
	
	/**
     * Función para escribir en el log advertencias. Para hacer uso
     * de dicha función hay que inicializar previamente el sistema.
     * 
     * @param tag Etiqueta de la línea a escribir.
     * @param text texto a escribir.
     */
     
    static void warning(std::string tag, std::string text);
     
    
private:
  
    /**
     * Función base para escribir en el log
     * 
     * @param tag Etiqueta de la línea a escribir.
     * @param text texto a escribir.
     * @param logType encabezado del log
     */
    static void log(std::string tag, std::string text, int logType);
  
    static time_t rawtime;
    static bool initialized;
    static std::string logFileName;
    static std::string header[];
}; // class Log


} // namespace GDE

#endif // GDE_CORE_LOG_HPP
