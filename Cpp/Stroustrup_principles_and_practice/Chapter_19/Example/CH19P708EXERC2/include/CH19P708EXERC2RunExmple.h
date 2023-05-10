/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/10/2023 07:44:57
	author                                          : Andrei-KS
*/
#ifndef __CH19P708EXERC2__
#define __CH19P708EXERC2__

#include "RunCommandOfExample.h"

/*
* Write a template function that takes a vector<T> vt and a vector<U> vu as
* arguments and returns the sum of all vt[i]*vu[i]s.
*
* @author Andrei-KS
*/
class CH19P708EXERC2RunExmple : public RunCommandOfExample
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

#endif // !__CH19P708EXERC2__