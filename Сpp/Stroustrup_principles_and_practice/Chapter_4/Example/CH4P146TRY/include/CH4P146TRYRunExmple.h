/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 14:35:56
	author                                       : Andrei-KS
*/
#ifndef __CH4P146TRY__
#define __CH4P146TRY__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH4P146TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH4P146TRY__