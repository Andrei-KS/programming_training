/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/07/2023 22:55:45
	author                                          : Andrei-KS
*/
#ifndef __CH21P761TRY__
#define __CH21P761TRY__

#include "RunCommandOfExample.h"

/*
* Are you sure those two definitions are logically equivalent? How would
* you be sure? Try constructing an argument for their being equivalent. That
* done, try both on some data. A famous computer scientist (Don Knuth)
* once said, “I have only proven the algorithm correct, not tested it.” Even
* mathematical proofs can contain errors. To be confident, you need to both
* reason and test.
*
* @author Andrei-KS
*/
class CH21P761TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH21P761TRY__