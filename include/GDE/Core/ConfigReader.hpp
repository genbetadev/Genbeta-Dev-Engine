#ifndef GDE_CORE_CONFIG_READER_HPP
#define GDE_CORE_CONFIG_READER_HPP

#include <string>
#include <map>
#include <SFML/Config.hpp>
#include <GDE/Config.hpp>
#include <GDE/Core/CoreTypes.hpp>

namespace GDE
{

class GDE_API ConfigReader
{
public:

    /**
     * Constructor de la clase.
     */
	ConfigReader();
    
    /**
     * Constructor de copia de la clase.
     * 
     * @param theCopy Objeto ConfigReader a copiar.
     */

	ConfigReader(const ConfigReader& theCopy);

    /**
     * Redefinición del operador "=".
     * 
     * @param theRight Lado derecho de la asignación.
     * 
     * @return Devuelve un puntero al objeto.
     */

	ConfigReader& operator=(const ConfigReader& theRight);

    /**
     * Destructor de la clase.
     */

	~ConfigReader();

    /**
     * Función para cargar un archivo.
     * 
     * @param filename Archivo a abrir.
     * 
     * @return Devuelve True en caso de éxito y False en caso contrario.
     */

	bool loadFromFile(const std::string& filename);

    /**
     * Función que comprueba si una sección está vacía.
     * 
     * @param theSection Sección a comprobar.
     * 
     * @return Devuelve True en caso de que la sección esté vacía y False en caso contrario.
     */

	bool isSectionEmpty(const std::string theSection) const;

    /**
     * Función para obtener un booleano del fichero leído.
     * 
     * @param theSection Sección donde se encuentra el booleano.
     * @param theName Clave del booleano a leer.
     * @param theDefault Valor por defecto en caso de que la clave no exista.
     * 
     * @return Devuelve el resultado encontrado, en caso de no haber coincidencias se devuelve theDefault.
     */

	bool getBool(const std::string theSection, const std::string theName, const bool theDefault = false) const;

    /**
     * Función para obtener un float del fichero leído.
     * 
     * @param theSection Sección donde se encuentra el float.
     * @param theName Clave del float a leer.
     * @param theDefault Valor por defecto en caso de que la clave no exista.
     * 
     * @return Devuelve el resultado encontrado, en caso de no haber coincidencias se devuelve theDefault.
     */

	float getFloat(const std::string theSection, const std::string theName, const float theDefault = 0.f) const;

    /**
     * Función para obtener un string del fichero leído.
     * 
     * @param theSection Sección donde se encuentra el string.
     * @param theName Clave del string a leer.
     * @param theDefault Valor por defecto en caso de que la clave no exista.
     * 
     * @return Devuelve el resultado encontrado, en caso de no haber coincidencias se devuelve theDefault.
     */
    
	std::string getString(const std::string theSection, const std::string theName, const std::string theDefault = "") const;

    /**
     * Función para obtener un uint32 del fichero leído.
     * 
     * @param theSection Sección donde se encuentra el uint32.
     * @param theName Clave del uint32 a leer.
     * @param theDefault Valor por defecto en caso de que la clave no exista.
     * 
     * @return Devuelve el resultado encontrado, en caso de no haber coincidencias se devuelve theDefault.
     */

	sf::Uint32 getUint32(const std::string theSection, const std::string theName, const sf::Uint32 theDefault = 0) const;

private:
	// CONSTANTES
	static const unsigned short MAX_CHARS = 100;
	// VARIABLES
    // Mapa para almacenar todas las secciones con sus correspondientes pares <clave,valor>
	std::map<const std::string, GDE::typeNameValue*> sections;

	std::string parseLine(const char* theLine, const unsigned long theCount,const std::string theSection);

	void storeNameValue(const std::string theSection, const std::string theName, const std::string theValue);

}; // clase ConfigReader

} // namespace GDE

#endif // GDE_CORE_CONFIG_READER_HPP