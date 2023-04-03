/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 21:50:06
	author                                          : Andrei-KS
*/
#ifndef __CH17P624EXERC3__
#define __CH17P624EXERC3__

#include "RunCommandOfExample.h"

/*
* Write a function, void to_lower(char* s), that replaces all uppercase char-
* acters in the C-style string s with their lowercase equivalents. For ex-
* ample, Hello, World! becomes hello, world!. Do not use any standard
* library functions. A C-style string is a zero-terminated array of characters,
* so if you find a char with the value 0 you are at the end.
*
* @author Andrei-KS
*/
class CH17P624EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH17P624EXERC3__