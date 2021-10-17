/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/18/2021 01:12:08
	author                                       : Andrei-KS
*/
#ifndef __CH4P166TASK6__
#define __CH4P166TASK6__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH4P166TASK6RunExmple : public RunCommandOfExample
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

#endif // !__CH4P166TASK6__