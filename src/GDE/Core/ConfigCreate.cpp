#include <GDE/Core/ConfigCreate.hpp>

namespace GDE
{

ConfigCreate::ConfigCreate()
{
}

ConfigCreate::~ConfigCreate()
{
}

void ConfigCreate::Open(const std::string& theFilename)
{
	this->file.open(theFilename);
	this->file.clear();
}

void ConfigCreate::Close()
{
	this->file.close();
}

void ConfigCreate::PutSection(const std::string& theSection)
{
	this->file << "[" << theSection << "]" << std::endl;
}

void ConfigCreate::PutValue(const std::string& theKey, const std::string& theValue)
{
	this->file << theKey << "=" << theValue << std::endl;
}

void ConfigCreate::PutComment(const std::string& theComment)
{
	this->file << "# " << theComment << std::endl;
}

void ConfigCreate::PutBlankLine()
{
	this->file << std::endl;
}

} // namespace GDE