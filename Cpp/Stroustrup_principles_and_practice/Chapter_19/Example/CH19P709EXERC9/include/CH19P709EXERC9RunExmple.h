/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 06/22/2023 08:36:26
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC9__
#define __CH19P709EXERC9__

#include "RunCommandOfExample.h"

/*
* Re-implement vector::operator=() (§19.2.5) using an allocator (§19.3.7)
* for memory management.
*
* @author Andrei-KS
*/
class CH19P709EXERC9RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC9__