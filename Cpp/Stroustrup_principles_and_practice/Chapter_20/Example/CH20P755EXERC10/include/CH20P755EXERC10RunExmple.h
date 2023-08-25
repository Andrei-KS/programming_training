/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2023 16:29:49
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC10__
#define __CH20P755EXERC10__

#include "RunCommandOfExample.h"

/*
* Define a version of the word-counting program where the user can spec-
* ify the set of whitespace characters.
*
* @author Andrei-KS
*/
class CH20P755EXERC10RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC10__