/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/16/2021 11:06:23
	author                                       : Andrei-KS
*/
#ifndef __CH3P124TASK1__
#define __CH3P124TASK1__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH3P124TASK1RunExmple : public RunCommandOfExample
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

#endif // !__CH3P124TASK1__