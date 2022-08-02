/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/25/2022 12:24:38
	author														: Andrei-KS
*/
#ifndef __CH11P388TRY__
#define __CH11P388TRY__

#include "RunCommandOfExample.h"

/**
* Make a simple table including the last name, first name, telephone number, and email address for yourself and at least five of your friends.
* @author Andrei-KS
*/
class CH11P388TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH11P388TRY__