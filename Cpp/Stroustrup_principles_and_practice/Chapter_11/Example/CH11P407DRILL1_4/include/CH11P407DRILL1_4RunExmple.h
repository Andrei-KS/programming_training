/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/25/2022 18:12:16
	author														: Andrei-KS
*/
#ifndef __CH11P407DRILL1_4__
#define __CH11P407DRILL1_4__

#include "RunCommandOfExample.h"

/**
* Declare an integer birth_year and assign it the year you were born. Output your birth_year in decimal, hexadecimal, and octal form. Label each value with the name of the base used. Did you line up your output in columns using the tab character? If not, do it.
* @author Andrei-KS
*/
class CH11P407DRILL1_4RunExmple : public RunCommandOfExample
{
public:
	/**
	 * The main function launch to run a example.
	 * This function can use command line parameters
	 * via self variables itsArgC, itsArgV
	 *
	 * @see RunCommandOfExample
	 */
	virtual int excute() override;
};

#endif // !__CH11P407DRILL1_4__