/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/26/2022 12:37:00
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC2__
#define __CH11P408EXERC2__

#include "RunCommandOfExample.h"

/**
* Write a program that given a file name and a word outputs each line that contains that word together with the line number. Hint: getline()
* @author Andrei-KS
*/
class CH11P408EXERC2RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC2__