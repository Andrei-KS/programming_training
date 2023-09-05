/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/05/2023 17:09:38
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC18__
#define __CH20P755EXERC18__

#include "RunCommandOfExample.h"

/*
* Define a range-checked iterator for vector (a random-access iterator).
*
* @author Andrei-KS
*/
class CH20P755EXERC18RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC18__