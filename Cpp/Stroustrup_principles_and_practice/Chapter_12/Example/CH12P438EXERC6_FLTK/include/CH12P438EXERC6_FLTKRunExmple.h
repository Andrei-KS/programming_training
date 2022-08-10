/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 18:00:18
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC6_FLTK__
#define __CH12P438EXERC6_FLTK__

#include "RunCommandOfExample.h"

/*
* What happens when you draw a Shape that doesn’t fit inside its window?
* What happens when you draw a Window that doesn’t fit on your screen?
* Write two programs that illustrate these two phenomena.
*
* @author Andrei-KS
*/
class CH12P438EXERC6_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC6_FLTK__