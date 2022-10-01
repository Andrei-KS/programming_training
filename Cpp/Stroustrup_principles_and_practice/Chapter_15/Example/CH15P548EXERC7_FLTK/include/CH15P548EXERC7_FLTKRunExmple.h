/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 18:12:19
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC7_FLTK__
#define __CH15P548EXERC7_FLTK__

#include "RunCommandOfExample.h"

/*
* Elaborate the bar graph class to allow labeling of the graph itself and its
* individual bars. Allow the use of color.
*
* @author Andrei-KS
*/
class CH15P548EXERC7_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC7_FLTK__