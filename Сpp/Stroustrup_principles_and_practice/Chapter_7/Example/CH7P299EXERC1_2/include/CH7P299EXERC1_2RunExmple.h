/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 11/30/2021 10:08:51
	author                                       : Andrei-KS
*/
#ifndef __CH7P299EXERC1_2__
#define __CH7P299EXERC1_2__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class CH7P299EXERC1_2RunExmple : public RunCommandOfExample
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

#endif // !__CH7P299EXERC1_2__