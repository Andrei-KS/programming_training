/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/16/2021 12:09:27
	author                                       : Andrei-KS
*/
#ifndef __CH3P125TASK5__
#define __CH3P125TASK5__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH3P125TASK5RunExmple : public RunCommandOfExample
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

#endif // !__CH3P125TASK5__