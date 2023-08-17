/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2023 08:02:56
	author                                          : Andrei-KS
*/

#include "CH20P715TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P715TRYRunExmple();

namespace {
  /*
  * @return a pointer to the element in[first, last) that has the highest value
  */
  double* high(double* first, double* last)
  {
    // This assume is not correctly, because if all value can less -1, we will get -1, but it is not true value.
    // double h = -1;

    double* high = first;
    // This assume is correct, but we have one case where we can get runtime error, first == last
    if (first == last)
    {
      return nullptr;
    }

    for (double* p = first; p != last; ++p)
    {
      if (*high < *p)
      {
        high = p;
      }
    }
    return high;
  }
}

int CH20P715TRYRunExmple::excute()
{
  random_device rd;
  int size = rd() % 100;
  double* pData = new double[size];
  for (int index = 0; index < size; ++index)
  {
    *(pData + index) = (rd() % 1000) * 1.0 / 10;
  }

  cout << "{ ";
  for (int index = 0; index < size; ++index)
  {
    cout << *(pData + index) << ", ";
  }
  if (size)
  {
    cout << "\b";
  }
  cout <<  "\b }\n";

  double* highValue = high(pData, pData + size);
  if (!highValue)
  {
    cout << "Array is empty\n";
  }
  else
  {
    cout << "High value : " << *highValue << "\n";
  }

  delete[] pData;
	return 0;
}