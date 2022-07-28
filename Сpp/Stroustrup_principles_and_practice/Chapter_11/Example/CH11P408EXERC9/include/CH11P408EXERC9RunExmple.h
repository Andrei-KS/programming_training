/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/28/2022 17:18:28
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC9__
#define __CH11P408EXERC9__

#include "RunCommandOfExample.h"

/*
* Write a program is content next subprograms: one program that
* converts an ordinary text file into binary and one program that reads
* binary and converts it to text.
*
* @author Andrei-KS
*/
class CH11P408EXERC9RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC9__