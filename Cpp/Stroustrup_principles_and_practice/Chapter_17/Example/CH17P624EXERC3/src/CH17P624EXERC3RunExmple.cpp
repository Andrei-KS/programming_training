/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 21:50:06
	author                                          : Andrei-KS
*/

#include "CH17P624EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH17P624EXERC3RunExmple();

namespace {
  void to_lower(char* str)
  {
    while (*str != '\0')
    {
      if (*str >= 'A' && *str <= 'Z')
      {
        *str = *str - 'A' + 'a';
      }
      ++str;
    }
  }
}

int CH17P624EXERC3RunExmple::excute()
{
  char s[] = "Hello, World";
  cout << s << '\n';

  to_lower(s);
  cout << s << '\n';
	return 0;
}