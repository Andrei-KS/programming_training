/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/11/2023 16:11:03
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC12__
#define __CH19P709EXERC12__

#include "RunCommandOfExample.h"

/*
* Define a File_handle class with a constructor that takes a string argu-
* ment (the file name), opens the file in the constructor, and closes it in the
* destructor.
*
* @author Andrei-KS
*/
class CH19P709EXERC12RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC12__