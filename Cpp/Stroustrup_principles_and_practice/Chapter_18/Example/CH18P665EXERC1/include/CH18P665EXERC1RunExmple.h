/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/21/2023 09:22:30
	author                                          : Andrei-KS
*/
#ifndef __CH18P665EXERC1__
#define __CH18P665EXERC1__

#include "RunCommandOfExample.h"

/*
* Write a function, char* strdup(const char*), that copies a C-style string
* into memory it allocates on the free store. Do not use any standard li-
* brary functions. Do not use subscripting use the dereference operator *
* instead.
*
* @author Andrei-KS
*/
class CH18P665EXERC1RunExmple : public RunCommandOfExample
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

#endif // !__CH18P665EXERC1__