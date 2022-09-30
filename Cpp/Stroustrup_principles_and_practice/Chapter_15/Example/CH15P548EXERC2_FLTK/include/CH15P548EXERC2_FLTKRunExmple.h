/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/30/2022 18:32:53
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC2_FLTK__
#define __CH15P548EXERC2_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Fct that is just like Function except that it stores its con-
* structor arguments. Provide Fct with “reset” operations, so that you can
* use it repeatedly for different ranges, different functions, etc.
*
* @author Andrei-KS
*/
class CH15P548EXERC2_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC2_FLTK__