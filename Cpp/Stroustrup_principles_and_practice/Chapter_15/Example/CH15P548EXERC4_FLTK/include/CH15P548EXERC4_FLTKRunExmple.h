/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 10:58:46
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC4_FLTK__
#define __CH15P548EXERC4_FLTK__

#include "RunCommandOfExample.h"

/*
* Graph a sine (sin()), a cosine (cos()), the sum of those (sin(x)+cos(x)), and
* the sum of the squares of those (sin(x)*sin(x)+cos(x)*cos(x)) on a single
* graph. Do provide axes and labels
*
* @author Andrei-KS
*/
class CH15P548EXERC4_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC4_FLTK__