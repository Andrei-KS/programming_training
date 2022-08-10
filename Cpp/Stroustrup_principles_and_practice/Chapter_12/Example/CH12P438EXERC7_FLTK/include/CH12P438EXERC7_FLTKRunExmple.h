/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 18:25:53
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC7_FLTK__
#define __CH12P438EXERC7_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a two-dimensional house seen from the front, the way a child
* would: with a door, two windows, and a roof with a chimney. Feel free to
* add details maybe have “smoke” come out of the chimney.
*
* @author Andrei-KS
*/
class CH12P438EXERC7_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC7_FLTK__