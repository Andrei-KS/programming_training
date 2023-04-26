/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 09:02:01
	author                                          : Andrei-KS
*/

#include "CH18P665EXERC8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC8RunExmple();

namespace {
  size_t getLength(const char* str)
  {
    size_t ret = 0;
    while (str[ret] != '\0')
    {
      ++ret;
    }
    return ret;
  }

  char* getBackwardStr(const char* str)
  {
    const size_t sizeStr = getLength(str);
    char* backwordStr = new char[sizeStr + 1];
    for (size_t index = 0; index < sizeStr; ++index)
    {
      backwordStr[index] = str[sizeStr - 1 - index];
    }
    backwordStr[sizeStr] = '\0';
    return backwordStr;
  }

  bool is_palindrome(const char* str)
  {
    char* backwordStr = getBackwardStr(str);
    char* head = backwordStr;
    bool result = true;
    while (*head != '\0')
    {
      if (*head != *str)
      {
        result = false;
        break;
      }
      ++head;
      ++str;
    }
    delete[] backwordStr;
    return result;
  }
}

int CH18P665EXERC8RunExmple::excute()
{
  cout << std::boolalpha << is_palindrome("home") << "\n";
  cout << std::boolalpha << is_palindrome("totetot") << "\n";
	return 0;
}