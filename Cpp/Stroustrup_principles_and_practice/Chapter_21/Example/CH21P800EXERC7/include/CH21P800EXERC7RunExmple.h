/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/05/2024 08:31:09
	author                                          : Andrei-KS
*/
#ifndef __CH21P800EXERC7__
#define __CH21P800EXERC7__

#include "RunCommandOfExample.h"

/*
* Write a binary search function for a vector<int> (without using the stan-
* dard one). You can choose any interface you like. Test it. How confident
* are you that your binary search function is correct? Now write a binary
* search function for a list<string>. Test it. How much do the two binary
* search functions resemble each other? How much do you think they
* would have resembled each other if you had not known about the STL?
*
* @author Andrei-KS
*/
class CH21P800EXERC7RunExmple : public RunCommandOfExample
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

#endif // !__CH21P800EXERC7__