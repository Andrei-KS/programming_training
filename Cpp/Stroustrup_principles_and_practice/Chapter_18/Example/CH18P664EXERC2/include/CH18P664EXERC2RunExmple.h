/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/24/2023 08:11:55
	author                                          : Andrei-KS
*/
#ifndef __CH18P664EXERC2__
#define __CH18P664EXERC2__

#include "RunCommandOfExample.h"

/*
* Write a function, char* findx(const char* s, const char* x), that finds the
* first occurrence of the C-style string x in s. Do not use any standard li-
* brary functions. Do not use subscripting use the dereference operator *
* instead.
*
* @author Andrei-KS
*/
class CH18P664EXERC2RunExmple : public RunCommandOfExample
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

#endif // !__CH18P664EXERC2__