/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2023 08:02:56
	author                                          : Andrei-KS
*/
#ifndef __CH20P715TRY__
#define __CH20P715TRY__

#include "RunCommandOfExample.h"

/*
* We left two potentially serious errors in this little program. One can cause a
* crash, and the other will give wrong answers if high() is used in many other
* programs where it might have been useful. The general techniques that we
* describe below will make them obvious and show how to systematically
* avoid them. For now, just find them and suggest remedies.
*
* @author Andrei-KS
*/
class CH20P715TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH20P715TRY__