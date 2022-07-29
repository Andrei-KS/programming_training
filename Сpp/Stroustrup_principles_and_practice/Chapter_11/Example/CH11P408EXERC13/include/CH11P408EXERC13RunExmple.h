/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/29/2022 18:24:10
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC13__
#define __CH11P408EXERC13__

#include "RunCommandOfExample.h"

/*
* Reverse the order of words (defined as whitespace-separated strings) in a
* file. For example, Norwegian Blue parrot becomes parrot Blue Norwegian.
* You are allowed to assume that all the strings from the file will fit into
* memory at once.
*
* @author Andrei-KS
*/
class CH11P408EXERC13RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC13__