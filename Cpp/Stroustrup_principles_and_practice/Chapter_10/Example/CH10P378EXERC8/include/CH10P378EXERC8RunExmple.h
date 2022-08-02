/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/13/2022 18:40:57
	author														: Andrei-KS
*/
#ifndef __CH10P378EXERC8__
#define __CH10P378EXERC8__

#include "RunCommandOfExample.h"

/**
* Write a program that accepts two file names and produces a new file that is the contents of the first file followed by the contents of the second that is, the program concatenates the two files.
* @author Andrei-KS
*/
class CH10P378EXERC8RunExmple : public RunCommandOfExample
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

#endif // !__CH10P378EXERC8__