/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 14:59:19
	author                                          : Andrei-KS
*/
#ifndef __CH20P754EXERC5__
#define __CH20P754EXERC5__

#include "RunCommandOfExample.h"

/*
* Define an input and an output operator (>> and <<) for vector.
*
* @author Andrei-KS
*/
class CH20P754EXERC5RunExmple : public RunCommandOfExample
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

#endif // !__CH20P754EXERC5__