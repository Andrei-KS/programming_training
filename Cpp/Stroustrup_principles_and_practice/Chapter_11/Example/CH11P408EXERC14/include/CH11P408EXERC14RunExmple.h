/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 14:13:47
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC14__
#define __CH11P408EXERC14__

#include "RunCommandOfExample.h"

/*
* Write a program that reads a text file and writes out how many characters
* of each character classification are in the file
*
* @author Andrei-KS
*/
class CH11P408EXERC14RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC14__