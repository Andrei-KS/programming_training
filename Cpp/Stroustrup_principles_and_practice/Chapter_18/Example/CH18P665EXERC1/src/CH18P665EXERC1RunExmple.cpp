/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/21/2023 09:22:30
	author                                          : Andrei-KS
*/

#include "CH18P665EXERC1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC1RunExmple();

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

  char* mystrdup(const char* str)
  {
    size_t size = getLength(str) + 1;
    char* result = new char[size];
    for (size_t index = 0; index < size; ++index)
    {
      result[index] = str[index];
    }
    return result;
  }
}

int CH18P665EXERC1RunExmple::excute()
{
  char* source = "copyTEXT\ntest\ntest2";
  char* text = mystrdup(source);
  cout << "\n-- source --\n"
    << source
    << "\n-- result --\n"
    << text
    << "\n--        --\n";
  delete[] text;
	return 0;
}