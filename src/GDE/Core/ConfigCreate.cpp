#include <GDE/Core/ConfigCreate.hpp>

namespace GDE
{

ConfigCreate::ConfigCreate()
{
}

ConfigCreate::~ConfigCreate()
{
}

void ConfigCreate::open(const std::string& theFilename)
{
	this->file.open(theFilename.c_str());
	this->file.clear();
}

void ConfigCreate::close()
{
	this->file.close();
}

void ConfigCreate::putSection(const std::string& theSection)
{
	this->file << "[" << theSection << "]" << std::endl;
}

void ConfigCreate::putValue(const std::string& theKey, const std::string& theValue)
{
	this->file << theKey << "=" << theValue << std::endl;
}

void ConfigCreate::putComment(const std::string& theComment)
{
	this->file << "# " << theComment << std::endl;
}

void ConfigCreate::putBlankLine()
{
	this->file << std::endl;
}

} // namespace GDE