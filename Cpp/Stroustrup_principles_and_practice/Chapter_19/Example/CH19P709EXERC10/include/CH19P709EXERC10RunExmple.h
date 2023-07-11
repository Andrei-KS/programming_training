/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 06/22/2023 08:59:22
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC10__
#define __CH19P709EXERC10__

#include "RunCommandOfExample.h"

/*
* Implement a simple unique_ptr supporting only a constructor, destructor,
* –>, *, and release(). In particular, don’t try to implement an assignment
* or a copy constructor.
*
* @author Andrei-KS
*/
class CH19P709EXERC10RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC10__