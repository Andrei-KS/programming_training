/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2022 18:32:14
	author                                          : Andrei-KS
*/
#ifndef __CH13P484EXERC3_FLTK__
#define __CH13P484EXERC3_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Arrow, which draws a line with an arrowhead.
*
* @author Andrei-KS
*/
class CH13P484EXERC3_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P484EXERC3_FLTK__