/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/20/2023 09:19:25
	author                                          : Andrei-KS
*/
#ifndef __CH18P663DRILL1_4_vector__
#define __CH18P663DRILL1_4_vector__

#include "RunCommandOfExample.h"

/*
* Standard library vector drill:
* 1. Define a global vector<int> gv initialize it with ten ints, 1, 2, 4, 8, 16, etc.
* 2. Define a function f() taking a vector<int> argument.
* 3. In f():
*  a. Define a local vector<int> lv with the same number of elements as the
*     argument vector.
*  b. Copy the values from gv into lv.
*  c. Print out the elements of lv.
*  d. Define a local vector<int> lv2 initialize it to be a copy of the argument
*     vector.
*  e. Print out the elements of lv2.
* 4. In main():
*  a. Call f() with gv as its argument.
*  b. Define a vector<int> vv, and initialize it with the first ten factorial val-
*     ues (1, 2*1, 3*2*1, 4*3*2*1, etc.).
*  c. Call f() with vv as its argument.
*
* @author Andrei-KS
*/
class CH18P663DRILL1_4_vectorRunExmple : public RunCommandOfExample
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

#endif // !__CH18P663DRILL1_4_vector__