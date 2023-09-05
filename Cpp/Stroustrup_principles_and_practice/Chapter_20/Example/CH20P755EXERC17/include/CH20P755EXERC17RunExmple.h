/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/05/2023 17:00:18
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC17__
#define __CH20P755EXERC17__

#include "RunCommandOfExample.h"

/*
* Define an ownership_vector that hold pointers to objects like pvector but
* provides a mechanism for the user to decide which objects are owned by
* the vector (i.e., which objects are deleted by the destructor). Hint: This
* exercise is simple if you were awake for Chapter 13.
*
* @author Andrei-KS
*/
class CH20P755EXERC17RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC17__