/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 13:05:14
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC8__
#define __CH11P408EXERC8__

#include "RunCommandOfExample.h"

/*
* Use the program from the previous exercise to make a dictionary.
* Run the result on a multi-page text file, look at the result,
* and see if you can improve the program to make a better dictionary.
*
* @author Andrei-KS
*/
class CH11P408EXERC8RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC8__