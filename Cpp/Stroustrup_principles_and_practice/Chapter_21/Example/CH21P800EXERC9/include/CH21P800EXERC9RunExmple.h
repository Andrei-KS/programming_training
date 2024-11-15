/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/06/2024 14:00:22
	author                                          : Andrei-KS
*/
#ifndef __CH21P800EXERC9__
#define __CH21P800EXERC9__

#include "RunCommandOfExample.h"

/*
* Define an Order class with (customer) name, address, data, and
* vector<Purchase> members. Purchase is a class with a (product) name,
* unit_price, and count members. Define a mechanism for reading and
* writing Orders to and from a file. Define a mechanism for printing Or-
* ders. Create a file of at least ten Orders, read it into a vector<Order>, sort
* it by name (of customer), and write it back out to a file. Create another
* file of at least ten Orders of which about a third are the same as in the first
* file, read it into a list<Order>, sort it by address (of customer), and write
* it back out to a file. Merge the two files into a third using std::merge().
*
* @author Andrei-KS
*/
class CH21P800EXERC9RunExmple : public RunCommandOfExample
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

#endif // !__CH21P800EXERC9__