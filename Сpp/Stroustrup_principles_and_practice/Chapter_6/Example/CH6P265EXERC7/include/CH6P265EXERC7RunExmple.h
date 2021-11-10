/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 11/10/2021 00:15:43
	author                                       : Andrei-KS
*/
#ifndef __CH6P265EXERC7__
#define __CH6P265EXERC7__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH6P265EXERC7RunExmple : public RunCommandOfExample
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

#endif // !__CH6P265EXERC7__