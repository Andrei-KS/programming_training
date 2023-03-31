/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/31/2023 07:13:24
	author                                          : Andrei-KS
*/
#ifndef __CH17P591TRY__
#define __CH17P591TRY__

#include "RunCommandOfExample.h"

/*
* Execute the example above and see what you get. Then extend the example
* to determine the size of bool, double, and some other type.
*
* @author Andrei-KS
*/
class CH17P591TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH17P591TRY__