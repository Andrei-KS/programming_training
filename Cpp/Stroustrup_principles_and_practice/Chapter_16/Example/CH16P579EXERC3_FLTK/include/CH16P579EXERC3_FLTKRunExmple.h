/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/12/2022 10:47:57
	author                                          : Andrei-KS
*/
#ifndef __CH16P579EXERC3_FLTK__
#define __CH16P579EXERC3_FLTK__

#include "RunCommandOfExample.h"

/*
* Place an Image on top of a Button move both when the button is pushed.
* Use this random number generator from std_lib_facilities.h to pick a
* new location for the “image button”:
* #include<random>
* inline int rand_int(int min, int max)
* {
*   static default_random_engine ran
*   return uniform_int_distribution<>{min,max}(ran)
* }
* It returns a random int in the range [min,max).
*
* @author Andrei-KS
*/
class CH16P579EXERC3_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH16P579EXERC3_FLTK__