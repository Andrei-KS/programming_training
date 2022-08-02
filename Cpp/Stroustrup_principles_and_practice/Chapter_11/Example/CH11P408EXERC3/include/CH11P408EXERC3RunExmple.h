/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/26/2022 13:41:04
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC3__
#define __CH11P408EXERC3__

#include "RunCommandOfExample.h"

/**
* Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc pn tm!.
* @author Andrei-KS
*/
class CH11P408EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC3__