/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/05/2023 08:40:45
	author                                          : Andrei-KS
*/
#ifndef __CH17P624EXERC5__
#define __CH17P624EXERC5__

#include "RunCommandOfExample.h"

/*
* Write a function, char* findx(const char* s, const char* x), that finds the
* first occurrence of the C-style string x in s.
*
* @author Andrei-KS
*/
class CH17P624EXERC5RunExmple : public RunCommandOfExample
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

#endif // !__CH17P624EXERC5__