/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 12/06/2023 06:08:21
	author                                          : Andrei-KS
*/
#ifndef __CH21P800EXERC5__
#define __CH21P800EXERC5__

#include "RunCommandOfExample.h"

/*
* What would we have to do if we couldn’t return end() to indicate “not
* found”? Redesign and re-implement find() and count() to take iterators to
* the first and last elements. Compare the results to the standard versions.
*
* @author Andrei-KS
*/
class CH21P800EXERC5RunExmple : public RunCommandOfExample
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

#endif // !__CH21P800EXERC5__