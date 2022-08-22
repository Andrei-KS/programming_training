/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/19/2022 16:19:47
	author                                          : Andrei-KS
*/
#ifndef __CH13P484EXERC6_FLTK__
#define __CH13P484EXERC6_FLTK__

#include "RunCommandOfExample.h"

/*
* Write a program that draws a class diagram like the one in §12.6. It will
* simplify matters if you start by defining a Box class that is a rectangle with
* a text label.
*
* @author Andrei-KS
*/
class CH13P484EXERC6_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P484EXERC6_FLTK__