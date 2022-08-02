/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/28/2022 12:45:24
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC6__
#define __CH11P408EXERC6__

#include "RunCommandOfExample.h"

/*
* Write a program that replaces punctuation with whitespace. Consider
* . (dot),  (semicolon), , (comma), ? (question mark), - (dash), ' (single
* quote) punctuation characters. Don’t modify characters within a pair of
* double quotes ("). For example, " - don't use the as-if rule." becomes
* " don t use the as if rule ".
*
* @author Andrei-KS
*/
class CH11P408EXERC6RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC6__