/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 07:44:47
	author                                          : Andrei-KS
*/
#ifndef __CH17P622DRILL1_10__
#define __CH17P622DRILL1_10__

#include "RunCommandOfExample.h"

/*
* 1. Allocate an array of ten ints on the free store using new.
* 2. Print the values of the ten ints to cout.
* 3. Deallocate the array (using delete[] ).
* 4. Write a function print_array10(ostream& os, int* a) that prints out the
* values of a (assumed to have ten elements) to os.
* 5. Allocate an array of ten ints on the free store initialize it with the values
* 100, 101, 102, etc. and print out its values.
* 6. Allocate an array of 11 ints on the free store initialize it with the values
* 100, 101, 102, etc. and print out its values.
* 7. Write a function print_array(ostream& os, int* a, int n) that prints out the
* values of a (assumed to have n elements) to os.
* 8. Allocate an array of 20 ints on the free store initialize it with the values
* 100, 101, 102, etc. and print out its values.
* 9. Did you remember to delete the arrays? (If not, do it.)
* 10. Do 5, 6, and 8 using a vector instead of an array and a print_vector()
* instead of print_array().
*
* @author Andrei-KS
*/
class CH17P622DRILL1_10RunExmple : public RunCommandOfExample
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

#endif // !__CH17P622DRILL1_10__