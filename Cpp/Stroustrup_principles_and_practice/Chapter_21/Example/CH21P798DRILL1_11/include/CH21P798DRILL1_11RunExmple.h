/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/11/2023 08:24:31
	author                                          : Andrei-KS
*/
#ifndef __CH21P798DRILL1_11__
#define __CH21P798DRILL1_11__

#include "RunCommandOfExample.h"

/*
* 1. Define a map<string,int> called msi.
* 2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21.
* 3. Output the (name,value) pairs to cout in some format of your choice.
* 4. Erase the (name,value) pairs from msi.
* 5. Write a function that reads value pairs from cin and places them in msi.
* 6. Read ten pairs from input and enter them into msi.
* 7. Write the elements of msi to cout.
* 8. Output the sum of the (integer) values in msi.
* 9. Define a map<int,string> called mis.
* 10. Enter the values from msi into mis that is, if msi has an element
* (" lecture",21), mis should have an element (21,"lecture").
* 11. Output the elements of mis to cout.
*
* @author Andrei-KS
*/
class CH21P798DRILL1_11RunExmple : public RunCommandOfExample
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

#endif // !__CH21P798DRILL1_11__