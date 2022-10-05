/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/05/2022 19:16:45
	author                                          : Andrei-KS
*/
#ifndef __CH16P577DRILL1_4_FLTK__
#define __CH16P577DRILL1_4_FLTK__

#include "RunCommandOfExample.h"

/*
* 1. Make a completely new project with linker settings for FLTK (as described in Appendix D).
* 2. Using the facilities of Graph_lib, type in the line-drawing program from
* §16.5 and get it to run.
* 3. Modify the program to use a pop-up menu as described in §16.7 and get
* it to run.
* 4. Modify the program to have a second menu for choosing line styles and
* get it to run.
*
* @author Andrei-KS
*/
class CH16P577DRILL1_4_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P577DRILL1_4_FLTK__