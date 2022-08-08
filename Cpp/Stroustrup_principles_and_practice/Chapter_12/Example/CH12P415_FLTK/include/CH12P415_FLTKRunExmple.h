/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/08/2022 15:39:08
	author                                          : Andrei-KS
*/
#ifndef __CH12P415_FLTK__
#define __CH12P415_FLTK__

#include "RunCommandOfExample.h"

/*
* 
* @author Andrei-KS
*/
class CH12P415_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P415_FLTK__