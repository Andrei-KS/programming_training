/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 17:42:07
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC16__
#define __CH11P408EXERC16__

#include "RunCommandOfExample.h"

/*
* Write a program to read a file of whitespace-separated numbers and
* output them in order (lowest value first), one value per line. Write a value
* only once, and if it occurs more than once write the count of its occurrences
* on its line. For example, 7 5 5 7 3 117 5 should give
#									/	3
#									/	5		3
#									/	7		2
#									/	117
*
* @author Andrei-KS
*/
class CH11P408EXERC16RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC16__