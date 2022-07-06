/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/30/2021 17:02:36
	author														: Andrei-KS
*/
#ifndef __CH5P214EXERC4__
#define __CH5P214EXERC4__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH5P214EXERC4RunExmple : public RunCommandOfExample
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

#endif // !__CH5P214EXERC4__