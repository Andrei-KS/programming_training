/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 11:24:20
	author                                          : Andrei-KS
*/

#include "CH20P753DRILL1_8RunExmple.h"
#include "std_lib_facilities.h"

#define NAME_OF( var ) #var

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P753DRILL1_8RunExmple();

namespace {
  /*
  */
  template<typename Iter>
  void GetIndex(Iter f, Iter e, int value)
  {
    Iter it = find(f, e, value);
    if (it == e)
    {
      cout << value <<" is not found\n";
      return;
    }

    int index = 0;
    while (f != it)
    {
      ++index;
      ++f;
    }
    cout << "position of " << value << " : " << index << "\n";
  }

  /*
  * requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
  */
  template<typename Iter1, typename Iter2>
  Iter2 Copy(Iter1 f1, Iter1 e1, Iter2 f2)
  {
    while (f1 != e1)
    {
      *f2 = *f1;
      ++f1;
      ++f2;
    }
    return f2;
  }


  /*
  */
  template<typename Iter>
  void AddIntValue(Iter first, Iter end, int value)
  {
    while (first != end)
    {
      *first += value;
      ++first;
    }
  }

  /*
  */
  template<typename Iter>
  void printData(string nameVar, Iter first, Iter end)
  {
    cout << "Data\"" << nameVar << "\"[" << typeid(Iter).name() << "] :\n ";
    if (first == end)
    {
      cout << "{ }\n";
      return;
    }

    cout << "{ ";
    while (first != end)
    {
      cout << *first << ", ";
      ++first;
    }
    cout << "\b\b }\n";
  }
}

int CH20P753DRILL1_8RunExmple::excute()
{
  const int intsDataSize = 10;
  int* intsData = new int[intsDataSize] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printData(NAME_OF(intsData), intsData, intsData + intsDataSize);

  vector<int> vectorData{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  printData(NAME_OF(vectorData), vectorData.begin(), vectorData.end());

  list<int> listData{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  printData(NAME_OF(listData), listData.begin(), listData.end());

  int* intsData2 = new int[intsDataSize];
  for (int i = 0; i < intsDataSize; ++i)
  {
    intsData2[i] = intsData[i];
  }
  printData(NAME_OF(intsData2), intsData2, intsData2 + intsDataSize);

  vector<int> vectorData2(vectorData);
  printData(NAME_OF(vectorData2), vectorData2.begin(), vectorData2.end());

  list<int> listData2(listData);
  printData(NAME_OF(listData2), listData2.begin(), listData2.end());

  // add value to ...
  AddIntValue(intsData, intsData + intsDataSize, 2);
  AddIntValue(vectorData.begin(), vectorData.end(), 3);
  AddIntValue(listData.begin(), listData.end(), 5);

  cout << "\n\n--- Report: ---\n";
  printData(NAME_OF(intsData), intsData, intsData + intsDataSize);
  printData(NAME_OF(vectorData), vectorData.begin(), vectorData.end());
  printData(NAME_OF(listData), listData.begin(), listData.end());
  printData(NAME_OF(intsData2), intsData2, intsData2 + intsDataSize);
  printData(NAME_OF(vectorData2), vectorData2.begin(), vectorData2.end());
  printData(NAME_OF(listData2), listData2.begin(), listData2.end());

  // copy
  Copy(intsData, intsData + intsDataSize, vectorData2.begin());
  Copy(vectorData.begin(), vectorData.end(), listData2.begin());
  Copy(listData.begin(), listData.end(), intsData2);

  cout << "\n\n--- Report: ---\n";
  printData(NAME_OF(intsData), intsData, intsData + intsDataSize);
  printData(NAME_OF(vectorData), vectorData.begin(), vectorData.end());
  printData(NAME_OF(listData), listData.begin(), listData.end());
  printData(NAME_OF(intsData2), intsData2, intsData2 + intsDataSize);
  printData(NAME_OF(vectorData2), vectorData2.begin(), vectorData2.end());
  printData(NAME_OF(listData2), listData2.begin(), listData2.end());


  // find
  GetIndex(vectorData.begin(), vectorData.end(), 3);
  GetIndex(listData.begin(), listData.end(), 27);

  delete[] intsData;
  delete[] intsData2;
	return 0;
}