/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/28/2021 00:45:17
	author                                       : Andrei-KS
*/
#ifndef __CH5P188TRY__
#define __CH5P188TRY__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH5P188TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH5P188TRY__