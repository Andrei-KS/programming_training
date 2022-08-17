/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2022 17:24:53
	author                                          : Andrei-KS
*/
#ifndef __CH13P483DRILL1_5_FLTK__
#define __CH13P483DRILL1_5_FLTK__

#include "RunCommandOfExample.h"

/*
* 1. Make an 800-by-1000 Simple_window.
* 2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window
* (so that each square is 100 by 100).
* 3. Make the eight squares on the diagonal starting from the top
* left corner red (use Rectangle).
* 4. Find a 200-by-200-pixel image (JPEG or GIF) and place three
* copies of iton the grid (each image covering four squares). If
* you can’t find an image that is exactly 200 by 200, use
* set_mask() to pick a 200-by-200 section of a larger image.
* Don’t obscure the red squares.
* 5. Add a 100-by-100 image. Have it move around from square
* to square when you click the “Next” button. Just put wait_for_button()
* in a loop with some code that picks a new square for your image.
*
* @author Andrei-KS
*/
class CH13P483DRILL1_5_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P483DRILL1_5_FLTK__