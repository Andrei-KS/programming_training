/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/24/2022 15:15:49
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC19_FLTK__
#define __CH13P485EXERC19_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Star. One parameter should be the number of points. Draw
* a few stars with differing numbers of points, differing line colors,
* and differing fill colors.
*
* @author Andrei-KS
*/
class CH13P485EXERC19_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC19_FLTK__