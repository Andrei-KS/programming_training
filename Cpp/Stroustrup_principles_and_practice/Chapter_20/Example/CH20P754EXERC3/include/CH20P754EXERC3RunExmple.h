/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 14:47:44
	author                                          : Andrei-KS
*/
#ifndef __CH20P754EXERC3__
#define __CH20P754EXERC3__

#include "RunCommandOfExample.h"

/*
* Look at the palindrome examples (§18.7) redo the Jack-and-Jill example
* from §20.1.2 using that variety of techniques.
*
* @author Andrei-KS
*/
class CH20P754EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH20P754EXERC3__