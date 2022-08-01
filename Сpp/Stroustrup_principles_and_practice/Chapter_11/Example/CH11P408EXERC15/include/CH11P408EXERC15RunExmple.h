/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 16:34:18
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC15__
#define __CH11P408EXERC15__

#include "RunCommandOfExample.h"

/*
* Write a program that reads a file of whitespace-separated numbers and
* outputs a file of numbers using scientific format and precision 8 in four
* fields of 20 characters per line.
*
* @author Andrei-KS
*/
class CH11P408EXERC15RunExmple : public RunCommandOfExample
{
public:
	/*
	 * The main function launch to run a example.
	 * This function can use command line parameters
	 * via self variables itsArgC, itsArgV
	 *
	 * @see RunCommandOfExample
	 */
	virtual int excute() override;
};

#endif // !__CH11P408EXERC15__