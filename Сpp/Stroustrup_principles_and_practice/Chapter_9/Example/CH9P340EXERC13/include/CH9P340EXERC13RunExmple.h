/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 01/30/2022 00:03:23
	author                                       : Andrei-KS
*/
#ifndef __CH9P340EXERC13__
#define __CH9P340EXERC13__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH9P340EXERC13RunExmple : public RunCommandOfExample
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

#endif // !__CH9P340EXERC13__