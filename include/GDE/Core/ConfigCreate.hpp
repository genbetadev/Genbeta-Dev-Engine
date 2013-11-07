#ifndef GDE_CORE_CONFIG_CREATE_HPP
#define GDE_CORE_CONFIG_CREATE_HPP

#include <string>
#include <fstream>
#include <SFML/System/NonCopyable.hpp>
#include <GDE/Config.hpp>

namespace GDE
{

class GDE_API ConfigCreate : sf::NonCopyable
{
public:
	ConfigCreate();

	~ConfigCreate();

	void open(const std::string& theFilename);

	void close();

	void putSection(const std::string& theSection);

	void putValue(const std::string& theKey, const std::string& theValue);

	void putComment(const std::string& theComment);

	void putBlankLine();

private:
	std::ofstream file;

}; // class ConfigCreate

} // namespace GDE

#endif // GDE_CORE_CONFIG_CREATE_HPP