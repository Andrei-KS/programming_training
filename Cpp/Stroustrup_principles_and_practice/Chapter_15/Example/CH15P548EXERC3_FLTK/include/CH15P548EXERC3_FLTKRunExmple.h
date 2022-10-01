/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/30/2022 19:16:16
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC3_FLTK__
#define __CH15P548EXERC3_FLTK__

#include "RunCommandOfExample.h"

/*
* Modify Fct from the previous exercise to take an extra argument to con-
* trol precision or whatever. Make the type of that argument a template
* parameter for extra flexibility.
*
* @author Andrei-KS
*/
class CH15P548EXERC3_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC3_FLTK__