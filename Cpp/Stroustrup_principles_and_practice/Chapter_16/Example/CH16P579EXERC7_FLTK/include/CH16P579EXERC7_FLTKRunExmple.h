/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/21/2023 08:03:58
	author                                          : Andrei-KS
*/
#ifndef __CH16P579EXERC7_FLTK__
#define __CH16P579EXERC7_FLTK__

#include "RunCommandOfExample.h"

/*
* Using the techniques developed in the previous exercises, make an image of
* an airplane “fly around” in a window. Have a “Start” and a “Stop” button.
*
* @author Andrei-KS
*/
class CH16P579EXERC7_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P579EXERC7_FLTK__