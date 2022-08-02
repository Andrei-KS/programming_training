/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/21/2022 18:02:29
	author														: Andrei-KS
*/
#ifndef __CH11P386TRY__
#define __CH11P386TRY__

#include "RunCommandOfExample.h"

/**
* Write some code to print the number 1234567.89 three times, first using defaultfloat, then fixed, then scientific. 
* @author Andrei-KS
*/
class CH11P386TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH11P386TRY__