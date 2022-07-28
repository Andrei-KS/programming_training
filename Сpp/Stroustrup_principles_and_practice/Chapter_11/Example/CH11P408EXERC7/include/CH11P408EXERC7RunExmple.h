/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/28/2022 14:52:21
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC7__
#define __CH11P408EXERC7__

#include "RunCommandOfExample.h"

/*
* Modify the program from the previous exercise so that it replaces don't
* with do not, can't with can not, etc. leaves hyphens within words intact
* (so that we get “ do not use the as-if rule ”) and converts all characters
* to lower case.
*
* @author Andrei-KS
*/
class CH11P408EXERC7RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC7__