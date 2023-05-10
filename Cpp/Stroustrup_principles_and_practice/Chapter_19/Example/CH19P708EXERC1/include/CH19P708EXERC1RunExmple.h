/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/10/2023 07:17:51
	author                                          : Andrei-KS
*/
#ifndef __CH19P708EXERC1__
#define __CH19P708EXERC1__

#include "RunCommandOfExample.h"

/*
* Write a template function f() that adds the elements of one vector<T> to
* the elements of another for example, f(v1,v2) should do v1[i]+=v2[i] for
* each element of v1.
*
* @author Andrei-KS
*/
class CH19P708EXERC1RunExmple : public RunCommandOfExample
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

#endif // !__CH19P708EXERC1__