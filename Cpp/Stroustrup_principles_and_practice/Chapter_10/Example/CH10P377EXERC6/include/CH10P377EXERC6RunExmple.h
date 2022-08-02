/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/11/2022 18:28:45
	author														: Andrei-KS
*/
#ifndef __CH10P377EXERC6__
#define __CH10P377EXERC6__

#include "RunCommandOfExample.h"

/**
* Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. Provide Roman_int with an as_int() member that returns the int value, so that if r is a Roman_int, we can write cout << "Roman" << r << " equals " << r.as_int() << '\n'.
* @author Andrei-KS
*/
class CH10P377EXERC6RunExmple : public RunCommandOfExample
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

#endif // !__CH10P377EXERC6__