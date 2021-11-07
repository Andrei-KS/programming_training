/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 11/07/2021 12:52:50
	author                                       : Andrei-KS
*/
#ifndef __CH6P264EXERC3__
#define __CH6P264EXERC3__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH6P264EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH6P264EXERC3__