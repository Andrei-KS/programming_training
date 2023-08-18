/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 08:13:23
	author                                          : Andrei-KS
*/
#ifndef __CH20P724TRY__
#define __CH20P724TRY__

#include "RunCommandOfExample.h"

/*
* We again left a serious error in that program. Find it, fix it, and suggest a
* general remedy for that kind of problem.
*
* @author Andrei-KS
*/
class CH20P724TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH20P724TRY__