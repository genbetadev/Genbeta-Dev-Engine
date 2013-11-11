#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdarg>
#include <GDE/Core/StringsUtil.hpp>

namespace GDE
{

std::string convertBool(const bool theBoolean)
{
	// Usamos la clase StringStream para convertir theBoolean a string
	std::stringstream anResult;

	// Añadimos theBoolean al stringstream
	if (theBoolean)
	{
		anResult << "true";
	}
	else
	{
		anResult << "false";
	}

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertColor(const sf::Color theColor)
{
	// Usamos la clase StringStream para convertir theColor a string
	std::stringstream anResult;

	// Añadimos theColor al stringstream
	anResult << theColor.r << ", ";
	anResult << theColor.g << ", ";
	anResult << theColor.b << ", ";
	anResult << theColor.a;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertDouble(const double theDouble)
{
	// Usamos la clase StringStream para convertir theDouble a string
	std::stringstream anResult;

	// Añadimos theDouble al stringstream
	anResult << theDouble;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertFloat(const float theFloat)
{
	// Usamos la clase StringStream para convertir theFloat a string
	std::stringstream anResult;

	// Añadimos theFloat al stringstream
	anResult << theFloat;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertInt8(const sf::Int8 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertInt16(const sf::Int16 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertInt32(const sf::Int32 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertInt64(const sf::Int64 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertIntRect(const sf::IntRect theRect)
{
	// Usamos la clase StringStream para convertir theRect a string
	std::stringstream anResult;

	// Añadimos theRect al stringstream
	anResult << theRect.top << ", ";
	anResult << theRect.left << ", ";
	anResult << theRect.width << ", ";
	anResult << theRect.height;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertUint8(const sf::Uint8 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertUint16(const sf::Uint16 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertUint32(const sf::Uint32 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertUint64(const sf::Uint64 theNumber)
{
	// Usamos la clase StringStream para convertir theNumber a string
	std::stringstream anResult;

	// Añadimos theNumber al stringstream
	anResult << theNumber;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertVector2f(const sf::Vector2f theVector)
{
	// Usamos la clase StringStream para convertir theVector a string
	std::stringstream anResult;

	// Añadimos theVector al stringstream
	anResult << theVector.x << ", ";
	anResult << theVector.y;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertVector2i(const sf::Vector2i theVector)
{
	// Usamos la clase StringStream para convertir theVector a string
	std::stringstream anResult;

	// Añadimos theVector al stringstream
	anResult << theVector.x << ", ";
	anResult << theVector.y;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertVector2u(const sf::Vector2u theVector)
{
	// Usamos la clase StringStream para convertir theVector a string
	std::stringstream anResult;

	// Añadimos theVector al stringstream
	anResult << theVector.x << ", ";
	anResult << theVector.y;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertVector3f(const sf::Vector3f theVector)
{
	// Usamos la clase StringStream para convertir theVector a string
	std::stringstream anResult;

	// Añadimos theVector al stringstream
	anResult << theVector.x << ", ";
	anResult << theVector.y << ", ";
	anResult << theVector.z;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

std::string convertVector3i(const sf::Vector3i theVector)
{
	// Usamos la clase StringStream para convertir theVector a string
	std::stringstream anResult;

	// Añadimos theVector al stringstream
	anResult << theVector.x << ", ";
	anResult << theVector.y << ", ";
	anResult << theVector.z;

	// Devolvemos el string resultante creado por stringstream
	return anResult.str();
}

bool parseBool(std::string theValue, const bool theDefault)
{
	bool anResult = theDefault;

	// Primero convertimos theValue a minusculas
	std::transform(theValue.begin(), theValue.end(), theValue.begin(), tolower);

	// Buscamos true/1/on
	if (theValue == "true" || theValue == "1" || theValue == "on")
	{
		anResult = true;
	}

	// Buscamos false/0/off
	if (theValue == "false" || theValue == "0" || theValue == "off")
	{
		anResult = false;
	}

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Color parseColor(const std::string theValue, const sf::Color theDefault)
{
	sf::Color anResult = theDefault;

	// Buscamos la primera coma
	size_t anComma1Offset = theValue.find_first_of(',');
	if (anComma1Offset != std::string::npos)
	{
		sf::Uint8 anRed = parseUint8(theValue.substr(0, anComma1Offset), theDefault.r);
		// Buscamos la siguiente coma
		size_t anComma2Offset = theValue.find_first_of(',', anComma1Offset + 1);
		if (anComma2Offset != std::string::npos)
		{
			sf::Uint8 anGreen = parseUint8(
				theValue.substr(anComma1Offset + 1, anComma2Offset), theDefault.g);
			// Buscamos la siguiente coma
			size_t anComma3Offset = theValue.find_first_of(',', anComma2Offset + 1);
			if (anComma3Offset != std::string::npos)
			{
				sf::Uint8 anBlue = parseUint8(
					theValue.substr(anComma2Offset + 1, anComma3Offset), theDefault.b);
				sf::Uint8 anAlpha = parseUint8(
					theValue.substr(anComma3Offset + 1), theDefault.a);

				// Tenemos los 4 valores parseados, devolvemos el color que hemos encontrado
				anResult.r = anRed;
				anResult.g = anGreen;
				anResult.b = anBlue;
				anResult.a = anAlpha;
			}
		}
	}

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

double parseDouble(const std::string theValue, const double theDefault)
{
	double anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a double
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

float parseFloat(const std::string theValue, const float theDefault)
{
	float anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a float
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Int8 parseInt8(const std::string theValue, const sf::Int8 theDefault)
{
	sf::Int8 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Int8
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Int16 parseInt16(const std::string theValue, const sf::Int16 theDefault)
{
	sf::Int16 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Int16
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Int32 parseInt32(const std::string theValue, const sf::Int32 theDefault)
{
	sf::Int32 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Int32
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Int64 parseInt64(const std::string theValue, const sf::Int64 theDefault)
{
	sf::Int64 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Int64
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::IntRect parseIntRect(const std::string theValue, const sf::IntRect theDefault)
{
	sf::IntRect anResult = theDefault;

	// Buscamos la primera coma
	size_t anComma1Offset = theValue.find_first_of(',');
	if (anComma1Offset != std::string::npos)
	{
		sf::Int32 anLeft = parseInt32(theValue.substr(0, anComma1Offset), theDefault.left);
		// Buscamos la siguiente coma
		size_t anComma2Offset = theValue.find_first_of(',', anComma1Offset + 1);
		if (anComma2Offset != std::string::npos)
		{
			sf::Int32 anTop = parseInt32(theValue.substr(anComma1Offset + 1, anComma2Offset), theDefault.top);
			// Buscamos la siguiente coma
			size_t anComma3Offset = theValue.find_first_of(',', anComma2Offset + 1);
			if (anComma3Offset != std::string::npos)
			{
				// Get the width and height values
				sf::Int32 anWidth = parseInt32(theValue.substr(anComma2Offset + 1, anComma3Offset), theDefault.width);
				sf::Int32 anHeight = parseInt32(theValue.substr(anComma3Offset + 1), theDefault.height);

				// Now that all 4 values have been parsed, return the color found
				anResult.left = anLeft;
				anResult.top = anTop;
				anResult.width = anWidth;
				anResult.height = anHeight;
			}
		}
	}

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Uint8 parseUint8(const std::string theValue, const sf::Uint8 theDefault)
{
	sf::Uint8 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Uint8
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Uint16 parseUint16(const std::string theValue, const sf::Uint16 theDefault)
{
	sf::Uint16 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Uint16
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Uint32 parseUint32(const std::string theValue, const sf::Uint32 theDefault)
{
	sf::Uint32 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Uint32
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Uint64 parseUint64(const std::string theValue, const sf::Uint64 theDefault)
{
	sf::Uint64 anResult = theDefault;
	std::istringstream iss(theValue);

	// Convertimos el string a sf::Uint64
	iss >> anResult;

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Vector2f parseVector2f(const std::string theValue, const sf::Vector2f theDefault)
{
	sf::Vector2f anResult = theDefault;

	// Buscamos la primera coma
	size_t anCommaOffset = theValue.find_first_of(',');
	if (anCommaOffset != std::string::npos)
	{
		float anX = parseFloat(theValue.substr(0, anCommaOffset), theDefault.x);
		float anY = parseFloat(theValue.substr(anCommaOffset + 1), theDefault.y);

		// Ahora que los 2 valores han sido parseados, devolvemos el vector encontrado
		anResult.x = anX;
		anResult.y = anY;
	}

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Vector2i parseVector2i(const std::string theValue, const sf::Vector2i theDefault)
{
	sf::Vector2i anResult = theDefault;

	// Buscamos la primera coma
	size_t anCommaOffset = theValue.find_first_of(',');
	if (anCommaOffset != std::string::npos)
	{
		sf::Int32 anX = parseInt32(theValue.substr(0, anCommaOffset), theDefault.x);
		sf::Int32 anY = parseInt32(theValue.substr(anCommaOffset + 1), theDefault.y);

		// Ahora que los 2 valores han sido parseados, devolvemos el vector encontrado
		anResult.x = anX;
		anResult.y = anY;
	}

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Vector2u parseVector2u(const std::string theValue, const sf::Vector2u theDefault)
{
	sf::Vector2u anResult = theDefault;

	// Buscamos la primera coma
	size_t anCommaOffset = theValue.find_first_of(',');
	if (anCommaOffset != std::string::npos)
	{
		sf::Uint32 anX = parseUint32(theValue.substr(0, anCommaOffset), theDefault.x);
		sf::Uint32 anY = parseUint32(theValue.substr(anCommaOffset + 1), theDefault.y);

		// Ahora que los 2 valores han sido parseados, devolvemos el vector encontrado
		anResult.x = anX;
		anResult.y = anY;
	}

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Vector3f parseVector3f(const std::string theValue, const sf::Vector3f theDefault)
{
	sf::Vector3f anResult = theDefault;

	// Buscamos la primera coma
	size_t anComma1Offset = theValue.find_first_of(',', 0);
	if (anComma1Offset != std::string::npos)
	{
		float anX = parseFloat(theValue.substr(0, anComma1Offset), theDefault.x);

		// Buscamos la siguiente coma
		size_t anComma2Offset = theValue.find_first_of(',', anComma1Offset + 1);
		if (anComma2Offset != std::string::npos)
		{
			float anY = parseFloat(theValue.substr(anComma1Offset + 1, anComma2Offset), theDefault.y);
			float anZ = parseFloat(theValue.substr(anComma2Offset + 1), theDefault.z);

			// Ahora que los 3 valores han sido parseados, devolvemos el vector encontrado
			anResult.x = anX;
			anResult.y = anY;
			anResult.z = anZ;
		}
	}

	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

sf::Vector3i parseVector3i(const std::string theValue, const sf::Vector3i theDefault)
{
	sf::Vector3i anResult = theDefault;

	// Buscamos la primera coma
	size_t anComma1Offset = theValue.find_first_of(',', 0);
	if (anComma1Offset != std::string::npos)
	{
		sf::Int32 anX = parseInt32(theValue.substr(0, anComma1Offset), theDefault.x);

		// Buscamos la siguiente coma
		size_t anComma2Offset = theValue.find_first_of(',', anComma1Offset + 1);
		if (anComma2Offset != std::string::npos)
		{
			sf::Int32 anY = parseInt32(theValue.substr(anComma1Offset + 1, anComma2Offset), theDefault.y);
			sf::Int32 anZ = parseInt32(theValue.substr(anComma2Offset + 1), theDefault.z);

			// Ahora que los 3 valores han sido parseados, devolvemos el vector encontrado
			anResult.x = anX;
			anResult.y = anY;
			anResult.z = anZ;
		}
	}
	// Devolvemos el resultado que hemos encontrado o el valor theDefault que se nos ha proporcionado
	return anResult;
}

std::string StringToLowercase(std::string theString)
{
	std::string anLowerString = theString;
	//from STL's algorithm header
	std::transform(anLowerString.begin(), anLowerString.end(), anLowerString.begin(), ::tolower);
	return anLowerString;
}

std::string StringToUppercase(std::string theString)
{
	std::string anLowerString = theString;
	//from STL's algorithm header
	std::transform(anLowerString.begin(), anLowerString.end(), anLowerString.begin(), ::toupper);
	return anLowerString;
}

std::string GDE_API StringFormat(const std::string stringToFormat, ...)
{
	int streamBufferSize = 100;
	std::string formattedString;

	va_list argumentParameters;

	formattedString.resize(streamBufferSize);

	va_start(argumentParameters, stringToFormat);
	// Compute the number of characters the final formatted string will have
	int numChars = vsnprintf((char *)formattedString.c_str(),
							 streamBufferSize,
							 stringToFormat.c_str(),
							 argumentParameters);


	// The formatted string could be stored in the initial buffer size
	if (numChars > -1 && numChars < streamBufferSize) {
		formattedString.resize(numChars);

		return formattedString;
	// The formatted string does not fit in the initial buffer size
	} else {
		// Resize the buffer and add space for the null-terminating char
		streamBufferSize = numChars + 1;
		formattedString.resize(streamBufferSize);

		// This second call will create the complete formatted string
		va_start(argumentParameters, stringToFormat);
		vsnprintf((char *)formattedString.c_str(),
				  streamBufferSize,
				  stringToFormat.c_str(),
				  argumentParameters);
	}

	va_end(argumentParameters);
	return formattedString;
}

} // namespace GDE
