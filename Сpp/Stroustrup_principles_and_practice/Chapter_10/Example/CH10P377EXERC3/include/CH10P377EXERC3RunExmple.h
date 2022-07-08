/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/08/2022 15:47:13
	author														: Andrei-KS
*/
#ifndef __CH10P377EXERC3__
#define __CH10P377EXERC3__

#include "RunCommandOfExample.h"

/**
* Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector and then calculates the mean and median temperatures in your data set.
* @author Andrei-KS
*/
class CH10P377EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH10P377EXERC3__