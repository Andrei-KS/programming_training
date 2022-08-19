/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/19/2022 14:36:06
	author                                          : Andrei-KS
*/
#ifndef __CH13P484EXERC5_FLTK__
#define __CH13P484EXERC5_FLTK__

#include "RunCommandOfExample.h"

/*
* Define the functions from exercise 4 for a Circle and an Ellipse. Place the
* connection points on or outside the shape but not outside the bounding
* rectangle.
*
* @author Andrei-KS
*/
class CH13P484EXERC5_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P484EXERC5_FLTK__