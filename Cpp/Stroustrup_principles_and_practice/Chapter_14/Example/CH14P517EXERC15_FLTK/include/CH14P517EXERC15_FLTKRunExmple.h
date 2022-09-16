/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/16/2022 15:39:03
	author                                          : Andrei-KS
*/
#ifndef __CH14P517EXERC15_FLTK__
#define __CH14P517EXERC15_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Iterator with a pure virtual function next() that returns
* a double* (see Chapter 17). Now derive Vector_iterator and List_iterator
* from Iterator so that next() for a Vector_iterator yields a pointer to
* the next element of a vector<double> and List_iterator does the same
* for a list<double>. You initialize a Vector_iterator with a vector<double>
* and the first call of next() yields a pointer to its first element, if any.
* If there is no next element, return 0. Test this by using a function void
* print(Iterator&) to print the elements of a vector<double> and a list<double>.
*
* @author Andrei-KS
*/
class CH14P517EXERC15_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P517EXERC15_FLTK__