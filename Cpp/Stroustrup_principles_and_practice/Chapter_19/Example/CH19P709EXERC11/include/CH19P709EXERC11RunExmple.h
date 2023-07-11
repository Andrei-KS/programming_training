/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/11/2023 12:01:18
	author                                          : Andrei-KS
*/
#ifndef __CH19P709EXERC11__
#define __CH19P709EXERC11__

#include "RunCommandOfExample.h"

/*
* Design and implement a counted_ptr<T> that is a type that holds a
* pointer to an object of type T and a pointer to a “use count” (an int)
* shared by all counted pointers to the same object of type T. The use
* count should hold the number of counted pointers pointing to a given
* T. Let the counted_ptr’s constructor allocate a T object and a use count
* on the free store. Let counted_ptr’s constructor take an argument to be
* used as the initial value of the T elements. When the last counted_ptr
* for a T is destroyed, counted_ptr’s destructor should delete the T. Give
* the counted_ptr operations that allow us to use it as a pointer. This is
* an example of a “smart pointer” used to ensure that an object doesn’t
* get destroyed until after its last user has stopped using it. Write a set
* of test cases for counted_ptr using it as an argument in calls, container
* elements, etc.
*
* @author Andrei-KS
*/
class CH19P709EXERC11RunExmple : public RunCommandOfExample
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

#endif // !__CH19P709EXERC11__