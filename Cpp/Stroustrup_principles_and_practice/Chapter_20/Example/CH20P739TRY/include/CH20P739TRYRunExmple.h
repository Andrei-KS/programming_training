/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 09:42:17
	author                                          : Andrei-KS
*/
#ifndef __CH20P739TRY__
#define __CH20P739TRY__

#include "RunCommandOfExample.h"

/*
* Rewrite advance() so that it will “go backward” when you give it a negative
* argument.
*
* @author Andrei-KS
*/
class CH20P739TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH20P739TRY__