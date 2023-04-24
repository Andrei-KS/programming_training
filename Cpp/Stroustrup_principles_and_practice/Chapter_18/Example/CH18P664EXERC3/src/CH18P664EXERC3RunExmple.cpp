/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/24/2023 08:54:31
	author                                          : Andrei-KS
*/

#include "CH18P664EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P664EXERC3RunExmple();

namespace {
  size_t getLength(const char* str)
  {
    size_t length = 0;
    while (*str++ != '\0')
    {
      ++length;
    }
    return length;
  }

  int mystrcmp(const char* s1, const char* s2)
  {
    const size_t sizeS1 = getLength(s1);
    const size_t sizeS2 = getLength(s2);

    for(int index = 0;index < sizeS1 && index < sizeS2;++index)
    {
      if (s1[index] != s2[index])
      {
        return s1[index] > s2[index] ? 1 : -1;
      }
    }

    if (sizeS1 == sizeS2)
    {
      return 0;
    }

    return sizeS1 > sizeS2 ? 1 : -1;
  }
}

int CH18P664EXERC3RunExmple::excute()
{
  cout << mystrcmp("aaa", "aaa") << "\n";
  cout << mystrcmp("aba", "aaa") << "\n";
  cout << mystrcmp("aaa", "aba") << "\n";
  cout << mystrcmp("aa", "aaa") << "\n";
	return 0;
}