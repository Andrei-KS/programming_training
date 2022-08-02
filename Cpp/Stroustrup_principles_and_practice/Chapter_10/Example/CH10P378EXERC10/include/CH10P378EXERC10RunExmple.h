/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/14/2022 14:57:26
	author														: Andrei-KS
*/
#ifndef __CH10P378EXERC10__
#define __CH10P378EXERC10__

#include "RunCommandOfExample.h"

/**
* Add a command from x to the calculator from Chapter 7 that makes it take input from a file x. Add a command to y to the calculator that makes it write its output (both standard output and error output) to file y. 
* @author Andrei-KS
*/
class CH10P378EXERC10RunExmple : public RunCommandOfExample
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

#endif // !__CH10P378EXERC10__