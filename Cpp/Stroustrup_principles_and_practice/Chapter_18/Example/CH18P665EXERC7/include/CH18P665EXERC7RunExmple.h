/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 08:06:33
	author                                          : Andrei-KS
*/
#ifndef __CH18P665EXERC7__
#define __CH18P665EXERC7__

#include "RunCommandOfExample.h"

/*
* Write versions of the cat_dot()s from the previous exercises to take
* C-style strings as arguments and return a free-store-allocated C-style string
* as the result. Do not use standard library functions or types in the im-
* plementation. Test these functions with several strings. Be sure to free
* (using delete) all the memory you allocated from free store (using new).
* Compare the effort involved in this exercise with the effort involved for
* exercises 5 and 6.
*
* @author Andrei-KS
*/
class CH18P665EXERC7RunExmple : public RunCommandOfExample
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

#endif // !__CH18P665EXERC7__