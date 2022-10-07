/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/06/2022 15:11:28
	author                                          : Andrei-KS
*/
#ifndef __CH16P578EXERC1_FLTK__
#define __CH16P578EXERC1_FLTK__

#include "RunCommandOfExample.h"

/*
* Make a My_window that’s a bit like Simple_window except that it has
* two buttons, next and quit.
*
* @author Andrei-KS
*/
class CH16P578EXERC1_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P578EXERC1_FLTK__