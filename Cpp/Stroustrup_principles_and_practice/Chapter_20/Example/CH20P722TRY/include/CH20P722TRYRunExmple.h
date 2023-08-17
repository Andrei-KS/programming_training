/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2023 08:26:01
	author                                          : Andrei-KS
*/
#ifndef __CH20P722TRY__
#define __CH20P722TRY__

#include "RunCommandOfExample.h"

/*
* Write a function void copy(int* f1, int* e1, int* f2) that copies the elements
* of an array of ints defined by [f1:e1) into another [f2:f2+(e1–f1)). Use only
* the iterator operations mentioned above (not subscripting).
*
* @author Andrei-KS
*/
class CH20P722TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH20P722TRY__