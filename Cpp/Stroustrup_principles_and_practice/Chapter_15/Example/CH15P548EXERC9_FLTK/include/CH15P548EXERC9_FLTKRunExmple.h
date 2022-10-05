/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/05/2022 10:26:24
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC9_FLTK__
#define __CH15P548EXERC9_FLTK__

#include "RunCommandOfExample.h"

/*
* Find another data set of heights (an inch is 2.54cm) and graph them with
* your program from the previous exercise. For example, search the web
* for “height distribution” or “height of people in the United States” and
* ignore a lot of rubbish or ask your friends for their heights. Ideally, you
* don’t have to change anything for the new data set. Calculating the scal-
* ing from the data is a key idea. Reading in labels from input also helps
* minimize changes when you want to reuse code.
*
* @author Andrei-KS
*/
class CH15P548EXERC9_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC9_FLTK__