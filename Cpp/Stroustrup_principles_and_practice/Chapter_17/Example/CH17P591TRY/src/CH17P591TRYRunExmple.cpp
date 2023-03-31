/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/31/2023 07:13:24
	author                                          : Andrei-KS
*/

#include "CH17P591TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH17P591TRYRunExmple();

namespace {
  void sizes(char ch, int i, int* p, bool b, double d)
  {
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << "\n";
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << "\n";
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << "\n";
    cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << "\n";
    cout << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << "\n";
  }
}

int CH17P591TRYRunExmple::excute()
{
  char ch = '1';
  int i = 1;
  int* p = &i;
  bool b = true;
  double d = 1.0;
  sizes(ch, i, p, b, d);
	return 0;
}