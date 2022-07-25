/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/25/2022 18:21:30
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC1__
#define __CH11P408EXERC1__

#include "RunCommandOfExample.h"

/**
* Write a program that reads a text file and converts its input to all lower case, producing a new file.
* @author Andrei-KS
*/
class CH11P408EXERC1RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC1__