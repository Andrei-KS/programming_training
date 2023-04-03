/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 08:19:17
	author                                          : Andrei-KS
*/
#ifndef __CH17P622DRILL1_13__
#define __CH17P622DRILL1_13__

#include "RunCommandOfExample.h"

/*
* 1. Allocate an int, initialize it to 7, and assign its address to a variable p1.
* 2. Print out the value of p1 and of the int it points to.
* 3. Allocate an array of seven ints initialize it to 1, 2, 4, 8, etc. and assign its
* address to a variable p2.
* 4. Print out the value of p2 and of the array it points to.
* 5. Declare an int* called p3 and initialize it with p2.
* 6. Assign p1 to p2.
* 7. Assign p3 to p2.
* 8. Print out the values of p1 and p2 and of what they point to.
* 9. Deallocate all the memory you allocated from the free store
* 10. Allocate an array of ten ints initialize it to 1, 2, 4, 8, etc. and assign its
* address to a variable p1.
* 11. Allocate an array of ten ints, and assign its address to a variable p2.
* 12. Copy the values from the array pointed to by p1 into the array pointed to
* by p2.
* 13. Repeat 10–12 using a vector rather than an array.
*
* @author Andrei-KS
*/
class CH17P622DRILL1_13RunExmple : public RunCommandOfExample
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

#endif // !__CH17P622DRILL1_13__