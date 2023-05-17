/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/11/2023 08:07:13
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC4__
#define __CH19P709EXERC4__

#include "RunCommandOfExample.h"

/*
* Modify class Link from §17.9.3 to be a template with the type of value
* as the template argument. Then redo exercise 13 from Chapter 17 with
* Link<God>.
*
* @author Andrei-KS
*/
class CH19P709EXERC4RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC4__