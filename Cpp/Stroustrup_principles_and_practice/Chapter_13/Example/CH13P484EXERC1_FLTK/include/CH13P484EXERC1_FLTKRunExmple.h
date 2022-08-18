/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2022 19:37:32
	author                                          : Andrei-KS
*/
#ifndef __CH13P484EXERC1_FLTK__
#define __CH13P484EXERC1_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
*
* @author Andrei-KS
*/
class CH13P484EXERC1_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P484EXERC1_FLTK__