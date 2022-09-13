/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/13/2022 13:36:43
	author                                          : Andrei-KS
*/
#ifndef __CH14P516EXERC8_FLTK__
#define __CH14P516EXERC8_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Octagon to be a regular octagon. Write a test that exercises
* all of its functions (as defined by you or inherited from Shape).
*
* @author Andrei-KS
*/
class CH14P516EXERC8_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P516EXERC8_FLTK__