/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/04/2023 07:30:01
	author                                          : Andrei-KS
*/
#ifndef __CH19P707DRILL1_14__
#define __CH19P707DRILL1_14__

#include "RunCommandOfExample.h"

/*
* 1. Define template<typename T> struct S { T val }.
* 2. Add a constructor, so that you can initialize with a T.
* 3. Define variables of types S<int>, S<char>, S<double>, S<string>, and
*    S<vector<int>> initialize them with values of your choice.
* 4. Read those values and print them.
* 5. Add a function template get() that returns a reference to val.
* 6. Put the definition of get() outside the class.
* 7. Make val private.
* 8. Do 4 again using get().
* 9. Add a set() function template so that you can change val.
* 10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler
*     than §19.2.5.
* 11. Provide const and non-const versions of get().
* 12. Define a function template<typename T> read_val(T& v) that reads from
*     cin into v.
* 13. Use read_val() to read into each of the variables from 3 except the
*     S<vector<int>> variable.
* 14. Bonus: Define input and output operators (>> and <<) for vector<T>s.
*     For both input and output use a { val, val, val } format. That will allow
*     read_val() to also handle the S<vector<int>> variable.
* Remember to test after each step.
*
* @author Andrei-KS
*/
class CH19P707DRILL1_14RunExmple : public RunCommandOfExample
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

#endif // !__CH19P707DRILL1_14__