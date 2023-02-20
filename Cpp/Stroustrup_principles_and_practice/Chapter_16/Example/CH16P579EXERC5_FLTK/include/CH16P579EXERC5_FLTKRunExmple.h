/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 02/20/2023 06:20:01
	author                                          : Andrei-KS
*/
#ifndef __CH16P579EXERC5_FLTK__
#define __CH16P579EXERC5_FLTK__

#include "RunCommandOfExample.h"

/*
* Write a program that draws a shape of your choice and moves it to a new
* point each time you click “Next.” The new point should be determined
* by a coordinate pair read from an input stream.
*
* @author Andrei-KS
*/
class CH16P579EXERC5_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P579EXERC5_FLTK__