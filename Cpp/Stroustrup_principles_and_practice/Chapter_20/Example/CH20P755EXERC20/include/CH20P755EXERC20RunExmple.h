/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/06/2023 09:17:46
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC20__
#define __CH20P755EXERC20__

#include "RunCommandOfExample.h"

/*
* Run a small timing experiment to compare the cost of using vector and list.
* You can find an explanation of how to time a program in §26.6.1. Generate
* N random int values in the range [0:N ). As each int is generated, insert
* it into a vector<int> (which grows by one element each time). Keep the
* vector sorted; that is, a value is inserted after every previous value that is
* less than or equal to the new value and before every previous value that is
* larger than the new value. Now do the same experiment using a list<int> to
* hold the ints. For which N is the list faster than the vector? Try to explain
* your result. This experiment was first suggested by John Bentley
*
* @author Andrei-KS
*/
class CH20P755EXERC20RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC20__