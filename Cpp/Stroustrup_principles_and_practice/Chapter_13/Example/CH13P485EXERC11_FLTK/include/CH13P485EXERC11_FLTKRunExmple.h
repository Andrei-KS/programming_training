/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 16:32:50
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC11_FLTK__
#define __CH13P485EXERC11_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a
* 300-pixel-long y axis through the center of the ellipse. Mark the foci.
* Mark a point on the ellipse that is not on one of the axes. Draw the two
* lines from the foci to the point.
*
* @author Andrei-KS
*/
class CH13P485EXERC11_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC11_FLTK__