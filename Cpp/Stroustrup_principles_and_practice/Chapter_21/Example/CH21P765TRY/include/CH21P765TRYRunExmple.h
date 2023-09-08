/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 12:28:33
	author                                          : Andrei-KS
*/
#ifndef __CH21P765TRY__
#define __CH21P765TRY__

#include "RunCommandOfExample.h"

/*
* Why are we so disgusted with that use of v? Give at least three ways this
* could lead to obscure errors. List three applications in which you’d particu-
* larly hate to find such code.
*
* @author Andrei-KS
*/
class CH21P765TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH21P765TRY__