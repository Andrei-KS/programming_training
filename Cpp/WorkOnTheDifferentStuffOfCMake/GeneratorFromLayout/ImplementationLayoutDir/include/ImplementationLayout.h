/*
	This file is created from a mocks that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                : 07/06/2022 17:07:39
	author                                       : Andrei-KS
*/
#ifndef __ImplementationLayout__
#define __ImplementationLayout__

#include "RunCommandOfExample.h"

/**
* 
* @author Andrei-KS
*/
class ImplementationLayoutRunExmple : public RunCommandOfExample
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

#endif // !__ImplementationLayout__