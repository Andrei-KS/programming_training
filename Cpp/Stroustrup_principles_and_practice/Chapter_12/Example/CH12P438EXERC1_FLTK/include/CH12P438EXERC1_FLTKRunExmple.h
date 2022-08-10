/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 13:14:06
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC1_FLTK__
#define __CH12P438EXERC1_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the
* Polygon red and the lines of the Rectangle blue.
*
* @author Andrei-KS
*/
class CH12P438EXERC1_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC1_FLTK__