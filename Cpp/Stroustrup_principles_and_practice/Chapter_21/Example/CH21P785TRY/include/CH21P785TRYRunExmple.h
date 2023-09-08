/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 13:09:46
	author                                          : Andrei-KS
*/
#ifndef __CH21P785TRY__
#define __CH21P785TRY__

#include "RunCommandOfExample.h"

/*
* Get this little example to work. Then add a few companies of your own
* choice, with weights of your choice.
*
* @author Andrei-KS
*/
class CH21P785TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH21P785TRY__