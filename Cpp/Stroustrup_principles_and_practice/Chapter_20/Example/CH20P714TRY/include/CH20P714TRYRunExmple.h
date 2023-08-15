/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/14/2023 09:07:38
	author                                          : Andrei-KS
*/
#ifndef __CH20P714TRY__
#define __CH20P714TRY__

#include "RunCommandOfExample.h"

/*
* If you were able to change Jill’s code, how would you redesign its interface
* to get rid of the ugliness?
*
* @author Andrei-KS
*/
class CH20P714TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH20P714TRY__