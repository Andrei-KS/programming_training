

#include "UTestGetStringOfGivenLength.h"
#include <cassert>

myUTest* myUTest::Utest = new UTestGetStringOfGivenLength();

void UTestGetStringOfGivenLength::excute()
{
	TestEmptyString();
	TestDifferentAmountLetterInWord("a", ' ', 3, "  a");
	TestDifferentAmountLetterInWord("aa", ' ', 3, " aa");
	TestDifferentAmountLetterInWord("aaa", ' ', 3, "aaa");

}

void UTestGetStringOfGivenLength::TestEmptyString()
{
	const size_t Givenlength = 5;
	const char placeHolder = '-';
	assert(StringProcessingUtilits::getStringOfGivenLength(std::string(), Givenlength, placeHolder) == std::string(Givenlength, placeHolder));
}

void UTestGetStringOfGivenLength::TestDifferentAmountLetterInWord(std::string wordIn, char placeHolder, size_t lengthOut, std::string correctWord)
{
	assert(StringProcessingUtilits::getStringOfGivenLength(wordIn, lengthOut, placeHolder) == correctWord);
}


