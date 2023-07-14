/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/12/2023 09:47:51
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC13__
#define __CH19P709EXERC13__

#include "RunCommandOfExample.h"

/*
* Write a Tracer class where its constructor prints a string and its destructor
* prints a string. Give the strings as constructor arguments. Use it to see
* where RAII management objects will do their job (i.e., experiment with
* Tracers as local objects, member objects, global objects, objects allocated
* by new, etc.). Then add a copy constructor and a copy assignment so that
* you can use Tracer objects to see when copying is done.
*
* @author Andrei-KS
*/
class CH19P709EXERC13RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC13__