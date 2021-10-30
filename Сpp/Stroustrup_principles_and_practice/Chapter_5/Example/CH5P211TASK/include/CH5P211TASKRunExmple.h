/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/29/2021 10:18:22
	author                                       : Andrei-KS
*/
#ifndef __CH5P211TASK__
#define __CH5P211TASK__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH5P211TASKRunExmple : public RunCommandOfExample
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

#endif // !__CH5P211TASK__