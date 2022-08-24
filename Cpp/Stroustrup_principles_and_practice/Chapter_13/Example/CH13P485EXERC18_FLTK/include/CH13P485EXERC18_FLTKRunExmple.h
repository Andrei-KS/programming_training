/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/24/2022 13:12:40
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC18_FLTK__
#define __CH13P485EXERC18_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Poly that represents a polygon but checks that its points
* really do make a polygon in its constructor. Hint: You’ll have to supply
* the points to the constructor.
*
* @author Andrei-KS
*/
class CH13P485EXERC18_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC18_FLTK__