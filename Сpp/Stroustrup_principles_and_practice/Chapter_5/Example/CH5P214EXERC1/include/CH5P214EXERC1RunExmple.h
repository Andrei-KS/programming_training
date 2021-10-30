/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/30/2021 12:43:42
	author                                       : Andrei-KS
*/
#ifndef __CH5P214EXERC1__
#define __CH5P214EXERC1__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH5P214EXERC1RunExmple : public RunCommandOfExample
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

#endif // !__CH5P214EXERC1__