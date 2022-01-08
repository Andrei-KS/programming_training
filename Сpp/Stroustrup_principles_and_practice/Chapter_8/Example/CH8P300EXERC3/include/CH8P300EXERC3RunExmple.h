/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 12/22/2021 09:06:27
	author                                       : Andrei-KS
*/
#ifndef __CH8P300EXERC3__
#define __CH8P300EXERC3__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH8P300EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH8P300EXERC3__