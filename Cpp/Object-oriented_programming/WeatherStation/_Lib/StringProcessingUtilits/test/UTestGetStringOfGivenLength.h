#ifndef __UTESTGETSTRINGOFGIVENLENGTH_H__
#define __UTESTGETSTRINGOFGIVENLENGTH_H__

#include "myUTest.h"
#include "StringProcessingUtilits.h"

/**
* Description of class UTestGetStringOfGivenLength
*/
class UTestGetStringOfGivenLength : public myUTest
{
public:
	/**
	* Function to run all tests
	*/
	virtual void excute() override;

protected:
	/**
	* Function check correct work function with empty string
	*/
	void TestEmptyString();

	/**
	* 
	*/
	void TestDifferentAmountLetterInWord(std::string wordIn, char placeHolder, size_t lengthOut, std::string correctWord);
};

#endif // !__UTESTGETSTRINGOFGIVENLENGTH_H__