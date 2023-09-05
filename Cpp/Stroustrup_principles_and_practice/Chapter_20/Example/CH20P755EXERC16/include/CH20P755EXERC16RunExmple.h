/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/05/2023 11:47:03
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC16__
#define __CH20P755EXERC16__

#include "RunCommandOfExample.h"

/*
* Define an ovector that is like pvector except that the [ ] and * operators
* return a reference to the object pointed to by an element rather than the
* pointer.
*
* @author Andrei-KS
*/
class CH20P755EXERC16RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC16__