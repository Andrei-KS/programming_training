/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/23/2022 14:38:06
	author                                          : Andrei-KS
*/
#ifndef __CH16P579EXERC4_FLTK__
#define __CH16P579EXERC4_FLTK__

#include "RunCommandOfExample.h"

/*
* Make a menu with items that make a circle, a square, an equilateral triangle,
* and a hexagon, respectively. Make an input box (or two) for giving a
* coordinate pair, and place the shape made by pressing a menu item at that
* coordinate. Sorry, no drag and drop.
*
* @author Andrei-KS
*/
class CH16P579EXERC4_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P579EXERC4_FLTK__