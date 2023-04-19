/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/12/2023 07:38:26
	author                                          : Andrei-KS
*/
#ifndef __CH18P646TRY__
#define __CH18P646TRY__

#include "RunCommandOfExample.h"

/*
* Make a version of this vector that is complete enough to compile and see
* what error message your compiler produces for v[3]=x.
*
* @author Andrei-KS
*/
class CH18P646TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH18P646TRY__