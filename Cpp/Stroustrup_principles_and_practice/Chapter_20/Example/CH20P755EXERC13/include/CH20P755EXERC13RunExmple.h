/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/28/2023 02:38:18
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC13__
#define __CH20P755EXERC13__

#include "RunCommandOfExample.h"

/*
* We don’t really need a “real” one-past-the-end Link for a list. Modify your
* solution to the previous exercise to use 0 to represent a pointer to the
* (nonexistent) one-past-the-end Link (list<Elem>::end()) that way, the size
* of an empty list can be equal to the size of a single pointer.
*
* @author Andrei-KS
*/
class CH20P755EXERC13RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC13__