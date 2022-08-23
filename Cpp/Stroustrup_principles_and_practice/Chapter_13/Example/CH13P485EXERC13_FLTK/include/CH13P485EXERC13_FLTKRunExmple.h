/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 17:41:17
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC13_FLTK__
#define __CH13P485EXERC13_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw the color matrix from §13.10, but without lines around each color
*
* @author Andrei-KS
*/
class CH13P485EXERC13_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC13_FLTK__