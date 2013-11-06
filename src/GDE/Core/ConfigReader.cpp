#include <GDE/Core/ConfigReader.hpp>
#include <GDE/Core/StringsUtil.hpp>

namespace GDE
{

ConfigReader::ConfigReader()
{
	////ILOGM("ConfigReader::ctor()");
}

ConfigReader::ConfigReader(const ConfigReader& theCopy) :
	mSections(theCopy.mSections)
{
}

ConfigReader::~ConfigReader()
{
	////ILOGM("ConfigReader::dtor()");

	// Delete all section name, value maps
	std::map<const std::string, typeNameValue*>::iterator iter;
	iter = mSections.begin();
	while (iter != mSections.end())
	{
		typeNameValue* anMap = iter->second;
		mSections.erase(iter++);
		delete anMap;
	}
}

bool ConfigReader::isSectionEmpty(const std::string theSection) const
{
	bool anResult = false;

	// Check if theSection really exists
	std::map<const std::string, typeNameValue*>::const_iterator iter;
	iter = mSections.find(theSection);
	if (iter != mSections.end())
	{
		typeNameValue* anMap = iter->second;
		if (NULL != anMap)
		{
			anResult = anMap->empty();
		}
	}

	// Return the result found above or the default value of false
	return anResult;
}

bool ConfigReader::GetBool(const std::string theSection,
	const std::string theName, const bool theDefault) const
{
	bool anResult = theDefault;

	// Check if theSection really exists
	std::map<const std::string, typeNameValue*>::const_iterator iter;
	iter = mSections.find(theSection);
	if (iter != mSections.end())
	{
		// Try to obtain the name, value pair
		typeNameValue* anMap = iter->second;
		if (NULL != anMap)
		{
			typeNameValueIter iterNameValue;
			iterNameValue = anMap->find(theName);
			if (iterNameValue != anMap->end())
			{
				anResult = parseBool(iterNameValue->second, theDefault);
			}
		}
	}

	// Return the result found or theDefault assigned above
	return anResult;
}

float ConfigReader::GetFloat(const std::string theSection,
	const std::string theName, const float theDefault) const
{
	float anResult = theDefault;

	// Check if theSection really exists
	std::map<const std::string, typeNameValue*>::const_iterator iter;
	iter = mSections.find(theSection);
	if (iter != mSections.end())
	{
		// Try to obtain the name, value pair
		typeNameValue* anMap = iter->second;
		if (NULL != anMap)
		{
			typeNameValueIter iterNameValue;
			iterNameValue = anMap->find(theName);
			if (iterNameValue != anMap->end())
			{
				anResult = parseFloat(iterNameValue->second, theDefault);
			}
		}
	}

	// Return the result found or theDefault assigned above
	return anResult;
}

std::string ConfigReader::GetString(const std::string theSection,
	const std::string theName, const std::string theDefault) const
{
	std::string anResult = theDefault;

	// Check if theSection really exists
	std::map<const std::string, typeNameValue*>::const_iterator iter;
	iter = mSections.find(theSection);
	if (iter != mSections.end())
	{
		// Try to obtain the name, value pair
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

	// Return the result found or theDefault assigned above
	return anResult;
}

sf::Uint32 ConfigReader::GetUint32(const std::string theSection, const std::string theName, const sf::Uint32 theDefault) const
{
	sf::Uint32 anResult = theDefault;

	// Check if theSection really exists
	std::map<const std::string, typeNameValue*>::const_iterator iter;
	iter = mSections.find(theSection);
	if (iter != mSections.end())
	{
		// Try to obtain the name, value pair
		typeNameValue* anMap = iter->second;
		if (NULL != anMap)
		{
			typeNameValueIter iterNameValue;
			iterNameValue = anMap->find(theName);
			if (iterNameValue != anMap->end())
			{
				anResult = parseUint32(iterNameValue->second, theDefault);
			}
		}
	}

	// Return the result found or theDefault assigned above
	return anResult;
}

bool ConfigReader::loadFromFile(const std::string& theFilename)
{
	bool anResult = false;
	char anLine[MAX_CHARS];
	std::string anSection;
	unsigned long anCount = 1;

	// Let the log know about the file we are about to read in
	//ILOG() << "ConfigReader:Read(" << theFilename << ") opening..." << std::endl;

	// Attempt to open the file
	FILE* anFile = fopen(theFilename.c_str(), "r");

	// Read from the file if successful
	if (NULL != anFile)
	{
		// Keep reading from configuration file until we reach the end of file marker
		while (!feof(anFile))
		{
			// Get the first line from the file
			if (fgets(anLine, MAX_CHARS, anFile) == NULL)
			{
				// Log the failure to read a line from the file if not at the end of the file
				if (!feof(anFile))
				{
					//ELOG() << "ConfigReader::Read(" << anFile << ") error reading line " << anCount << std::endl;
				}
				// Exit our while loop, were done!
				break;
			}
			else
			{
				// Parse the line
				anSection = parseLine(anLine, anCount, anSection);
			}

			// Increment our Line counter
			anCount++;
		}

		// Don't forget to close the file
		fclose(anFile);

		// Set success result
		anResult = true;
	}
	else
	{
		//ELOG() << "ConfigReader::Read(" << theFilename << ") error opening file" << std::endl;
	}

	// Return anResult of true if successful, false otherwise
	return anResult;
}

ConfigReader& ConfigReader::operator=(const ConfigReader& theRight)
{
	// Use copy constructor to duplicate theRight side
	ConfigReader temp(theRight);

	// Now swap my local copy with the copy from theRight
	std::swap(mSections, temp.mSections);

	// Return my pointer
	return *this;
}

std::string ConfigReader::parseLine(const char* theLine,
	const unsigned long theCount, const std::string theSection)
{
	std::string anResult = theSection;
	size_t anLength = strlen(theLine);
	if (anLength > 1)
	{
		// Skip preceeding spaces at the begining of the line
		size_t anOffset = 0;
		while (anOffset < anLength && theLine[anOffset] == ' ')
		{
			anOffset++;
		}

		// Now check for comments
		if (theLine[anOffset] != '#' && theLine[anOffset] != ';')
		{
			// Next check for the start of a new section
			if (theLine[anOffset] == '[')
			{
				// Skip over the begin section marker '['
				anOffset++;

				// Skip preceeding spaces of section name
				while (anOffset < anLength && theLine[anOffset] == ' ')
				{
					anOffset++;
				}

				// Retrieve the section name while looking for the section end marker ']'
				size_t anIndex = 0;
				char anSection[MAX_CHARS] = { 0 };
				while ((anOffset + anIndex) < anLength && theLine[anOffset + anIndex] != ']')
				{
					// Retrieve the section name from theLine
					anSection[anIndex] = theLine[anOffset + anIndex];

					// Increment anIndex
					anIndex++;
				}
				// Add null terminator
				anSection[anIndex] = '\0';
				// Remove trailing spaces
				while (anIndex > 0 && anSection[anIndex - 1] == ' ')
				{
					// Put a null terminator at the end of the section name
					anSection[--anIndex] = '\0';
				}

				// Only update the current section name if we found the section end
				// marker before the end of the line
				if ((anOffset + anIndex) < anLength && anIndex > 0)
				{
					// Change the return string to the newly parsed section name
					anResult = anSection;
				}
				else
				{
					//ELOG() << "ConfigReader::ParseLine(" << theCount << ") missing section end marker ']'" << std::endl;
				}
			}
			// Just read the name=value pair into the current section
			else
			{
				// Retrieve the name and value while looking for the comment flags ';' or '#'
				size_t anNameIndex = 0;
				char anName[MAX_CHARS];

				// First retrieve the name while looking for either the '=' or ':' delimiter
				while ((anOffset + anNameIndex) < anLength &&
					theLine[(anOffset + anNameIndex)] != '=' &&
					theLine[(anOffset + anNameIndex)] != ':')
				{
					// Retrieve anName from theLine
					anName[anNameIndex] = theLine[anOffset + anNameIndex];

					// Increment anNameIndex
					anNameIndex++;
				}
				// Assign our starting offset value
				anOffset += anNameIndex;
				// Put a null terminator at the end of the name
				anName[anNameIndex] = '\0';
				// Remove trailing spaces from the name
				while (anNameIndex > 0 && anName[anNameIndex - 1] == ' ')
				{
					// Put a null terminator at the end of the name
					anName[--anNameIndex] = '\0';
				}

				// Only search for the value if we found the '=' or ':' delimiter
				if (anOffset < anLength && anNameIndex > 0)
				{
					size_t anValueIndex = 0;
					char anValue[MAX_CHARS];

					// Skip over the delimiter between name and value '=' or ':'
					anOffset++;

					// Skip preceeding spaces
					while (anOffset < anLength && theLine[anOffset] == ' ')
					{
						anOffset++;
					}
					// Next retrieve the value while looking for comments flags ';' or '#'
					while ((anOffset + anValueIndex) < anLength &&
						theLine[(anOffset + anValueIndex)] != '\r' &&
						theLine[(anOffset + anValueIndex)] != '\n' &&
						theLine[(anOffset + anValueIndex)] != ';' &&
						theLine[(anOffset + anValueIndex)] != '#')
					{
						// Retrieve anValue from theLine
						anValue[anValueIndex] = theLine[anOffset + anValueIndex];

						// Increment anValueIndex
						anValueIndex++;
					}
					// Put a null terminator at the end of the section name
					anValue[anValueIndex] = '\0';
					// Remove trailing spaces from the name
					while (anValueIndex > 0 && anValue[anValueIndex - 1] == ' ')
					{
						// Put a null terminator at the end of the name
						anValue[--anValueIndex] = '\0';
					}

					// Store the name,value pair obtained into the current section
					storeNameValue(theSection, anName, anValue);
				}
				else
				{
					//ELOG() << "ConfigReader::ParseLine(" << theCount << ") missing name or value delimiter of '=' or ':'" << std::endl;
				}
			}
		} // if(theLine[anOffset] != '#' && theLine[anOffset] != ';') // Not a comment
	} // if(anLength > 1)

	// Return either the previous section name or the new section name found
	return anResult;
}

void ConfigReader::storeNameValue(const std::string theSection,
	const std::string theName, const std::string theValue)
{
	// Check if the name, value map already exists for theSection
	std::map<const std::string, typeNameValue*>::iterator iterSection;
	iterSection = mSections.find(theSection);
	if (iterSection == mSections.end())
	{
		// First try to create a new name, value pair map for this new section
		typeNameValue* anMap = new(std::nothrow) typeNameValue;

		// Make sure we were able to create the map ok
		if (NULL != anMap)
		{
			//ILOG() << "ConfigReader::StoreNameValue(" << theSection << ") adding (" << theName << "," << theValue << ")" << std::endl;

			// Add the new name, value pair to this map
			anMap->insert(std::pair<const std::string, const std::string>(theName, theValue));

			// Add the new name, value pair map for this new section
			mSections.insert(std::pair<const std::string, typeNameValue*>(theSection, anMap));
		}
		else
		{
			//ELOG() << "ConfigReader::StoreNameValue(" << theSection << ") unable to add (" << theName << "," << theValue << ") out of memory!" << std::endl;
		}
	}
	else
	{
		// Retrieve the existing name, value pair map
		typeNameValue* anMap = iterSection->second;

		// Make sure we were able to retrieve the map ok
		if (NULL != anMap)
		{
			// Make sure the name, value pair doesn't already in the map
			typeNameValueIter iterNameValue;
			iterNameValue = anMap->find(theName);
			if (iterNameValue == anMap->end())
			{
				//ILOG() << "ConfigReader::StoreNameValue(" << theSection << ") adding (" << theName << "," << theValue << ")" << std::endl;

				// Add the new name, value pair to this map
				anMap->insert(std::pair<const std::string, const std::string>(theName, theValue));
			}
			else
			{
				//ELOG() << "ConfigReader::StoreNameValue(" << theSection << ") unable to add (" << theName << "," << theValue << ") already exists!" << std::endl;
			}
		}
	} // else(iterSection == mSections.end())
}

} // namespace GDE