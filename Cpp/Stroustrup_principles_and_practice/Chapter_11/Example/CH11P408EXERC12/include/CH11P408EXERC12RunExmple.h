/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/29/2022 17:06:33
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC12__
#define __CH11P408EXERC12__

#include "RunCommandOfExample.h"

/*
* Reverse the order of characters in a text file. For example, asdfghjkl
* becomes lkjhgfdsa. Warning: There is no really good, portable, and efficient
* way of reading a file backward.
*
* @author Andrei-KS
*/
class CH11P408EXERC12RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC12__