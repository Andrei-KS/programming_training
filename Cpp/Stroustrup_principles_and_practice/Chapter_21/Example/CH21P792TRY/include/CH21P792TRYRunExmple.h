/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 14:57:59
	author                                          : Andrei-KS
*/
#ifndef __CH21P792TRY__
#define __CH21P792TRY__

#include "RunCommandOfExample.h"

/*
* First get the program as written to work and test it with a small file of, say,
* a few hundred words. Then try the emphatically not recommended version that
* guesses about the size of input and see what happens when the input buffer b
* overflows. Note that the worst-case scenario is that the overflow led to noth-
* ing bad in your particular example, so that you would be tempted to ship it
* to users.
*
* @author Andrei-KS
*/
class CH21P792TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH21P792TRY__