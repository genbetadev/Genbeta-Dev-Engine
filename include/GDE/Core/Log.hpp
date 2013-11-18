#ifndef GDE_CORE_LOG_HPP
#define GDE_CORE_LOG_HPP

#include <GDE/Config.hpp>
#include <GDE/Core/CoreTypes.hpp>
#include <sstream>
#include <ctime>

namespace GDE
{
	/**
	 * @brief Clase que permite almacenar información en un log usando streams.
	 *
	 * @section init Inicializando los registros
	 *
	 * Antes de poder usar el sistema de registro, debe llamar al método estático GDE::Log::init()
	 * el cual pide como argumento una referencia a un objeto de tipo @c std::ostream en donde
	 * se imprimirá el registro. Todo objeto de tipo @c std::ostream o uno de sus derivados
	 * son válidos, pero las opciones más normales son:
	 * @li @c std::fstream para escribir en un archivo
	 * @li @c std::stringstream para escribir en una cadena de texto
	 * @li @c std::cout o @c std::cerr para escribir directamente en la salida estándar
	 *
	 * Si decide usar un archivo, debe crear una instancia de un objeto @c std::fstream y abrir
	 * el archivo para escritura en modo texto (normalmente usando el modo @c std::ios::app).
	 * <b>ES MUY IMPORTANTE QUE EL OBJETO PERMANEZCA VÁLIDO Y EL ARCHIVO NO SEA CERRADO.</b>
	 * Por ejemplo, para usar un archivo llamado "logs.txt":
	 *
	 * @code
	 * int main ()
	 * {
	 *     std::ofstream file ("logs.txt", std::ios::app);
	 *     GDE::Log::init (file);
	 *
	 *     // ...
	 *     // file debe permanecer abierto mientras se use Log
	 *
	 *     GDE::Log::close();
	 *     file.close();
	 *     return 0;
	 * }
	 * @endcode
	 *
	 * Nunca haga algo como esto:
	 *
	 * @code
	 * SuperClass::SuperClass()  // constructor de la clase SuperClass
	 * {
	 *     std::ofstream file ("logs.txt", std::ios::app);
	 *     GDE::Log::init (file);
	 * }
	 * @endcode
	 *
	 * En el código anterior el objeto @e file solo existe dentro del constructor y será
	 * destruido automáticamente cuando el constructor termine, dejando la clase GDE::Log en un
	 * estado indeterminado. Si realmente desea inicializar los registros dentro de una clase,
	 * debe hacer algo similar a:
	 *
	 * @code
	 * class SuperClass
	 * {
	 * public:
	 *     SuperClass();
	 *     ~SuperClass();
	 *
	 * private:
	 *     std::ofstream file;
	 * }
	 *
	 * SuperClass::SuperClass()
	 * {
	 *     file.open ("logs.txt", std::ios:app);
	 *     GDE::Log::init (file);
	 * }
	 *
	 * SuperClass::~SuperClass()
	 * {
	 *     file.close();
	 *     GDE::Log::close();
	 * }
	 * @endcode
	 *
	 * La diferencia radica en que ahora @e file es un miembro de la clase, y como tal, su vida
	 * se prolonga hasta que el objeto de tipo @e SuperClass sea destruido. Este es un buen momento
	 * para llamar al método GDE::Log::close().
	 *
	 * Tenga en cuenta que la responsabilidad de la correcta apertura del archivo recae en usted.
	 * Debe comprobar que el archivo se haya abierto correctamente antes de entregar el parámetro al
	 * método GDE::Log::init().
	 *
	 * Si desea utilizar @c std::cerr como objeto de salida, simplemente llame al método GDE::Log::init()
	 * del siguiente modo:
	 *
	 * @code
	 * GDE::Log::init(std::cerr);
	 * @endcode
	 *
	 * De este modo, todos los mensajes irán a parar a la salida estándar de errores.
	 *
	 *
	 * @section using Escribiendo registros
	 *
	 * No intente crear un objeto de tipo GDE::Log manualmente, en cambio, haga uso de las macros
	 * GDE_LOG_INFO, GDE_LOG_DEBUG, GDE_LOG_WARNING y GDE_LOG_ERROR.
	 *
	 * Ejemplos:
	 * @code
	 * GDE_LOG_DEBUG("SceneManager: Constructor llamado";
	 * GDE_LOG_INFO("VSync:" << this->vsync);
	 * GDE_LOG_WARNING("El valor de a =" << a << "es mayor que b =" << b);
	 * GDE_LOG_INFO("Resolución:" << GDE::Log::nospace << videoMode.width << "x" << videoMode.height);
	 * @endcode
	 *
	 * Escribiría algo similar a:
	 * @code
	 * 21:20:34 DEBUG: SceneManager: Constructor llamado
	 * 21:20:34 INFO: VSync: true
	 * 21:20:34 WARNING: El valor de a = 7 es mayor que b = 3
	 * 21:20:34 INFO: Resolución: 800x600
	 * @endcode
	 *
	 * Note que no es necesario colocar explícitamente una nueva línea en el flujo. El caracter @e \\n
	 * será colocado automáticamente. También debe notar que no es necesario dejar un espacio en blanco
	 * entre los valores, esto se hace automáticamente por defecto. Este comportamiento puede ser
	 * cambiado usando los manipuladores space y nospace.
	 *
	 * La macro GDE_LOG_ERROR imprime además el nombre de archivo y número de línea
	 * donde ocurrió el error.
	 *
	 *
	 * @section custom_debug Información de depuración para tipos de datos personalizados
	 *
	 * La clase GDE::Log hace un uso extensivo de @c std::stringstream, por tanto todos los tipos de
	 * datos aceptados por este pueden usarse en GDE::Log. Sin embargo, muchas veces resulta útil
	 * sobrecargar @c operator<< para usar los streams sobre clases nuevas.
	 *
	 * En el siguiente ejemplo asumimos que usted tiene una clase llamada @e MyPoint la cual representa
	 * un punto a través de sus coordenadas x e y. La implementación para el operador será similar a la
	 * siguiente:
	 *
	 * @code
	 * GDE::Log& operator<< (GDE::Log& stream, const MyPoint &p)
	 * {
	 *     using namespace GDE;
	 *
	 *     stream << Log::nospace << "(" << p.x() << ", " << p.y() << ")";
	 *     stream << Log::space;
	 *     return stream;
	 * }
	 *
	 * // ...
	 *
	 * MyPoint pos(10, 34);
	 * GDE_LOG_INFO("Posición del personaje:" << pos);
	 * @endcode
	 *
	 *
	 * @section custom_handler Personalizando la forma en que se imprimen los mensajes
	 *
	 * LA FUNCIONALIDAD DESCRITA EN ESTA SECCIÓN AUN NO ESTÁ COMPLETAMENTE IMPLEMENTADA.
	 *
	 * La clase GDE::Log le permite modificar la forma en que se escriben los mensajes instalando
	 * un controlador (handler) personalizado. Para crear su propio controlador debe crear una función
	 * con exactamente estos argumentos:
	 *
	 * @code
	 * void myLogHandler (std::ostream &os,
	 *                    GDE::LogLevel level,
	 *                    const std::string &message,
	 *                    const std::string &date,
	 *                    const std::string &time,
	 *                    const GDE::SourceContext &context
	 *                   )
	 * {
	 *
     * }
	 * @endcode
	 *
	 * El objeto de tipo @c std::ostream es el lugar donde debe escribir todos los mensajes. El parámetro
	 * @e level es uno de los valores: GDE::Debug, GDE::Info, GDE::Warning o GDE::Error. @e message es el
	 * mensaje que la clase GDE::Log ha formateado. @e date es un texto que almacena la fecha actual y
	 * @e time es un texto que almacena la hora actual. El parámetro @e context es una estructura que
	 * contiene los miembros: @e file y @e line, que representan el nombre de archivo y número
	 * de línea donde ocurrió la llamada.
	 *
	 * Un ejemplo de un controlador de mensajes personalizado podría ser como el siguiente:
	 *
	 * @code
	 * void myLogHandler (std::ostream &os,
	 *                    GDE::LogLevel level,
	 *                    const std::string &message,
	 *                    const std::string &date,
	 *                    const std::string &time,
	 *                    const GDE::SourceContext &context
	 *                   )
	 * {
	 *     switch (level)
	 *     {
	 *     case GDE::Debug:
	 *         os << time << ": " << "DEBUG: " << message;
	 *         break;
	 *
	 *     case GDE::Info:
	 *         os << time << ": " << "INFO: " << message;
	 *         break;
	 *
	 *     case GDE::Warning:
	 *         os << time << ": " << context.file << ":" << context.line << ": ";
	 *         os << "WARNING: " << message;
	 *         break;
	 *
	 *     case GDE::Error:
	 *         os << time << ": " << context.file << ":" << context.line << ": ";
	 *         os << " ERROR: " << message;
	 *         break;
     *     }
	 * }
	 * @endcode
	 *
	 * No debe colocar el salto de línea final, esto lo hará la clase GDE::Log.
	 *
	 * Para instalar ahora el controlador que acaba de crear, debe usar el método GDE::Log::installHandler()
	 * pasando como parámetro el puntero a la función que acaba de crear:
	 *
	 * @code
	 * GDE::Log::installHandler(myLogHandler);
	 * @endcode
	 *
	 * Si bien, esto puede hacerse en cualquier punto, es más recomendable hacerlo solo una vez al comienzo,
	 * antes de usar la clase GDE::Log para escribir.
	 */
class GDE_API Log
{
	Log (const Log &);
	Log& operator= (const Log &);

public:
	//=======================================================================================
	//                                    Clase Manipulator
	//=======================================================================================
	template <typename ArgType>
	class Manipulator
	{
	public:
		typedef Log& (*FunctionPointer) (Log&, ArgType);

		Manipulator (FunctionPointer fp, const ArgType &arg) : function(fp), arg(arg)  { }
		Log& operator() (Log& a) const { return (*function)(a, arg); }

	private:
		FunctionPointer function;
		ArgType arg;
	};



	//=======================================================================================
	//                                       Clase Log
	//=======================================================================================

	Log (LogLevel level, const char *file, int line, const char *function);
	~Log ();

	/**
	 * Retorna una referencia a @c *this.
	 *
	 * No debería llamar a esta función manualmente. Tomar una referencia de un objeto
	 * temporal puede ser peligroso.
	 */
	Log& reference () { return *this; }

	/**
	 * Inicializa el sistema de logs indicando el flujo donde se imprimirá el mensaje generado.
	 * @e outputStream debe referenciar a un objeto válido y preparado para recibir información.
	 * Además, la referencia debe mantenerse válida hasta que el último mensaje sea escrito.
	 *
	 * Si el parámetro @e outputStream representa un archivo de tipo @e std::fstream o derivados,
	 * debe abrir previamente el archivo para escritura y asegurarse que el archivo se haya abierto
	 * correctamente.
	 *
	 * @param outputStream Referencia al flujo donde se imprimirán los mensajes.
	 */
	static void init (std::ostream& outputStream);

	/**
	 * Finaliza el sistema de logs olvidando la referencia al flujo entregado por GDE::Log::init().
	 *
	 * Use este método cuando, por ejemplo, desee cerrar el archivo que está usando GDE::Log y
	 * no desea que GDE::Log lo siga utilizando.
	 *
	 * Si el parámetro @e outputStream representa un archivo de tipo @e std::fstream o derivados,
	 * debe abrir previamente el archivo para escritura y asegurarse que el archivo se haya abierto
	 * correctamente.
	 *
	 * @param outputStream Referencia al flujo donde se imprimirán los mensajes.
	 */
	static void close ();

	/**
	 * Sobrecarga @c operator<< para el tipo @c bool, escribiendo @c true o @c false según
	 * corresponda.
	 *
	 * @param b Valor o variable de tipo @c bool.
	 */
	Log& operator<< (bool b);

	/**
	 * Sobrecarga @c operator<< para el tipo @c std::string. El texto se escribe entre comillas.
	 *
	 * @param str Valor o variable de tipo @c std::string.
	 */
	Log& operator<< (const std::string &str);

	/**
	 * Sobrecarga @c operator<< para aceptar manipuladores sin argumentos.
	 *
	 * Los manipuladores no son más que un puntero a función que toman una referencia a GDE::Log,
	 * la modifican adecuadamente y la retornan nuevamente. Este método toma el puntero a función
	 * y la ejecuta, pasando @c *this como parámetro.
	 *
	 * @param manipulator Puntero a función de tipo Log& (Log&) que sirve como manipulador.
	 */
	Log& operator<< (Log& (*manipulator)(GDE::Log&)) { return (*manipulator)(*this); }


	/**
	 * Sobrecarga @c operator<< para aceptar manipuladores con un argumento.
	 *
	 * Los manipuladores con un argumento se implementan utilizando un objeto función (functor) que
	 * almacena internamente la dirección de una función y el argumento a utilizar. GDE::Log hace
	 * uso de la clase plantilla GDE::Log::Manipulator<T> para implementar el objeto función con el
	 * parámetro indicado. Este operador sobrecargado toma un objeto de tipo GDE::Log::Manipulator<T>
	 * y lo invoca, pasando @c *this como argumento.
	 *
	 * @tparam ArgType Tipo de argumento que usará el manipulador. Este parámetro es deducido
	 *                 automáticamente por el compilador.
	 * @param manipulator Objeto función que sirve como manipulador con un argumento.
	 */
	template <typename ArgType>
	Log& operator<< (const Manipulator<ArgType> &manipulator) { return manipulator(*this); }


	/**
	 * Sobrecarga @c operator<< para cualquier tipo de dato aceptado por @c std::stringstream.
	 *
	 * @tparam T Un tipo de dato aceptado por \c std::stringstream. Es deducido automáticamente por
	 *           el compilador.
	 * @param t Valor o variable de tipo @c T.
	 */
	template <typename T> Log& operator<< (T t);


	// Manipuladores básicos

	/**
	 * Manipulador que indica al stream que use un espacio entre cada parámetro pasado.
	 * Este es el comportamiento por defecto.
	 *
	 * @code
	 * GDE_LOG_INFO(GDE::Log::space << "hola" << "mundo")
	 * @endcode
	 *
	 * Imprime:
	 *
	 * @code
	 * hola mundo
	 * @endcode
	 *
	 *
	 */
	static Log& space (Log &o);

	/**
	 * Manipulador que indica al stream que no coloque un espacio entre cada parámetro pasado.
	 * Este comportamiento se mantendrá en el stream actual hasta que aparezca el manipulador
	 * space;
	 *
	 * @code
	 * GDE_LOG_INFO(GDE::Log::nospace << "hola" << "mundo")
	 * @endcode
	 *
	 * Imprime:
	 *
	 * @code
	 * holamundo
	 * @endcode
	 */
	static Log& nospace (Log &o);


private:
	Log& maybeSpace ();
	static std::string actualTimeToText ();

private:
	SourceContext context;
	std::stringstream textStream;
	bool autoSpacing;
	LogLevel level;
	std::string tag;

	static std::ostream *outputStream;
	static bool initialized;
	static time_t rawtime;
	static LogHandler handler;
};



//=======================================================================================
//                   Definiciones de funciones inline y templates
//=======================================================================================

template <typename T>
Log& Log::operator<< (T t)
{
	this->textStream << t;
	return maybeSpace();
}


} // namespace



//=======================================================================================
//                                      Macros
//=======================================================================================

#define GDE_LOG_INFO(MSG) \
	do { GDE::Log(GDE::Info, __FILE__, __LINE__, 0).reference() << MSG; } while(0)

#define GDE_LOG_DEBUG(MSG) \
	do { GDE::Log(GDE::Debug, __FILE__, __LINE__, 0).reference() << MSG; } while(0)

#define GDE_LOG_WARNING(MSG) \
	do { GDE::Log(GDE::Warning, __FILE__, __LINE__, 0).reference() << MSG; } while(0)

#define GDE_LOG_ERROR(MSG) \
	do { GDE::Log(GDE::Error, __FILE__, __LINE__, 0).reference() << MSG; } while(0)



#endif // GDE_CORE_LOG_HPP
