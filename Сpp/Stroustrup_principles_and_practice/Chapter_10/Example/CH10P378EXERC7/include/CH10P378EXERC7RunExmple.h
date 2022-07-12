/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/12/2022 17:04:52
	author														: Andrei-KS
*/
#ifndef __CH10P378EXERC7__
#define __CH10P378EXERC7__

#include "RunCommandOfExample.h"

/**
* Make a version of the calculator from Chapter 7 that accepts Roman numerals rather than the usual Arabic ones, for example, XXI + CIV == CXXV.
* @author Andrei-KS
*/
class CH10P378EXERC7RunExmple : public RunCommandOfExample
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

#endif // !__CH10P378EXERC7__