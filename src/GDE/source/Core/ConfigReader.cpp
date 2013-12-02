#include <cstdio>
#include <cstring>

#include "GDE/Core/ConfigReader.hpp"
#include "GDE/Log/Log.hpp"
#include "GDE/Utils/StringsUtil.hpp"

namespace GDE { namespace Core
{

ConfigReader::ConfigReader()
{
}

ConfigReader::ConfigReader(const ConfigReader& theCopy) :
    sections(theCopy.sections)
{
}

ConfigReader::~ConfigReader()
{
    // Borra todos los pares <clave,valor> del mapa
    std::map<const std::string, typeNameValue*>::iterator iter;
    iter = this->sections.begin();
    while (iter != this->sections.end())
    {
        typeNameValue* anMap = iter->second;
        this->sections.erase(iter++);
        delete anMap;
    }
}

bool ConfigReader::isSectionEmpty(const std::string theSection) const
{
    bool anResult = false;

    // Comprueba si una sección existe
    std::map<const std::string, typeNameValue*>::const_iterator iter;
    iter = this->sections.find(theSection);
    if (iter != this->sections.end())
    {
        typeNameValue* anMap = iter->second;
        if (NULL != anMap)
        {
            anResult = anMap->empty();
        }
    }

    // Devuelve el resultado obtenido anteriormente o false en caso de no encontrase la sección
    return anResult;
}

bool ConfigReader::getBool(const std::string theSection,
    const std::string theName, const bool theDefault) const
{
    bool anResult = theDefault;

    // Comprueba si la sección existe
    std::map<const std::string, typeNameValue*>::const_iterator iter;
    iter = this->sections.find(theSection);
    if (iter != this->sections.end())
    {
        // Intenta obtener el par <clave, valor>
        typeNameValue* anMap = iter->second;
        if (NULL != anMap)
        {
            typeNameValueIter iterNameValue;
            iterNameValue = anMap->find(theName);
            if (iterNameValue != anMap->end())
            {
                anResult = Utils::parseBool(iterNameValue->second, theDefault);
            }
        }
    }

    // Devuelve el resultado encontrado o el valor de theDefault
    return anResult;
}

float ConfigReader::getFloat(const std::string theSection,
    const std::string theName, const float theDefault) const
{
    float anResult = theDefault;

    // Comprueba si la sección existe
    std::map<const std::string, typeNameValue*>::const_iterator iter;
    iter = this->sections.find(theSection);
    if (iter != this->sections.end())
    {
        // Intenta obtener el par <clave, valor>
        typeNameValue* anMap = iter->second;
        if (NULL != anMap)
        {
            typeNameValueIter iterNameValue;
            iterNameValue = anMap->find(theName);
            if (iterNameValue != anMap->end())
            {
                anResult = Utils::parseFloat(iterNameValue->second, theDefault);
            }
        }
    }

    // Devuelve el resultado encontrado o el valor de theDefault
    return anResult;
}

std::string ConfigReader::getString(const std::string theSection,
    const std::string theName, const std::string theDefault) const
{
    std::string anResult = theDefault;

    // Comprueba si la sección existe
    std::map<const std::string, typeNameValue*>::const_iterator iter;
    iter = this->sections.find(theSection);
    if (iter != this->sections.end())
    {
        // Intenta obtener el par <clave, valor>
        typeNameValue* anMap = iter->second;
        if (NULL != anMap)
        {
            typeNameValueIter iterNameValue;
            iterNameValue = anMap->find(theName);
            if (iterNameValue != anMap->end())
            {
                anResult = iterNameValue->second;
            }
        }
    }

    // Devuelve el resultado encontrado o el valor de theDefault
    return anResult;
}

sf::Uint32 ConfigReader::getUint32(const std::string theSection, const std::string theName, const sf::Uint32 theDefault) const
{
    sf::Uint32 anResult = theDefault;
    // Comprueba si la sección existe
    std::map<const std::string, typeNameValue*>::const_iterator iter;
    iter = this->sections.find(theSection);
    if (iter != this->sections.end())
    {
        // Intenta obtener el par <clave, valor>
        typeNameValue* anMap = iter->second;
        if (NULL != anMap)
        {
            typeNameValueIter iterNameValue;
            iterNameValue = anMap->find(theName);
            if (iterNameValue != anMap->end())
            {
                anResult = Utils::parseUint32(iterNameValue->second, theDefault);
            }
        }
    }

    // Devuelve el resultado encontrado o el valor de theDefault
    return anResult;
}

bool ConfigReader::loadFromFile(const std::string& theFilename)
{
    bool anResult = false;
    char anLine[MAX_CHARS];
    std::string anSection;
    unsigned long anCount = 1;

	// Indicamos en el log que estamos cargando un fichero
    GDE::Log::info("ConfigReader::loadFromFile","Abriendo fichero "+theFilename+".");

    // Intentamos abrir el fichero
    FILE* anFile = fopen(theFilename.c_str(), "r");

    // Leemos el fichero si se abrió correctamente
    if (NULL != anFile)
    {
        // Leemos hasta que lleguemos al final del fichero
        while (!feof(anFile))
        {
            // Obtenemos la primera línea del fichero
            if (fgets(anLine, MAX_CHARS, anFile) == NULL)
            {
                // Si ocurre un error lo metemos en el log
                if (!feof(anFile))
                {
                    GDE::Log::error("ConfigReader::Read", Utils::StringFormat("Error leyendo la línea %d", anCount));
                }
                // Salimos del bucle
                break;
            }
            else
            {
                // Parseamos la línea
                anSection = parseLine(anLine, anCount, anSection);
            }

            // Incrementamos el contador de líneas
            anCount++;
        }

        // Cerramos el fichero
        fclose(anFile);

        // Indicamos que todo se realizó correctamente
        anResult = true;
    }
    else
    {
        GDE::Log::error("ConfigReader::loadFromFile",  Utils::StringFormat("Error al leer fichero %s .", theFilename.c_str()));
    }

    // Devuelve true en caso de éxito, false en caso contrario
    return anResult;
}

ConfigReader& ConfigReader::operator=(const ConfigReader& theRight)
{
    // Usamos el contructor de copia
    ConfigReader temp(theRight);

    // Intercambiamos las copias
    std::swap(this->sections, temp.sections);

    // Devolvemos el puntero
    return *this;
}

std::string ConfigReader::parseLine(const char* theLine,
    const unsigned long theCount, const std::string theSection)
{
    std::string anResult = theSection;
    size_t anLength = strlen(theLine);
    if (anLength > 1)
    {
        // Ignoramos los espacios
        size_t anOffset = 0;
        while (anOffset < anLength && theLine[anOffset] == ' ')
        {
            anOffset++;
        }

        // Comprobamos si hay comentarios
        if (theLine[anOffset] != '#' && theLine[anOffset] != ';')
        {
            // Comprobamos el comienzo de una nueva sección
            if (theLine[anOffset] == '[')
            {
                // Saltamos el inicio de sección '['
                anOffset++;

                // Ignoramos los espacios
                while (anOffset < anLength && theLine[anOffset] == ' ')
                {
                    anOffset++;
                }

                // Obtenemos el nombre de la sección mientras buscamos el final de la sección ']'
                size_t anIndex = 0;
                char anSection[MAX_CHARS] = { 0 };
                while ((anOffset + anIndex) < anLength && theLine[anOffset + anIndex] != ']')
                {
                    // Obtenemos el nombre de la sección de theLine
                    anSection[anIndex] = theLine[anOffset + anIndex];

                    // Incrementamos anIndex
                    anIndex++;
                }
                // Añadimos el delimitador de final de cadena
                anSection[anIndex] = '\0';
                // Eliminamos espacios finales
                while (anIndex > 0 && anSection[anIndex - 1] == ' ')
                {
                    // Ponemos el delimitador de final de cadena a la sección
                    anSection[--anIndex] = '\0';
                }

                //Solo actualizamos el nombre de sección si encontramos el deliminador de sección ']'
                //antes del final de la línea
                if ((anOffset + anIndex) < anLength && anIndex > 0)
                {
                    // Actualizamos el nombre de la sección
                    anResult = anSection;
                }
                else
                {
                    GDE::Log::error("ConfigReader::parseLine",
									 Utils::StringFormat("No se encontró el delimitador de sección ']' en la línea %d", theCount));
                }
            }
            // Leemos el par <clave,valor> de la sección actual.
            else
            {
                size_t anNameIndex = 0;
                char anName[MAX_CHARS];

                // Obtenemos la clave mientras buscamos "=" o ":"
                while ((anOffset + anNameIndex) < anLength &&
                    theLine[(anOffset + anNameIndex)] != '=' &&
                    theLine[(anOffset + anNameIndex)] != ':')
                {
                    // Obtenemos anName de theLine
                    anName[anNameIndex] = theLine[anOffset + anNameIndex];

                    // Incrementamos anNameIndex
                    anNameIndex++;
                }
                // Asignamos nuestro valor offset
                anOffset += anNameIndex;
                // Ponemos el delimitador de cadena
                anName[anNameIndex] = '\0';
                // Eliminamos los espacios del final
                while (anNameIndex > 0 && anName[anNameIndex - 1] == ' ')
                {
                    // Ponemos el delimitador de cadena
                    anName[--anNameIndex] = '\0';
                }

                // Solo buscamos el valor si encontramos el delimitador ":" o "="
                if (anOffset < anLength && anNameIndex > 0)
                {
                    size_t anValueIndex = 0;
                    char anValue[MAX_CHARS];

                    // Nos saltamos el delimitador ":" o "="
                    anOffset++;

                    // Eliminamos espacios
                    while (anOffset < anLength && theLine[anOffset] == ' ')
                    {
                        anOffset++;
                    }
                    // Obtenemos el valor mientras buscamos el final de línea o el comienzo de un comentario
                    while ((anOffset + anValueIndex) < anLength &&
                        theLine[(anOffset + anValueIndex)] != '\r' &&
                        theLine[(anOffset + anValueIndex)] != '\n' &&
                        theLine[(anOffset + anValueIndex)] != ';' &&
                        theLine[(anOffset + anValueIndex)] != '#')
                    {
                        // Obtenemos anValue de theLine
                        anValue[anValueIndex] = theLine[anOffset + anValueIndex];

                        // Incrementamos anValueIndex
                        anValueIndex++;
                    }
                    // Ponemos el delimitador de final de cadena
                    anValue[anValueIndex] = '\0';
                    // Eliminamos los espacios
                    while (anValueIndex > 0 && anValue[anValueIndex - 1] == ' ')
                    {
                        // Ponemos el delimitador de final de cadena
                        anValue[--anValueIndex] = '\0';
                    }

                    // Almacenamos el par <clave,valor>
                    storeNameValue(theSection, anName, anValue);
                }
                else
                {
                    GDE::Log::error("ConfigReader::parseLine",
									 Utils::StringFormat("No se encontró el delimitador de nombre o valor '=' o ':' en la línea %d", theCount));
                }
            }
        } // if(theLine[anOffset] != '#' && theLine[anOffset] != ';')
    } // if(anLength > 1)

    // Devolvemos la el nombre de la nueva sección en caso de encontrarla, en caso contrario
    // se devuelve el nombre de la sección anterior
    return anResult;
}

void ConfigReader::storeNameValue(const std::string theSection,
    const std::string theName, const std::string theValue)
{
    // Comprobamos si el par <clave,valor> ya existe para theSection
    std::map<const std::string, typeNameValue*>::iterator iterSection;
    iterSection = this->sections.find(theSection);
    if (iterSection == this->sections.end())
    {
        // Intentamos crear un nuevo mapa para almacenar los pares <clave,valor> de dicha sección
        typeNameValue* anMap = new(std::nothrow) typeNameValue;

        // Nos aseguramos de que hemos creado el mapa correctamente
        if (NULL != anMap)
        {
            GDE::Log::info("ConfigReader::StoreNameValue","Añadiendo "+theName+"="+theValue + " a la sección [" + theSection+"].");

            // Añadimos el nuevo par <clave,valor> al mapa
            anMap->insert(std::pair<const std::string, const std::string>(theName, theValue));

            // Añadimos el mapa creado anteriormente a la sección
            this->sections.insert(std::pair<const std::string, typeNameValue*>(theSection, anMap));
        }
        else
        {
            GDE::Log::error("ConfigReader::StoreNameValue","Imposible añadir "+theName+"="+theValue + " a la sección [" + theSection+"] posible falta de memoria.");
        }
    }
    else
    {
        // Retrieve the existing name, value pair map
        typeNameValue* anMap = iterSection->second;

        // Nos aseguramos de que hemos creado el mapa correctamente
        if (NULL != anMap)
        {
            // Nos aseguramos de que el par <clave,valor> no esté ya en el mapa
            typeNameValueIter iterNameValue;
            iterNameValue = anMap->find(theName);
            if (iterNameValue == anMap->end())
            {
                GDE::Log::info("ConfigReader::StoreNameValue","Añadiendo "+theName+"="+theValue + " a la sección [" + theSection+"].");
                // Añadimos el nuevo par <clave,valor>
                anMap->insert(std::pair<const std::string, const std::string>(theName, theValue));
            }
            else
            {
                GDE::Log::error("ConfigReader::StoreNameValue","Imposible añadir "+theName+"="+theValue + " a la sección [" + theSection+"] porque ya existe.");
            }
        }
    } // else(iterSection == mSections.end())
}

} } // namespace GDE::Core
