/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/20/2022 15:52:20
	author                                          : Andrei-KS
*/
#ifndef __CH15P547DRILL1_3_FLTK__
#define __CH15P547DRILL1_3_FLTK__

#include "RunCommandOfExample.h"

/*
* Class definition drill:
* 1. Define a struct Person containing a string name and an int age.
* 2. Define a variable of type Person, initialize it with “Goofy” and 63, and
* write it to the screen (cout).
* 3. Define an input (>>) and an output (<<) operator for Person read in a
* Person from the keyboard (cin) and write it out to the screen (cout).
*
* @author Andrei-KS
*/
class CH15P547DRILL1_3_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P547DRILL1_3_FLTK__