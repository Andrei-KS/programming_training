/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 02/02/2022 09:05:59
	author                                       : Andrei-KS
*/
#ifndef __CH9P341EXERC15__
#define __CH9P341EXERC15__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH9P341EXERC15RunExmple : public RunCommandOfExample
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

#endif // !__CH9P341EXERC15__