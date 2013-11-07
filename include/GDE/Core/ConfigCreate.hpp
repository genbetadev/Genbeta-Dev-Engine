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

	void Open(const std::string& theFilename);

	void Close();

	void PutSection(const std::string& theSection);

	void PutValue(const std::string& theKey, const std::string& theValue);

	void PutComment(const std::string& theComment);

	void PutBlankLine();

private:
	std::ofstream file;

}; // class ConfigCreate

} // namespace GDE

#endif // GDE_CORE_CONFIG_CREATE_HPP