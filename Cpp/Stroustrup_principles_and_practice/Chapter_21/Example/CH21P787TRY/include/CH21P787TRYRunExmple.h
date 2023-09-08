/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 13:43:51
	author                                          : Andrei-KS
*/
#ifndef __CH21P787TRY__
#define __CH21P787TRY__

#include "RunCommandOfExample.h"

/*
* Write a small program using #include<unordered_map>. If that doesn’t
* work, unordered_map wasn’t shipped with your C++ implementation. If
* your C++ implementation doesn’t provide unordered_map, you have to
* download one of the available implementations (e.g., see www.boost.org).
*
* @author Andrei-KS
*/
class CH21P787TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH21P787TRY__