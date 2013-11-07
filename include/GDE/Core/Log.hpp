#ifndef GDE_CORE_LOG_HPP
#define GDE_CORE_LOG_HPP

#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

namespace GDE
{
    
class Log{
public:

    /**
     * Función para inicializar el sistema de logs. 
     */

    static void init();
    
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
     
    
private:
    static std::string logFileName;
    static time_t rawtime;
    static bool initialized;
};
}




#endif // GDE_CORE_LOG_HPP
