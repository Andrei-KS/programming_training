/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 08:06:33
	author                                          : Andrei-KS
*/

#include "CH18P665EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC7RunExmple();

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

  char* cat_dot(const char* s1, const char* s2, const char* separator = ".")
  {
    const size_t sizeS1 = getLength(s1);
    const size_t sizeS2 = getLength(s2);
    const size_t sizeSeparator = getLength(separator);

    size_t sizeResult = sizeS1 + sizeS2 + sizeSeparator;
    char* result = new char[sizeResult + 1];
    size_t indexResult = 0;

    for (size_t index = 0; index < sizeS1; ++index,++indexResult)
    {
      result[indexResult] = s1[index];
    }

    for (size_t index = 0; index < sizeSeparator; ++index, ++indexResult)
    {
      result[indexResult] = separator[index];
    }

    for (size_t index = 0; index < sizeS2; ++index, ++indexResult)
    {
      result[indexResult] = s2[index];
    }

    result[indexResult] = '\0';
    return result;
  }
}

int CH18P665EXERC7RunExmple::excute()
{
  char* result = cat_dot("Niels", "Bohr");
  cout << result << "\n";
  delete[] result;

  result = cat_dot("Niels", "Bohr", "-/\\-");
  cout << result << "\n";
  delete[] result;
  return 0;
}