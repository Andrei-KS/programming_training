/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/06/2023 01:21:43
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC19__
#define __CH20P755EXERC19__

#include "RunCommandOfExample.h"

/*
* Define a range-checked iterator for list (a bidirectional iterator).
*
* @author Andrei-KS
*/
class CH20P755EXERC19RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC19__