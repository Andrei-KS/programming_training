/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 08:46:06
	author                                          : Andrei-KS
*/
#ifndef __CH20P728TRY__
#define __CH20P728TRY__

#include "RunCommandOfExample.h"

/*
* The standard library vector doesn’t provide push_front(). Why not? Imple-
* ment push_front() for vector and compare it to push_back().
*
* @author Andrei-KS
*/
class CH20P728TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH20P728TRY__