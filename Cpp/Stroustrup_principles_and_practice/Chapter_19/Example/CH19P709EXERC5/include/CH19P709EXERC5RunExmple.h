/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/17/2023 08:22:47
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC5__
#define __CH19P709EXERC5__

#include "RunCommandOfExample.h"

/*
* Define a class Int having a single member of class int. Define construc-
* tors, assignment, and operators +, –, *, / for it. Test it, and improve its
* design as needed (e.g., define operators << and >> for convenient I/O).
*
* @author Andrei-KS
*/
class CH19P709EXERC5RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC5__