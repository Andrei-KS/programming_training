/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/06/2024 11:13:09
	author                                          : Andrei-KS
*/
#ifndef __CH21P800EXERC8__
#define __CH21P800EXERC8__

#include "RunCommandOfExample.h"

/*
* Take the word-frequency example from §21.6.1 and modify it to output
* its lines in order of frequency (rather than in lexicographical order). An
* example line would be 3: C++ rather than C++: 3.
*
* @author Andrei-KS
*/
class CH21P800EXERC8RunExmple : public RunCommandOfExample
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

#endif // !__CH21P800EXERC8__