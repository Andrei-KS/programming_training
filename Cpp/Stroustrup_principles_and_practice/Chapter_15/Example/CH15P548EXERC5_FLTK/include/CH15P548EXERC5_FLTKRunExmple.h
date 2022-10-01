/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 11:27:56
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC5_FLTK__
#define __CH15P548EXERC5_FLTK__

#include "RunCommandOfExample.h"

/*
* “Animate” (as in §15.5) the series 1—1/3+1/5—1/7+1/9—1/11+ ... . It is
* known as Leibniz’s series and converges to pi/4.
*
* @author Andrei-KS
*/
class CH15P548EXERC5_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC5_FLTK__