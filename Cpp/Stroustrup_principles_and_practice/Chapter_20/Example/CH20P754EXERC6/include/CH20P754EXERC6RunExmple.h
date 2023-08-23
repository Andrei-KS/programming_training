/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/19/2023 07:56:56
	author                                          : Andrei-KS
*/
#ifndef __CH20P754EXERC6__
#define __CH20P754EXERC6__

#include "RunCommandOfExample.h"

/*
* Write a find-and-replace operation for Documents based on §20.6.2.
*
* @author Andrei-KS
*/
class CH20P754EXERC6RunExmple : public RunCommandOfExample
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

#endif // !__CH20P754EXERC6__