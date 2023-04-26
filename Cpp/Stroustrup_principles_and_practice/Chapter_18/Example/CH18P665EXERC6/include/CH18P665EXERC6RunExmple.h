/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 08:00:47
	author                                          : Andrei-KS
*/
#ifndef __CH18P665EXERC6__
#define __CH18P665EXERC6__

#include "RunCommandOfExample.h"

/*
* Modify cat_dot() from the previous exercise to take a string to be used as
* the separator (rather than dot) as its third argument.
*
* @author Andrei-KS
*/
class CH18P665EXERC6RunExmple : public RunCommandOfExample
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

#endif // !__CH18P665EXERC6__