/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/10/2023 08:38:47
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC3__
#define __CH19P709EXERC3__

#include "RunCommandOfExample.h"

/*
* Write a template class Pair that can hold a pair of values of any type.
* Use this to implement a simple symbol table like the one we used in the
* calculator (§7.8).
*
* @author Andrei-KS
*/
class CH19P709EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC3__