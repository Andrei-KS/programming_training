/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/19/2021 10:31:18
	author                                       : Andrei-KS
*/
#ifndef __CH4P167TASK11__
#define __CH4P167TASK11__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH4P167TASK11RunExmple : public RunCommandOfExample
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

#endif // !__CH4P167TASK11__