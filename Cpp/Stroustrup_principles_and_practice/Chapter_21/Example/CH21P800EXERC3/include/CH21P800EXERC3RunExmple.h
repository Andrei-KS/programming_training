/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/14/2023 08:24:22
	author                                          : Andrei-KS
*/
#ifndef __CH21P800EXERC3__
#define __CH21P800EXERC3__

#include "RunCommandOfExample.h"

/*
* Implement count() yourself. Test it
*
* @author Andrei-KS
*/
class CH21P800EXERC3RunExmple : public RunCommandOfExample
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

#endif // !__CH21P800EXERC3__