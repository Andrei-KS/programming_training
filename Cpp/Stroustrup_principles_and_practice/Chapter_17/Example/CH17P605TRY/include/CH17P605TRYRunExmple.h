/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/31/2023 09:09:01
	author                                          : Andrei-KS
*/
#ifndef __CH17P605TRY__
#define __CH17P605TRY__

#include "RunCommandOfExample.h"

/*
* Write a little program using base classes and members where you define the
* constructors and destructors to output a line of information when they are
* called. Then, create a few objects and see how their constructors and destruc-
* tors are called.
*
* @author Andrei-KS
*/
class CH17P605TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH17P605TRY__