#ifndef GDE_CORE_CONFIG_CREATE_HPP
#define GDE_CORE_CONFIG_CREATE_HPP

#include <string>
#include <fstream>
#include <SFML/System/NonCopyable.hpp>
#include <GDE/Config.hpp>

namespace GDE
{

	/**
	 * @brief Clase encargada de crear y modificar archivos de configuración.
	 * 
	 * Los archivos de configuración ("config-file") están en formato .ini, por lo que usan secciones,
	 * claves y valores.
	 * 
	 * Para modificar un archivo, primero se tiene que abrir con open():
	 * 
	 * GDE::ConfigCreate::open("config.ini");
	 * 
	 * Cuando se quiera cerrar el archivo ya abierto, se usa close():
	 * 
	 * GDE::ConfigCreate::close();
	 */
class GDE_API ConfigCreate : sf::NonCopyable
{
public:

		/**
		 * @brief Constructor del editor de configuración ConfigCreate.
		 * 
		 * Idealmente debe haber uno por archivo.
		 */
	ConfigCreate();

        /**
         * @brief Destructor del editor de configuración ConfigCreate.
         */
	~ConfigCreate();

		/**
		 * @brief Función para cargar un archivo de configuración.
		 * 
		 * @param[in] theFilename El nombre del archivo de configuración a cargar.
		 */
	void open(const std::string& theFilename);

		/**
		 * @brief Función para cerrar un archivo de configuración.
		 * 
		 * El archivo no se podrá seguir editando cuando se cierre, a menos que se abra de nuevo con open().
		 */
	void close();

		/**
		 * @brief Función para añadir una nueva sección al archivo de configuración.
		 * 
		 * Las secciones se usan para separar contextos en los archivos de configuración .ini.
		 * Para añadir una sección "General" se escribe:
		 * 
		 * putSection("General");
		 * 
		 * Una sección está marcado por un corchete de apertura, un nombre, el cierre de los corchetes y 
		 * un salto de linea. La sección llamada "General", se escribiría en el archivo así:
		 * 
		 * [General]
		 * 
		 * @note Para evitar incompatibilidades, no se deben escribir los parámetros con acentos, cremas o eñes;
		 * se debe escribir en Inglés.
		 * 
		 * @param[in] theSection El nombre de la sección a añadir.
		 */
	void putSection(const std::string& theSection);

		/**
		 * @brief Función para escribir una clave ("key" o "keyvalue") y un valor al archivo de configuración.
		 * 
		 * Una clave es el nombre de la opción a ser modificada, mientras que el valor es el dato que lleva
		 * esa configuración u opción.
		 * 
		 * Un ejemplo de clave-valor en un archivo .ini es:
		 * 
		 * color=red
		 * 
		 * Donde "color" es la clave y "red" es el valor. Esto se puede escribir en el archivo de configuración con
		 * la función putValue():
		 * 
		 * GDE::ConfigCreate::putValue("color", "red");
		 * 
		 * @note Para evitar incompatibilidades, no se deben escribir los parámetros con acentos, cremas o eñes;
		 * se debe escribir en Inglés.
		 * 
		 * @param[in] theKey La clave a escribir.
		 * @param[in] theValue El valor de la clave.
		 */
	void putValue(const std::string& theKey, const std::string& theValue);

		/**
		 * @brief Función para escribir un comentario en el archivo de configuración.
		 * 
		 * En los archivos de configuración, los comentarios son ignorados y sirven para explicar algo o añadir un
		 * poco más de información acerca de algo en el archivo. Los comentarios van por un "#" hasta el final de
		 * la linea.
		 * 
		 * Un ejemplo de un comentario es:
		 * 
		 * # Éste es un comentario.
		 * 
		 * Para escribir ese último ejemplo usando la función putComment(), se escribe:
		 * 
		 * GDE::ConfigCreate::putComment("Éste es un comentario.");
		 * 
		 * Dado que los comentarios son ignorados por el lector de archivos de configuración, pueden contener
		 * acentos, cremillas o eñes y van escritos en Español.
		 * 
		 * @param[in] theComment El comentario a agregar.
		 */
	void putComment(const std::string& theComment);

		/**
		 * @brief Función para añadir una linea vacía al archivo de configuración
		 * 
		 * Las lineas vacías son ignoradas por el lector de archivos de configuración y usualmente sirven para
		 * tener un orden visual en el archivo.
		 * 
		 * Para agregar un espacio vacío, se escribe:
		 * 
		 * GDE::ConfigCreate::putBlankLine();
		 */
	void putBlankLine();

private:
		/**
		 * @brief Variable del archivo de configuración abierto por la instancia de la clase.
		 */
	std::ofstream file;

}; // class ConfigCreate

} // namespace GDE

#endif // GDE_CORE_CONFIG_CREATE_HPP
