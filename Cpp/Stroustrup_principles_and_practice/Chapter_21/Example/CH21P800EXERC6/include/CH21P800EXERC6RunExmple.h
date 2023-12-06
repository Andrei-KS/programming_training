/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 12/06/2023 06:37:14
	author                                          : Andrei-KS
*/
#ifndef __CH21P800EXERC6__
#define __CH21P800EXERC6__

#include "RunCommandOfExample.h"

/*
* In the Fruit example in §21.6.5, we copy Fruits into the set. What if
* we didn’t want to copy the Fruits? We could have a set<Fruit*> instead.
* However, to do that, we’d have to define a comparison operation for that
* set. Implement the Fruit example using a set<Fruit*, Fruit_comparison>.
* Discuss the differences between the two implementations.
*
* @author Andrei-KS
*/
class CH21P800EXERC6RunExmple : public RunCommandOfExample
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

#endif // !__CH21P800EXERC6__