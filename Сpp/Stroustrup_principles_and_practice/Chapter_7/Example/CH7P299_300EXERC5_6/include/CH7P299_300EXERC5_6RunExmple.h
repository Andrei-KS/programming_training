/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 12/08/2021 05:52:40
	author                                       : Andrei-KS
*/
#ifndef __CH7P299_300EXERC5_6__
#define __CH7P299_300EXERC5_6__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH7P299_300EXERC5_6RunExmple : public RunCommandOfExample
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

#endif // !__CH7P299_300EXERC5_6__