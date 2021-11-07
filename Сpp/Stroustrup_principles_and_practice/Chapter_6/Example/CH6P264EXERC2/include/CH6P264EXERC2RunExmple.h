/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 11/07/2021 12:23:39
	author                                       : Andrei-KS
*/
#ifndef __CH6P264EXERC2__
#define __CH6P264EXERC2__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH6P264EXERC2RunExmple : public RunCommandOfExample
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

#endif // !__CH6P264EXERC2__