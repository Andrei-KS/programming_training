/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/15/2023 13:39:22
	author                                          : Andrei-KS
*/
#ifndef __CH21P798DRILL1_8__
#define __CH21P798DRILL1_8__

#include "RunCommandOfExample.h"

/*
* 1. Define a struct Item { string name; int iid; double value; / *. . . * / };, make
*    a vector<Item>, vi, and fill it with ten items from a file.
* 2. Sort vi by name.
* 3. Sort vi by iid.
* 4. Sort vi by value; print it in order of decreasing value (i.e., largest value
*    first).
* 5. Insert Item{"horse shoe",99,12.34} and Item{"Canon S400", 9988,499.95}.
* 6. Remove (erase) two Items identified by name from vi.
* 7. Remove (erase) two Items identified by iid from vi.
* 8. Repeat the exercise with a list<Item> rather than a vector<Item>.
*
* @author Andrei-KS
*/
class CH21P798DRILL1_8RunExmple : public RunCommandOfExample
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

#endif // !__CH21P798DRILL1_8__