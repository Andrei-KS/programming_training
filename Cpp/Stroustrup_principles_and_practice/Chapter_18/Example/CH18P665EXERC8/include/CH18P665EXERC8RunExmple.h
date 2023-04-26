/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 09:02:01
	author                                          : Andrei-KS
*/
#ifndef __CH18P665EXERC8__
#define __CH18P665EXERC8__

#include "RunCommandOfExample.h"

/*
* Rewrite all the functions in §18.7 to use the approach of making a back-
* ward copy of the string and then comparing for example, take "home",
* generate "emoh", and compare those two strings to see that they are
* different, so home isn’t a palindrome.
*
* @author Andrei-KS
*/
class CH18P665EXERC8RunExmple : public RunCommandOfExample
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

#endif // !__CH18P665EXERC8__