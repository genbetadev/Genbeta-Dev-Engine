#ifndef GDE_CORE_STRING_UTIL_HPP
#define GDE_CORE_STRING_UTIL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Config.hpp"

namespace GDE { namespace Utils
{

///////////////////////////////////////////////////////////////////////////
// Metodos de manipulación de Strings
///////////////////////////////////////////////////////////////////////////
/**
 * convertBool convertirá el valor de tipo 'bool' proporcionado en un 'String'.
 * @param[in] theBoolean: El parametro 'bool' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theBoolean.
 **/
std::string GDE_API convertBool(const bool theBoolean);

/**
 * convertColor convertirá el valor de tipo 'sf::Color' proporcionado en un 'String'.
 * @param[in] theVector: El parametro 'sf::Color' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theVector.
 **/
std::string GDE_API convertColor(const sf::Color theVector);

/**
 * convertDouble convertirá el valor de tipo 'double' proporcionado en un 'String'.
 * @param[in] theFloat: El parametro 'double' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theFloat.
 **/
std::string GDE_API convertDouble(const double theFloat);

/**
 * convertFloat convertirá el valor de tipo 'float' proporcionado en un 'String'.
 * @param[in] theFloat: El parametro 'float' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theFloat.
 **/
std::string GDE_API convertFloat(const float theFloat);

/**
 * convertInt8 convertirá el valor de tipo 'Int8' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Int8' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber.
 **/
std::string GDE_API convertInt8(const sf::Int8 theNumber);

/**
 * convertInt16 convertirá el valor de tipo 'sf::Int16' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Int16' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber.
 **/
std::string GDE_API convertInt16(const sf::Int16 theNumber);

/**
 * convertInt32 convertirá el valor de tipo 'sf::Int32' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Int32' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber.
 **/
std::string GDE_API convertInt32(const sf::Int32 theNumber);

/**
 * convertInt64 convertirá el valor de tipo 'sf::Int64' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Int64' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber.
 **/
std::string GDE_API convertInt64(const sf::Int64 theNumber);

/**
 * convertIntRect convertirá el valor de tipo 'sf::IntRect' proporcionado en un 'String'.
 * @param[in] theRect: El parametro 'sf::IntRect' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theRect
 **/
std::string GDE_API convertIntRect(const sf::IntRect theRect);

/**
 * convertUint8 convertirá el valor de tipo 'sf::Uint8' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Uint8' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber
 **/
std::string GDE_API convertUint8(const sf::Uint8 theNumber);

/**
 * convertUint16 convertirá el valor de tipo 'sf::Uint16' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Uint16' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber
 **/
std::string GDE_API convertUint16(const sf::Uint16 theNumber);

/**
 * convertUint32 convertirá el valor de tipo 'sf::Uint32' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Uint32' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber
 **/
std::string GDE_API convertUint32(const sf::Uint32 theNumber);

/**
 * convertUint64 convertirá el valor de tipo 'sf::Uint64' proporcionado en un 'String'.
 * @param[in] theNumber: El parametro 'sf::Uint64' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theNumber
 **/
std::string GDE_API convertUint64(const sf::Uint64 theNumber);

/**
 * convertVector2f convertirá el valor de tipo 'sf::Vector2f' proporcionado en un 'String'.
 * @param[in] theVector: El parametro 'sf::Vector2f' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theVector
 **/
std::string GDE_API convertVector2f(const sf::Vector2f theVector);

/**
 * convertVector2i convertirá el valor de tipo 'sf::Vector2i' proporcionado en un 'String'.
 * @param[in] theVector: El parametro 'sf::Vector2i' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theVector
 **/
std::string GDE_API convertVector2i(const sf::Vector2i theVector);

/**
 * convertVector2u convertirá el valor de tipo 'sf::Vector2u' proporcionado en un 'String'.
 * @param[in] theVector: El parametro 'sf::Vector2u' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theVector
 **/
std::string GDE_API convertVector2u(const sf::Vector2u theVector);

/**
 * convertVector3f convertirá el valor de tipo 'sf::Vector3f' proporcionado en un 'String'.
 * @param[in] theVector: El parametro 'sf::Vector3f' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theVector
 **/
std::string GDE_API convertVector3f(const sf::Vector3f theVector);

/**
 * convertVector3i convertirá el valor de tipo 'sf::Vector3i' proporcionado en un 'String'.
 * @param[in] theVector: El parametro 'sf::Vector3i' a convertir en 'String'.
 * @return: Devuelve el 'String' con la conversión de theVector
 **/
std::string GDE_API convertVector3i(const sf::Vector3i theVector);

///////////////////////////////////////////////////////////////////////////
// Metodos de parseo de Strings
///////////////////////////////////////////////////////////////////////////
/**
 * parseBool parseará theValue para obtener el valor 'bool' a devolver
 * Si el valor no es uno de los siguientes (0,1,true,false,on,
 * off) entonces se devolerá theDefault en su lugar.
 * @param[in] theValue a parsear con los valores (0,1,true,false,on,off)
 * @param[in] theDefault: El bool a devolver si el parseo falla.
 * @return el valor bool obtenido
 **/
bool GDE_API parseBool(std::string theValue, const bool theDefault);

/**
 * parseColor parseará theValue para obtener los valores R,G,B,A produciendo un
 * objeto sf::Color para el método GetColor.
 * @param[in] theValue: El valor a parsear con los valores de color R,G,B,A.
 * @param[in] theDefault: El sf::Color a devolver si el parseo falla.
 * @return: Devolverá un sf::Color con los valores parseados.
 **/
sf::Color GDE_API parseColor(const std::string theValue, const sf::Color theDefault);

/**
 * parseDouble parseará theValue para obtener el valor double o devolverá 
 * theDefaulf si el parseo falla.
 * @param[in] theValue a parsear con el valor float.
 * @param[in] theDefault: El double a devolver si el parseo falla.
 * @return: Devolverá un double con los valores parseados.
 **/
double GDE_API parseDouble(const std::string theValue, const double theDefault);

/**
 * parseFloat parseará theValue para obtener el valor float o devolverá 
 * theDefaulf si el parseo falla.
 * @param[in] theValue a parsear con el valor float
 * @param[in] theDefault: El float a devolver si el parseo falla.
 * @return: Devolverá un float con los valores parseados.
 **/
float GDE_API parseFloat(const std::string theValue, const float theDefault);

/**
 * parseInt8 parseará theValue para obtener el valor sf::Int8.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf::Int8
 * @param[in] theDefault: El sf::Int8 a devolver si el parseo falla.
 * @return: Devolverá un sf::Int8 con los valores parseados.
 **/
sf::Int8 GDE_API parseInt8(const std::string theValue, const sf::Int8 theDefault);

/**
 * parseInt16 parseará theValue para obtener el valor sf::Int16.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf::Int16
 * @param[in] theDefault: El sf::Int16 a devolver si el parseo falla.
 * @return: Devolverá un sf::Int16 con los valores parseados.
 **/
sf::Int16 GDE_API parseInt16(const std::string theValue, const sf::Int16 theDefault);

/**
 * parseInt32 parseará theValue para obtener el valor sf::Int32.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con los el valor sf::Int32
 * @param[in] theDefault: El sf::Int32 a devolver si el parseo falla.
 * @return: Devolverá un sf::Int32 con los valores parseados.
 **/
sf::Int32 GDE_API parseInt32(const std::string theValue, const sf::Int32 theDefault);

/**
 * parseInt64 parseará theValue para obtener el valorsf::Int64.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf:Int64
 * @param[in] theDefault: El sf::Int64 a devolver si el parseo falla.
 * @return: Devolverá un sf::Int64 con los valores parseados.
 **/
sf::Int64 GDE_API parseInt64(const std::string theValue, const sf::Int64 theDefault);

/**
 * parseIntRect parseará theValue para obtener el valor sf::IntRect.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf::IntRect
 * @param[in] theDefault: El sf::IntRect a devolver si el parseo falla.
 * @return: Devolverá un sf::IntRect con los valores parseados.
 **/
sf::IntRect GDE_API parseIntRect(const std::string theValue, const sf::IntRect theDefault);

/**
 * parseUint8 parseará theValue para obtener el valor signed 8 bit.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf:Uint8
 * @param[in] theDefault: El sf::Uint8 a devolver si el parseo falla.
 * @return: Devolverá un sf::Uint8 con los valores parseados.
 **/
sf::Uint8 GDE_API parseUint8(const std::string theValue, const sf::Uint8 theDefault);

/**
 * parseUint16 parseará theValue para obtener el valor unsigned 16 bit.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf::Uint16
 * @param[in] theDefault: El sf::Uint16 a devolver si el parseo falla.
 * @return: Devolverá un sf::Uint16 con los valores parseados.
 **/
sf::Uint16 GDE_API parseUint16(const std::string theValue, const sf::Uint16 theDefault);

/**
 * parseUint32 parseará theValue para obtener el valor unsigned 32 bit.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf::Uint32
 * @param[in] theDefault: El sf::Uint32 a devolver si el parseo falla.
 * @return: Devolverá un sf::Uint32 con los valores parseados.
 **/
sf::Uint32 GDE_API parseUint32(const std::string theValue, const sf::Uint32 theDefault);

/**
 * parseUint64 parseará theValue para obtener el valor unsigned 64 bit.
 * Si el parseo falla, devolverá theDefault en su lugar.
 * @param[in] theValue a parsear con el valor sf::Uint64
 * @param[in] theDefault: El sf::Uint64 a devolver si el parseo falla.
 * @return: Devolverá un sf::Uint64 con los valores parseados.
 **/
sf::Uint64 GDE_API parseUint64(const std::string theValue, const sf::Uint64 theDefault);

/**
 * parseVector2f parseará theValue para obtener el valor X,Y del vector
 * para crear un objeto sf::Vector2f.
 * @param[in] theValue a parsear con los valores X,Y del vector
 * @param[in] theDefault: El sf::Vector2f a devolver si el parseo falla.
 * @return: Devolverá un sf::Vector2f con los valores parseados.
 **/
sf::Vector2f GDE_API parseVector2f(const std::string theValue, const sf::Vector2f theDefault);

/**
 * parseVector2i parseará theValue para obtener el valor X,Y del vector
 * para crear un objeto sf::Vector2i.
 * @param[in] theValue a parsear con los valores X,Y del vector
 * @param[in] theDefault: El sf::Vector2i a devolver si el parseo falla.
 * @return: Devolverá un sf::Vector2i con los valores parseados.
 **/
sf::Vector2i GDE_API parseVector2i(const std::string theValue, const sf::Vector2i theDefault);

/**
 * parseVector2u parseará theValue para obtener el valor X,Y del vector
 * para crear un objeto sf::Vector2u.
 * @param[in] theValue a parsear con los valores X,Y del vector
 * @param[in] theDefault: El sf::Vector2u a devolver si el parseo falla.
 * @return: Devolverá un sf::Vector2u con los valores parseados.
 **/
sf::Vector2u GDE_API parseVector2u(const std::string theValue, const sf::Vector2u theDefault);

/**
 * parseVector3f parseará theValue para obtener el valor X,Y,Z del vector
 * para crear un objeto sf::Vector3f.
 * @param[in] theValue a parsear con los valores X,Y,Z del vector
 * @param[in] theDefault: El sf::Vector3f a devolver si el parseo falla.
 * @return: Devolverá un sf::Vector3f con los valores parseados.
 **/
sf::Vector3f GDE_API parseVector3f(const std::string theValue, const sf::Vector3f theDefault);

/**
 * parseVector3i parseará theValue para obtener el valor X,Y,Z del vector
 * para crear un objeto sf::Vector3i.
 * @param[in] theValue a parsear con los valores X,Y,Z del vector
 * @param[in] theDefault: El sf::Vector3i a devolver si el parseo falla.
 * @return: Devolverá un sf::Vector3i con los valores parseados.
 **/
sf::Vector3i GDE_API parseVector3i(const std::string theValue, const sf::Vector3i theDefault);

/**
 * StringToLower convertirá todas las letras de theString a minusculas.
 * @param[in] theString: El String a convertir.
 * @return theString: El String con sus letras en minusculas.
 **/
std::string GDE_API StringToLowercase(std::string theString);

/**
 * StringToLower convertirá todas las letras de theString a mayúsculas.
 * @param[in] theString: El String a convertir.
 * @return theString: El String con sus letras en mayúsculas.
 **/
std::string GDE_API StringToUppercase(std::string theString);

/**
 * Permite formatear una std::string como en una llamada a printf, usando una
 * lista de argumentos variable.
 *
 * @param[in] stringToFormat: String con el formato.
 * @param[in] args: Lista variable de argumentos con los elementos a sustituir
 * @return std::string: Nueva string formateada con los argumentos pasados
 **/
std::string GDE_API StringFormat(const std::string stringToFormat, ...);

} } // namespace GDE::Utils

#endif // GDE_CORE_STRING_UTIL_HPP
