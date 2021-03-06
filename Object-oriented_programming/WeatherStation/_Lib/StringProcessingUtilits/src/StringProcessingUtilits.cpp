

#include "StringProcessingUtilits.h"

std::vector<std::string> StringProcessingUtilits::SplitStringToVector(const std::string& sourceString, const char delimiterSymbol)
{
	std::vector<std::string> outputVector;
	size_t currentWordInVetor = 0;
	bool addNewWordFlag = true;
	size_t sizeString = sourceString.size();
	for (size_t i = 0; i < sizeString; i++)
	{
		if ((sourceString[i] == delimiterSymbol) || (sourceString[i] == '\0'))
		{
			if ((outputVector.size() != 0) && (outputVector[currentWordInVetor].size() != 0))
			{
				addNewWordFlag = true;
				currentWordInVetor++;
			}
		}
		else
		{
			if (addNewWordFlag)
			{
				outputVector.push_back(std::string({ sourceString[i] }));
				addNewWordFlag = false;
			}
			else
			{
				outputVector[currentWordInVetor].push_back(sourceString[i]);
			}
		}
	}
	return std::move(outputVector);
}

std::string StringProcessingUtilits::getStringOfGivenLength(std::string sourceString, size_t length, char placeHolders)
{
	size_t lengthSourceString = sourceString.length();
	std::string ret(length, placeHolders);
	size_t minimumLength = lengthSourceString > length ? length : lengthSourceString;
	for (int i = 0; i < minimumLength; i++)
	{
		ret[length - i - 1] = sourceString[lengthSourceString - i - 1];
	}
	return std::move(ret);
}