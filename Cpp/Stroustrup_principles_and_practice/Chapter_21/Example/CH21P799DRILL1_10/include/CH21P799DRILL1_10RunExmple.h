/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/13/2023 09:29:22
	author                                          : Andrei-KS
*/
#ifndef __CH21P799DRILL1_10__
#define __CH21P799DRILL1_10__

#include "RunCommandOfExample.h"

/*
* 1. Read some floating-point values (at least 16 values) from a file into a
*    vector<double> called vd.
* 2. Output vd to cout.
* 3. Make a vector vi of type vector<int> with the same number of elements
*    as vd copy the elements from vd into vi.
* 4. Output the pairs of (vd[i],vi[i]) to cout, one pair per line.
* 5. Output the sum of the elements of vd.
* 6. Output the difference between the sum of the elements of vd and the sum
*    of the elements of vi.
* 7. There is a standard library algorithm called reverse that takes a sequence
*    (pair of iterators) as arguments reverse vd, and output vd to cout.
* 8. Compute the mean value of the elements in vd output it.
* 9. Make a new vector<double> called vd2 and copy all elements of vd with
*    values lower than (less than) the mean into vd2.
* 10. Sort vd output it again.
*
* @author Andrei-KS
*/
class CH21P799DRILL1_10RunExmple : public RunCommandOfExample
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

#endif // !__CH21P799DRILL1_10__