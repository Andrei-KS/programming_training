/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 07:56:56
	author                                          : Andrei-KS
*/
#ifndef __CH18P665EXERC5__
#define __CH18P665EXERC5__

#include "RunCommandOfExample.h"

/*
* Write a function, string cat_dot(const string& s1, const string& s2),
* that concatenates two strings with a dot in between. For example, cat_
* dot("Niels", "Bohr") will return a string containing Niels.Bohr.
*
* @author Andrei-KS
*/
class CH18P665EXERC5RunExmple : public RunCommandOfExample
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

#endif // !__CH18P665EXERC5__