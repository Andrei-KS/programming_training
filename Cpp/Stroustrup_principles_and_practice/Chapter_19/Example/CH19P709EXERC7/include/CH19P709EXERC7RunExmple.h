/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/22/2023 09:29:24
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC7__
#define __CH19P709EXERC7__

#include "RunCommandOfExample.h"

/*
* Try your solution to exercise 2 with some Numbers.
*
* @author Andrei-KS
*/
class CH19P709EXERC7RunExmple : public RunCommandOfExample
{
public:
  /*
  * The main function launch to run a example.
	* This function can use command line parameters
	* via self variables itsArgC, itsArgV
	*
	* @see RunCommandOfExample
	*/
  virtual int excute() override;
};

#endif // !__CH19P709EXERC7__