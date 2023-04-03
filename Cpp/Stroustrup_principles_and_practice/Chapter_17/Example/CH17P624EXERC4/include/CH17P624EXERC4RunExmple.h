/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 23:18:28
	author                                          : Andrei-KS
*/
#ifndef __CH17P624EXERC4__
#define __CH17P624EXERC4__

#include "RunCommandOfExample.h"

/*
* Write a function, char* strdup(const char*), that copies a C-style string
* into memory it allocates on the free store. Do not use any standard library
* functions.
*
* @author Andrei-KS
*/
class CH17P624EXERC4RunExmple : public RunCommandOfExample
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

#endif // !__CH17P624EXERC4__