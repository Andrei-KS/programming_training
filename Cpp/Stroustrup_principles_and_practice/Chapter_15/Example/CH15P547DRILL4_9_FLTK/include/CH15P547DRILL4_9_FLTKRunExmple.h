/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/20/2022 17:41:38
	author                                          : Andrei-KS
*/
#ifndef __CH15P547DRILL4_9_FLTK__
#define __CH15P547DRILL4_9_FLTK__

#include "RunCommandOfExample.h"

/*
* Class definition drill:
* 4. Give Person a constructor initializing name and age.
* 5. Make the representation of Person private, and provide const member
* functions name() and age() to read the name and age.
* 6. Modify >> and << to work with the redefined Person.
* 7. Modify the constructor to check that age is [0:150) and that name doesn’t
* contain any of the characters ; : " ' [ ] * & ^ % $ # @ !. Use error() in case
* of error. Test.
* 8. Read a sequence of Persons from input (cin) into a vector<Person>;
* write them out again to the screen (cout). Test with correct and erroneous input.
* 9. Change the representation of Person to have first_name and second_name
* instead of name. Make it an error not to supply both a first and a second
* name. Be sure to fix >> and << also. Test.
*
* @author Andrei-KS
*/
class CH15P547DRILL4_9_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P547DRILL4_9_FLTK__