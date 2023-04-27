/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 09:27:30
	author                                          : Andrei-KS
*/
#ifndef __CH18P665EXERC9__
#define __CH18P665EXERC9__

#include "RunCommandOfExample.h"

/*
* Consider the memory layout in §17.4. Write a program that tells the order
* in which static storage, the stack, and the free store are laid out in memory.
* In which direction does the stack grow: upward toward higher addresses
* or downward toward lower addresses? In an array on the free store, are
* elements with higher indices allocated at higher or lower addresses?
*
* @author Andrei-KS
*/
class CH18P665EXERC9RunExmple : public RunCommandOfExample
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

#endif // !__CH18P665EXERC9__