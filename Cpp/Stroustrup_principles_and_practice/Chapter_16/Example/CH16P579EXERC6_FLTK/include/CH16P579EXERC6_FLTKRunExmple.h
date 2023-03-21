/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/09/2023 08:26:49
	author                                          : Andrei-KS
*/
#ifndef __CH16P579EXERC6_FLTK__
#define __CH16P579EXERC6_FLTK__

#include "RunCommandOfExample.h"

/*
* Make an “analog clock,” that is, a clock with hands that move. You get the
* time of day from the operating system through a library call. A major part
* of this exercise is to find the functions that give you the time of day and
* a way of waiting for a short period of time (e.g., a second for a clock tick)
* and to learn to use them based on the documentation you found. Hint:
* clock(), sleep().
*
* @author Andrei-KS
*/
class CH16P579EXERC6_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P579EXERC6_FLTK__