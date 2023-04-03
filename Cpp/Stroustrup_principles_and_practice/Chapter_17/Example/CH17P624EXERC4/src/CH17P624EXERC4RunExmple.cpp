/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 23:18:28
	author                                          : Andrei-KS
*/

#include "CH17P624EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH17P624EXERC4RunExmple();

namespace {
  int getLength(const char* str)
  {
    int resualt = 1;
    while (*str++ != '\0')
    {
      ++resualt;
    }
    return resualt;
  }

  char* strdupMy(const char* str)
  {
    //cout << str << '\n';
    int size = getLength(str);
    //cout << size << '\n';
    char* resualt = new char[size];
    //cout << resualt << '\n';
    while (*resualt++ = *str++){}
    //cout << (resualt - size) << '\n';
    return (resualt-size);
  }
}

int CH17P624EXERC4RunExmple::excute()
{
  char* str = strdupMy("Hello sun");
  cout << str << '\n';
  delete[] str;
	return 0;
}