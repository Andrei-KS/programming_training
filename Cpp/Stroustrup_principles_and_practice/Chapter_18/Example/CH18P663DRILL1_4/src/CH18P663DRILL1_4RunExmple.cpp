/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/19/2023 08:50:12
	author                                          : Andrei-KS
*/

#include "CH18P663DRILL1_4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P663DRILL1_4RunExmple();

namespace {
  int globalArraySize = 6;
  int globalArray[] = { 1, 2, 4, 8, 16, 32 };

  void f(int a[], int size)
  {
    const int LOCAL_ARRAY_SIZE = 10;
    int localArray[LOCAL_ARRAY_SIZE];
    for (int index = 0; index < LOCAL_ARRAY_SIZE && index < size; ++index)
    {
      localArray[index] = a[index];
    }

    cout << "\n";
    for (int index = 0; index < LOCAL_ARRAY_SIZE; ++index)
    {
      cout << localArray[index] << " ";
    }
    cout << "\n";

    int* p = new int[size];
    for (int index = 0; index < size; ++index)
    {
      p[index] = a[index];
    }

    cout << "\n";
    for (int index = 0; index < size; ++index)
    {
      cout << p[index] << " ";
    }
    cout << "\n";

    delete[] p;
  }
}

int CH18P663DRILL1_4RunExmple::excute()
{
  f(globalArray, globalArraySize);
  
  const int AA_SIZE = 8;
  int aa[AA_SIZE] = { 1 };
  for (int index = 1; index < AA_SIZE; ++index)
  {
    aa[index] = aa[index-1] * (index-1 + 1);
  }
  f(aa, AA_SIZE);
	return 0;
}