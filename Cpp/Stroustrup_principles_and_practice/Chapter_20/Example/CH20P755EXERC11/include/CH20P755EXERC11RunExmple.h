/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2023 17:25:27
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC11__
#define __CH20P755EXERC11__

#include "RunCommandOfExample.h"

/*
* Given a list<int> as a (by-reference) parameter, make a vector<double>
* and copy the elements of the list into it. Verify that the copy was complete
* and correct. Then print the elements sorted in order of increasing value.
*
* @author Andrei-KS
*/
class CH20P755EXERC11RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC11__