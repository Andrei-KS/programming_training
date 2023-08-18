/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 14:01:34
	author                                          : Andrei-KS
*/
#ifndef __CH20P754EXERC2__
#define __CH20P754EXERC2__

#include "RunCommandOfExample.h"

/*
* Get the Jack-and-Jill example from §20.1.2 to work. Use input from a
* couple of small files to test it.
*
* @author Andrei-KS
*/
class CH20P754EXERC2RunExmple : public RunCommandOfExample
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

#endif // !__CH20P754EXERC2__