/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/15/2022 12:15:38
	author														: Andrei-KS
*/
#ifndef __CH10P378EXERC11__
#define __CH10P378EXERC11__

#include "RunCommandOfExample.h"

/**
* Write a program that produces the sum of all the whitespace-separated integers in a text file. For example, bears: 17 elephants 9 end should output 26.
* @author Andrei-KS
*/
class CH10P378EXERC11RunExmple : public RunCommandOfExample
{
public:
	/**
	 * The main function launch to run a example.
	 * This function can use command line parameters
	 * via self variables itsArgC, itsArgV
	 *
	 * @see RunCommandOfExample
	 */
	virtual int excute() override;
};

#endif // !__CH10P378EXERC11__