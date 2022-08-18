/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2022 14:31:40
	author                                          : Andrei-KS
*/
#ifndef __CH13P484EXERC2_FLTK__
#define __CH13P484EXERC2_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a box with rounded corners. Define a class Box, consisting of four
* lines and four arcs
*
* @author Andrei-KS
*/
class CH13P484EXERC2_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P484EXERC2_FLTK__