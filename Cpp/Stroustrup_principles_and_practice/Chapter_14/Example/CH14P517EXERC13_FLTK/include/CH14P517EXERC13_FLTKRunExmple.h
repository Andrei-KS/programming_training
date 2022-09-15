/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/15/2022 17:06:43
	author                                          : Andrei-KS
*/
#ifndef __CH14P517EXERC13_FLTK__
#define __CH14P517EXERC13_FLTK__

#include "RunCommandOfExample.h"

/*
* Modify Binary_tree to take a parameter (or parameters) to indicate what
* kind of line to use to connect the nodes (e.g., an arrow pointing down
* or a red arrow pointing up). Note how this exercise and the last use two
* alternative ways of making a class hierarchy more flexible and useful.
*
* @author Andrei-KS
*/
class CH14P517EXERC13_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P517EXERC13_FLTK__