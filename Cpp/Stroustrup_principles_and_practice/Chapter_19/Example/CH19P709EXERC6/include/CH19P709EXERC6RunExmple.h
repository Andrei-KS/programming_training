/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/18/2023 09:40:11
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC6__
#define __CH19P709EXERC6__

#include "RunCommandOfExample.h"

/*
* Repeat the previous exercise, but with a class Number<T> where T can be
* any numeric type. Try adding % to Number and see what happens when
* you try to use % for Number<double> and Number<int>.
*
* @author Andrei-KS
*/
class CH19P709EXERC6RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC6__