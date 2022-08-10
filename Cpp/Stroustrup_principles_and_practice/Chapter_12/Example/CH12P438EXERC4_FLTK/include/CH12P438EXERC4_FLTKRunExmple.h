/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 16:03:35
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC4_FLTK__
#define __CH12P438EXERC4_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
*
* @author Andrei-KS
*/
class CH12P438EXERC4_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC4_FLTK__