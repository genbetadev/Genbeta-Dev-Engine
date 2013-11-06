#ifndef GDE_CORE_STRING_UTIL_HPP
#define GDE_CORE_STRING_UTIL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <GDE/Config.hpp>

namespace GDE
{

///////////////////////////////////////////////////////////////////////////
// String Manipulation Methods
///////////////////////////////////////////////////////////////////////////
/**
* convertBool will convert the boolean value provided into a string.
* @param[in] theBoolean to convert to a string.
* @return the resulting string after converting theBoolean
*/
std::string GDE_API convertBool(const bool theBoolean);

/**
* convertColor will convert theColor value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string GDE_API convertColor(const sf::Color theVector);

/**
* convertDouble will convert the double value provided into a string.
* @param[in] theFloat to convert to a string.
* @return the resulting string after converting theFloat
*/
std::string GDE_API convertDouble(const double theFloat);

/**
* convertFloat will convert the float value provided into a string.
* @param[in] theFloat to convert to a string.
* @return the resulting string after converting theFloat
*/
std::string GDE_API convertFloat(const float theFloat);

/**
* convertInt8 will convert the 8 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertInt8(const sf::Int8 theNumber);

/**
* convertInt16 will convert the 16 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertInt16(const sf::Int16 theNumber);

/**
* convertInt32 will convert the 32 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertInt32(const sf::Int32 theNumber);

/**
* convertInt64 will convert the 64 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertInt64(const sf::Int64 theNumber);

/**
* convertIntRect will convert the sf::IntRect value provided into a string.
* @param[in] theRect to convert to a string.
* @return the resulting string after converting theRect
*/
std::string GDE_API convertIntRect(const sf::IntRect theRect);

/**
* convertUint8 will convert the 8 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertUint8(const sf::Uint8 theNumber);

/**
* convertUint16 will convert the 16 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertUint16(const sf::Uint16 theNumber);

/**
* convertUint32 will convert the 32 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertUint32(const sf::Uint32 theNumber);

/**
* convertUint64 will convert the 64 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string GDE_API convertUint64(const sf::Uint64 theNumber);

/**
* convertVector2f will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string GDE_API convertVector2f(const sf::Vector2f theVector);

/**
* convertVector2i will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string GDE_API convertVector2i(const sf::Vector2i theVector);

/**
* convertVector2u will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string GDE_API convertVector2u(const sf::Vector2u theVector);

/**
* convertVector3f will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string GDE_API convertVector3f(const sf::Vector3f theVector);

/**
* convertVector3i will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string GDE_API convertVector3i(const sf::Vector3i theVector);

///////////////////////////////////////////////////////////////////////////
// String parse Methods
///////////////////////////////////////////////////////////////////////////
/**
* parseBool will parse theValue string to obtain the boolean value to
* return.  If the value is not one of the following (0,1,true,false,on,
* off) then theDefault will be returned instead.
* @param[in] theValue to parse for (0,1,true,false,on,off)
* @param[in] theDefault value to return if not one of the above
* @return the boolean value obtained
*/
bool GDE_API parseBool(std::string theValue, const bool theDefault);

/**
* parseColor will parse theValue string to obtain the R,G,B,A color values
* to produce an sf::Color object for the GetColor method above.
* @param[in] theValue to parse for R,G,B,A color values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Color GDE_API parseColor(const std::string theValue, const sf::Color theDefault);

/**
* parseDouble will parse theValue string to obtain the double value to
* return or return theDefault instead.
* @param[in] theValue to parse for the float value
* @param[in] theDefault float value to use if the parser fails
* @return the float value obtained or theDefault if not parsed
*/
double GDE_API parseDouble(const std::string theValue, const double theDefault);

/**
* parseFloat will parse theValue string to obtain the float value to
* return or return theDefault instead.
* @param[in] theValue to parse for the float value
* @param[in] theDefault float value to use if the parser fails
* @return the float value obtained or theDefault if not parsed
*/
float GDE_API parseFloat(const std::string theValue, const float theDefault);

/**
* parseInt8 will parse theValue string to obtain a signed 8 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 8 bit value
* @param[in] theDefault signed 8 bit value to use if the parser fails
* @return the signed 8 bit value obtained
*/
sf::Int8 GDE_API parseInt8(const std::string theValue, const sf::Int8 theDefault);

/**
* parseInt16 will parse theValue string to obtain a signed 16 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 16 bit value
* @param[in] theDefault signed 16 bit value to use if the parser fails
* @return the signed 16 bit value obtained
*/
sf::Int16 GDE_API parseInt16(const std::string theValue, const sf::Int16 theDefault);

/**
* parseInt32 will parse theValue string to obtain a signed 32 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 32 bit value
* @param[in] theDefault signed 32 bit value to use if the parser fails
* @return the signed 32 bit value obtained
*/
sf::Int32 GDE_API parseInt32(const std::string theValue, const sf::Int32 theDefault);

/**
* parseInt64 will parse theValue string to obtain a signed 64 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 64 bit value
* @param[in] theDefault signed 64 bit value to use if the parser fails
* @return the signed 64 bit value obtained
*/
sf::Int64 GDE_API parseInt64(const std::string theValue, const sf::Int64 theDefault);

/**
* parseIntRect will parse theValue string to obtain a sf::IntRect value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the sf::IntRect value
* @param[in] theDefault sf::IntRect value to use if the parser fails
* @return the sf::IntRect value obtained
*/
sf::IntRect GDE_API parseIntRect(const std::string theValue, const sf::IntRect theDefault);

/**
* parseUint8 will parse theValue string to obtain a signed 8 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 8 bit value
* @param[in] theDefault signed 8 bit value to use if the parser fails
* @return the signed 8 bit value obtained
*/
sf::Uint8 GDE_API parseUint8(const std::string theValue, const sf::Uint8 theDefault);

/**
* parseUint16 will parse theValue string to obtain an unsigned 16 bit
* value.  If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the unsigned 16 bit value
* @param[in] theDefault unsigned 16 bit value to use if the parser fails
* @return the unsigned 16 bit value obtained
*/
sf::Uint16 GDE_API parseUint16(const std::string theValue, const sf::Uint16 theDefault);

/**
* parseUint32 will parse theValue string to obtain an unsigned 32 bit
* value.  If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the unsigned 32 bit value
* @param[in] theDefault unsigned 32 bit value to use if the parser fails
* @return the unsigned 32 bit value obtained
*/
sf::Uint32 GDE_API parseUint32(const std::string theValue, const sf::Uint32 theDefault);

/**
* parseUint64 will parse theValue string to obtain an unsigned 64 bit
* value.  If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the unsigned 64 bit value
* @param[in] theDefault unsigned 64 bit value to use if the parser fails
* @return the unsigned 64 bit value obtained
*/
sf::Uint64 GDE_API parseUint64(const std::string theValue, const sf::Uint64 theDefault);

/**
* parseVector2f will parse theValue string to obtain the X,Y vector values
* to produce an sf::Vector2f object.
* @param[in] theValue to parse for X,Y vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector2f GDE_API parseVector2f(const std::string theValue, const sf::Vector2f theDefault);

/**
* parseVector2i will parse theValue string to obtain the X,Y vector values
* to produce an sf::Vector2i object.
* @param[in] theValue to parse for X,Y vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector2i GDE_API parseVector2i(const std::string theValue, const sf::Vector2i theDefault);

/**
* parseVector2u will parse theValue string to obtain the X,Y vector values
* to produce an sf::Vector2u object.
* @param[in] theValue to parse for X,Y vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector2u GDE_API parseVector2u(const std::string theValue, const sf::Vector2u theDefault);

/**
* parseVector3f will parse theValue string to obtain the X,Y,Z vector values
* to produce an sf::Vector3f object.
* @param[in] theValue to parse for X,Y,Z vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector3f GDE_API parseVector3f(const std::string theValue, const sf::Vector3f theDefault);

/**
* parseVector3i will parse theValue string to obtain the X,Y,Z vector values
* to produce an sf::Vector3i object.
* @param[in] theValue to parse for X,Y,Z vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector3i GDE_API parseVector3i(const std::string theValue, const sf::Vector3i theDefault);
/**
* StringToLower will convert theString to all lowercase letters.
* @param[in] theString is the string to change case.
* @return theString with all lowercase.
**/
std::string GDE_API StringToLowercase(std::string theString);

/**
* StringToLower will convert theString to all uppercase letters.
* @param[in] theString is the string to change case.
* @return theString with all uppercase.
**/
std::string GDE_API StringToUppercase(std::string theString);

} // namespace GDE

#endif // GDE_CORE_STRING_UTIL_HPP