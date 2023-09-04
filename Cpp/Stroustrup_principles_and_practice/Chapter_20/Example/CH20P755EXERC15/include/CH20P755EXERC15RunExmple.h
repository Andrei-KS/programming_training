/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/04/2023 09:36:43
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC15__
#define __CH20P755EXERC15__

#include "RunCommandOfExample.h"

/*
* Define a pvector to be like a vector of pointers except that it contains
* pointers to objects and its destructor deletes each object.
*
* @author Andrei-KS
*/
class CH20P755EXERC15RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC15__