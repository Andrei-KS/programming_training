/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 08:00:47
	author                                          : Andrei-KS
*/

#include "CH18P665EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC6RunExmple();

namespace {
  string cat_dot(const string& s1, const string& s2, const string& separator = ".")
  {
    return s1 + separator + s2;
  }
}

int CH18P665EXERC6RunExmple::excute()
{
  cout << cat_dot("Niels", "Bohr") << "\n";
  cout << cat_dot("Niels", "Bohr", "-/\\-") << "\n";
	return 0;
}