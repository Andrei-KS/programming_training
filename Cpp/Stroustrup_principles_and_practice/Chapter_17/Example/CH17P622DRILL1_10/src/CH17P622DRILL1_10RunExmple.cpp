/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 07:44:47
	author                                          : Andrei-KS
*/

#include "CH17P622DRILL1_10RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH17P622DRILL1_10RunExmple();

namespace {
  void print_array10(ostream& os, int* a)
  {
    for (int index = 0; index < 10; ++index)
    {
      cout << a[index] << '\n';
    }
  }
  void print_array(ostream& os, int* a, int n)
  {
    for (int index = 0; index < n; ++index)
    {
      cout << a[index] << '\n';
    }
  }
  void print_vector(const vector<int>& v)
  {
    for (int index = 0; index < v.size(); ++index)
    {
      cout << v[index] << '\n';
    }
  }
}

int CH17P622DRILL1_10RunExmple::excute()
{
  const int SIZE_ARRAY = 10;
  int* arrayTen = new int[SIZE_ARRAY];
  for (int index = 0; index < SIZE_ARRAY; ++index)
  {
    cout << arrayTen[index] << '\n';
  }
  cout << "\nUse print_array10:\n";
  print_array10(cout, arrayTen);
  delete[] arrayTen;

  int* arrayB = new int[SIZE_ARRAY];
  for (int index = 0; index < SIZE_ARRAY; ++index)
  {
    arrayB[index] = 100 + index;
  }
  print_array(cout, arrayB, SIZE_ARRAY);

  const int SIZE_ARRAY_2 = 11;
  int* arrayC = new int[11];
  for (int index = 0; index < SIZE_ARRAY_2; ++index)
  {
    arrayC[index] = 100 + index;
  }
  print_array(cout, arrayC, SIZE_ARRAY_2);

  const int SIZE_ARRAY_3 = 20;
  int* arrayD = new int[SIZE_ARRAY_3];
  for (int index = 0; index < SIZE_ARRAY_3; ++index)
  {
    arrayD[index] = 100 + index;
  }
  print_array(cout, arrayD, SIZE_ARRAY_3);

  cout << "\nuse vector:\n";
  vector<int> vB(10);
  for (int index = 0; index < vB.size(); ++index)
  {
    vB[index] = 100 + index;
  }
  print_array(cout, &vB[0], vB.size());
  print_vector(vB);

  cout << '\n';
  vector<int> vC(10);
  for (int index = 0; index < vC.size(); ++index)
  {
    vC[index] = 100 + index;
  }
  print_array(cout, &vC[0], vC.size());
  print_vector(vC);

  cout << '\n';
  vector<int> vD(20);
  for (int index = 0; index < vD.size(); ++index)
  {
    vD[index] = 100 + index;
  }
  print_array(cout, &vD[0], vD.size());
  print_vector(vD);

  delete[] arrayD;
  delete[] arrayC;
  delete[] arrayB;
	return 0;
}