/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/22/2022 17:40:42
	author                                          : Andrei-KS
*/
#ifndef __CH13P484EXERC8_FLTK__
#define __CH13P484EXERC8_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Regular_hexagon (a regular hexagon is a six-sided polygon
* with all sides of equal length). Use the center and the distance from the
* center to a corner point as constructor arguments.
*
* @author Andrei-KS
*/
class CH13P484EXERC8_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P484EXERC8_FLTK__