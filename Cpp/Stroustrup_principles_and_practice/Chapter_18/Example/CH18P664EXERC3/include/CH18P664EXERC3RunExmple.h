/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/24/2023 08:54:31
	author                                          : Andrei-KS
*/
#ifndef __CH18P664EXERC3__
#define __CH18P664EXERC3__

#include "RunCommandOfExample.h"

/*
* Write a function, int strcmp(const char* s1, const char* s2), that compares
* C-style strings. Let it return a negative number if s1 is lexicographically
* before s2, zero if s1 equals s2, and a positive number if s1 is lexicograph-
* ically after s2. Do not use any standard library functions. Do not use
* subscripting use the dereference operator * instead.
*
* @author Andrei-KS
*/
class CH18P664EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH18P664EXERC3__