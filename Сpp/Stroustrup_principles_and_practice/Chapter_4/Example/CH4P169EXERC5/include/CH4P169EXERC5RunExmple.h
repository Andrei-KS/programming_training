/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/25/2021 21:39:09
	author                                       : Andrei-KS
*/
#ifndef __CH4P169EXERC5__
#define __CH4P169EXERC5__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH4P169EXERC5RunExmple : public RunCommandOfExample
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

#endif // !__CH4P169EXERC5__