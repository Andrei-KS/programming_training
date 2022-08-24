/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/24/2022 12:46:41
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC17_FLTK__
#define __CH13P485EXERC17_FLTK__

#include "RunCommandOfExample.h"

/*
* Do the previous exercise, but using hexagons of a few different colors.
*
* @author Andrei-KS
*/
class CH13P485EXERC17_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC17_FLTK__