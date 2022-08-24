/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/24/2022 12:17:39
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC16_FLTK__
#define __CH13P485EXERC16_FLTK__

#include "RunCommandOfExample.h"

/*
* Do the previous exercise, but with hexagons.
*
* @author Andrei-KS
*/
class CH13P485EXERC16_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC16_FLTK__