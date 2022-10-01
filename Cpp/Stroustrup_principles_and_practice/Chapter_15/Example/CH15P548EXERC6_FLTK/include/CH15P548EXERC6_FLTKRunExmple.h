/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 12:42:38
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC6_FLTK__
#define __CH15P548EXERC6_FLTK__

#include "RunCommandOfExample.h"

/*
* Design and implement a bar graph class. Its basic data is a vector<double>
* holding N values, and each value should be represented by a “bar” that is
* a rectangle where the height represents the value.
*
* @author Andrei-KS
*/
class CH15P548EXERC6_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC6_FLTK__