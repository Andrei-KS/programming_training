/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2023 08:26:01
	author                                          : Andrei-KS
*/

#include "CH20P722TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P722TRYRunExmple();

namespace {
  void copy(int* f1, int* e1, int* f2)
  {
    while (f1 != e1)
    {
      *f2 = *f1;
      ++f1;
      ++f2;
    }
  }

  void print(int* f, int* e)
  {
    if (f == e)
    {
      cout << "{\n}\n";
      return;
    }

    cout << "{";
    while(f!=e)
    {
      cout << "\n" << f << ":" << *f << ",";
      ++f;
    }
    cout << "\b \n}\n";
    
  }
}

int CH20P722TRYRunExmple::excute()
{
  random_device rd;
  int size = rd() % 20;
  int* pData1 = new int[size];
  int* pData2 = new int[size];
  
  for (int* f = pData1,*e = pData1 + size; f != e; ++f)
  {
    *f = (rd() % 1000) * 1.0 / 10;
  }
  print(pData1, pData1 + size);
  print(pData2, pData2 + size);

  cout << "\n";

  copy(pData1, pData1 + size, pData2);
  print(pData1, pData1 + size);
  print(pData2, pData2 + size);

  delete[] pData1;
  delete[] pData2;
	return 0;
}