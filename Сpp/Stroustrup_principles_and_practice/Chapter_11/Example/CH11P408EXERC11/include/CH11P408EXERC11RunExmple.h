/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/29/2022 16:22:50
	author														: Andrei-KS
*/
#ifndef __CH11P408EXERC11__
#define __CH11P408EXERC11__

#include "RunCommandOfExample.h"

/*
* Write a function vector<string> split(const string& s, const string& w)
* that returns a vector of whitespace-separated substrings from
* the argument s, where whitespace is defined as “ordinary whitespace” plus the
* characters in w.
*
* @author Andrei-KS
*/
class CH11P408EXERC11RunExmple : public RunCommandOfExample
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

#endif // !__CH11P408EXERC11__