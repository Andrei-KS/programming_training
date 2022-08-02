#ifndef __STRINGPROCESSINGUTILITS_H__
#define __STRINGPROCESSINGUTILITS_H__

#include <string>
#include <vector>

/**
* @author Andrei-KS
*/
namespace StringProcessingUtilits
{
	/**
	* 
	*/
	std::vector<std::string> SplitStringToVector(const std::string& sourceString, const char delimiterSymbol = ' ');

	/**
	* Make string of given length
	* @param sourceString -
	* @param length - 
	* @param placeHolders - 
	* return 
	*/
	std::string getStringOfGivenLength(std::string sourceString, size_t length, char placeHolders = ' ');
}

#endif // !__STRINGPROCESSINGUTILITS_H__