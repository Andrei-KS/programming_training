/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/07/2022 17:43:39
	author                                          : Andrei-KS
*/
#ifndef __CH16P578EXERC2_FLTK__
#define __CH16P578EXERC2_FLTK__

#include "RunCommandOfExample.h"

/*
* Make a window (based on My_window) with a 4-by-4 checkerboard of
* square buttons. When pressed, a button performs a simple action, such as
* printing its coordinates in an output box, or turns a slightly different color
* (until another button is pressed).
*
* @author Andrei-KS
*/
class CH16P578EXERC2_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P578EXERC2_FLTK__