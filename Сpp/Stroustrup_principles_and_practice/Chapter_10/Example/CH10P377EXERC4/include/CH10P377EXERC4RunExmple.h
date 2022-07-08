/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/08/2022 18:01:26
	author														: Andrei-KS
*/
#ifndef __CH10P377EXERC4__
#define __CH10P377EXERC4__

#include "RunCommandOfExample.h"

/**
* Modify the program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit temperatures. Then modify the program from exercise 3 to test each temperature, converting the Celsius readings to Fahrenheit before putting them into the vector
* @author Andrei-KS
*/
class CH10P377EXERC4RunExmple : public RunCommandOfExample
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

#endif // !__CH10P377EXERC4__