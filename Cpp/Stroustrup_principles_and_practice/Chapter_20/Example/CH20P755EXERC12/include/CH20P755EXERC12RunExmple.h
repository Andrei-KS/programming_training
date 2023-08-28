/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2023 17:40:46
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC12__
#define __CH20P755EXERC12__

#include "RunCommandOfExample.h"

/*
* Complete the definition of list from §20.4.1–2 and get the high() example
* to run. Allocate a Link to represent one past the end.
*
* @author Andrei-KS
*/
class CH20P755EXERC12RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC12__