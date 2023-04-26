/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 07:56:56
	author                                          : Andrei-KS
*/

#include "CH18P665EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC5RunExmple();

namespace {
  string cat_dot(const string& s1, const string& s2)
  {
    return s1 + string(".") + s2;
  }
}

int CH18P665EXERC5RunExmple::excute()
{
  cout << cat_dot("Niels", "Bohr") << "\n";
	return 0;
}