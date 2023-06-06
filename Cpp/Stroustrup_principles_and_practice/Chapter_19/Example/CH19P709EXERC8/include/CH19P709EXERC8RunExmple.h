/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/22/2023 10:09:52
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC8__
#define __CH19P709EXERC8__

#include "RunCommandOfExample.h"

/*
* Implement an allocator (§19.3.7) using the basic allocation functions mal-
* loc() and free() (§B.11.4). Get vector as defined by the end of §19.4 to
* work for a few simple test cases. Hint: Look up “placement new” and
* “explicit call of destructor” in a complete C++ reference.
*
* @author Andrei-KS
*/
class CH19P709EXERC8RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC8__