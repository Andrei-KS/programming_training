/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 11/04/2021 22:04:56
	author                                       : Andrei-KS
*/
#ifndef __CH6P263TASK__
#define __CH6P263TASK__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH6P263TASKRunExmple : public RunCommandOfExample
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

#endif // !__CH6P263TASK__