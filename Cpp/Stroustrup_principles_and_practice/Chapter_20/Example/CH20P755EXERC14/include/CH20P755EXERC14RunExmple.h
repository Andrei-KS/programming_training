/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/28/2023 09:31:42
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC14__
#define __CH20P755EXERC14__

#include "RunCommandOfExample.h"

/*
* efine a singly-linked list, slist, in the style of std::list. Which operations
* from list could you reasonably eliminate from slist because it doesn’t have
* back pointers?
*
* @author Andrei-KS
*/
class CH20P755EXERC14RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC14__