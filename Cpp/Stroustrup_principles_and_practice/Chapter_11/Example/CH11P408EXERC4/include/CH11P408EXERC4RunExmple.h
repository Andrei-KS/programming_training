/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/26/2022 18:53:21
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC4__
#define __CH11P408EXERC4__

#include "RunCommandOfExample.h"

/*
* Write a program that prompts the user to enter several integers in any
* combination of octal, decimal, or hexadecimal, using the 0 and 0x base
* suffixes interprets the numbers correctly and converts them to decimal
* form.Then your program should output the values in properly spaced
* columns like this:
*    0x43 hexadecimal converts to 67 decimal
*
* @author Andrei-KS
*/
class CH11P408EXERC4RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC4__