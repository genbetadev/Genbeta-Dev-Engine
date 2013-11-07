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
	ConfigReader();

	ConfigReader(const ConfigReader& theCopy);

	ConfigReader& operator=(const ConfigReader& theRight);

	~ConfigReader();

	bool loadFromFile(const std::string& filename);

	bool isSectionEmpty(const std::string theSection) const;

	bool GetBool(const std::string theSection, const std::string theName, const bool theDefault = false) const;

	float GetFloat(const std::string theSection, const std::string theName, const float theDefault = 0.f) const;

	std::string GetString(const std::string theSection, const std::string theName, const std::string theDefault = "") const;

	sf::Uint32 GetUint32(const std::string theSection, const std::string theName, const sf::Uint32 theDefault = 0) const;

private:
	// CONSTANTES
	static const unsigned short MAX_CHARS = 100;
	// VARIABLES
	/// Map to store all the sections and their corresponding name=value pairs
	std::map<const std::string, GDE::typeNameValue*> mSections;

	std::string parseLine(const char* theLine, const unsigned long theCount,const std::string theSection);

	void storeNameValue(const std::string theSection, const std::string theName, const std::string theValue);

}; // class ConfigReader

} // namespace GDE

#endif // GDE_CORE_CONFIG_READER_HPP