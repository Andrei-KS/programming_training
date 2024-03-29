/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/19/2023 08:50:12
	author                                          : Andrei-KS
*/
#ifndef __CH18P663DRILL1_4__
#define __CH18P663DRILL1_4__

#include "RunCommandOfExample.h"

/*
* Array drill:
* 1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
* 2. Define a function f() taking an int array argument and an int argument
*    indicating the number of elements in the array.
* 3. In f():
*  a. Define a local int array la of ten ints.
*  b. Copy the values from ga into la.
*  c. Print out the elements of la.
*  d. Define a pointer p to int and initialize it with an array allocated on the
*     free store with the same number of elements as the argument array.
*  e. Copy the values from the argument array into the free-store array.
*  f. Print out the elements of the free-store array.
*  g. Deallocate the free-store array.
* 4. In main():
*  a. Call f() with ga as its argument.
*  b. Define an array aa with ten elements, and initialize it with the first ten
*     factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
*  c. Call f() with aa as its argument.
*
* @author Andrei-KS
*/
class CH18P663DRILL1_4RunExmple : public RunCommandOfExample
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

#endif // !__CH18P663DRILL1_4__