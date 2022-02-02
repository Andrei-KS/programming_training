/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 02/01/2022 09:15:09
	author                                       : Andrei-KS
*/
#ifndef __CH9P340EXERC14__
#define __CH9P340EXERC14__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH9P340EXERC14RunExmple : public RunCommandOfExample
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

#endif // !__CH9P340EXERC14__