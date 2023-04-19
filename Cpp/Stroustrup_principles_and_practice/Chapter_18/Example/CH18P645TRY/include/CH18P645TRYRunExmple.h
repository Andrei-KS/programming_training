/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/11/2023 08:46:51
	author                                          : Andrei-KS
*/
#ifndef __CH18P645TRY__
#define __CH18P645TRY__

#include "RunCommandOfExample.h"

/*
* We really mean it: do run this example and make sure you understand the
* result. If you do, you’ll understand most of what there is to know about
* construction and destruction of objects.
*
* @author Andrei-KS
*/
class CH18P645TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH18P645TRY__