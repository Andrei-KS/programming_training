/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/08/2022 15:09:07
	author														: Andrei-KS
*/
#ifndef __CH10P377EXERC2__
#define __CH10P377EXERC2__

#include "RunCommandOfExample.h"

/**
* Write a program that creates a file of data in the form of the temperature Reading type. For testing, fill the file with at least 50 “temperature readings.” Call this program and the file it creates raw_temps.txt.
* @author Andrei-KS
*/
class CH10P377EXERC2RunExmple : public RunCommandOfExample
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

#endif // !__CH10P377EXERC2__