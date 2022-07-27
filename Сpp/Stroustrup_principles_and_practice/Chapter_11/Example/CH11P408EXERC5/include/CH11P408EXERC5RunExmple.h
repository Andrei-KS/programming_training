/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/27/2022 15:47:52
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC5__
#define __CH11P408EXERC5__

#include "RunCommandOfExample.h"

/*
* Write a program that reads strings and for each string outputs the
* character classification of each character, as defined by
* the character classification. Note that a character can have several
* classifications (e.g., x is both a letter and an alphanumeric).
*
* @author Andrei-KS
*/
class CH11P408EXERC5RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC5__