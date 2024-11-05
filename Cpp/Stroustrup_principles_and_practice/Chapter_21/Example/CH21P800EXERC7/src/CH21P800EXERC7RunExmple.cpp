/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/05/2024 08:31:09
	author                                          : Andrei-KS
*/

#include "CH21P800EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P800EXERC7RunExmple();

namespace {
  template<class ForwardIt, typename T, class Compare>
  bool my_binary_search(ForwardIt begin, ForwardIt end, const T& value, Compare comp)
  {
    std::iterator_traits<ForwardIt>::difference_type dist = distance(begin, end);
    if (!dist)
    {
      return false;
    }

    ForwardIt midIt = begin;
    while (dist > 1)
    {
      dist = dist / 2;
      midIt = begin;
      advance(midIt, dist);

      if (*midIt == value)
      {
        return true;
      }

      if (comp(*midIt, value))
      {
        begin = midIt;
      }
    }

    return false;
  }

  template<class T>
  void print(const T& sequence)
  {
    ostream_iterator<T::value_type> oo(cout, " ");
    copy(sequence.begin(), sequence.end(), oo);
    cout << "\n";
  }
  
  bool comp(const int lh, const int rh) { return lh < rh; }
}

int CH21P800EXERC7RunExmple::excute()
{
  vector<int> testIntVector1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
  vector<int> testIntVector2 = { 1, 2, 3, 5, 6, 7, 8, 9, 10, 11 };
  vector<int> testIntVector3 = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 11 };
  list<int> testIntList1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
  list<int> testIntList2 = { 1, 2, 3, 5, 6, 7, 8, 9, 10, 11 };
  list<int> testIntList3 = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 11 };
  print(testIntVector1);
  print(testIntVector2);
  print(testIntVector3);
  print(testIntList1);
  print(testIntList2);
  print(testIntList3);
  int searchValue = 4;
  cout << boolalpha;
  cout << searchValue << "\n";
  cout << my_binary_search(testIntVector1.begin(), testIntVector1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector2.begin(), testIntVector2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector3.begin(), testIntVector3.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList1.begin(), testIntList1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList2.begin(), testIntList2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList3.begin(), testIntList3.end(), searchValue, comp) << "\n";
  searchValue = 8;
  cout << searchValue << "\n";
  cout << my_binary_search(testIntVector1.begin(), testIntVector1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector2.begin(), testIntVector2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector3.begin(), testIntVector3.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList1.begin(), testIntList1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList2.begin(), testIntList2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList3.begin(), testIntList3.end(), searchValue, comp) << "\n";
  searchValue = 9;
  cout << searchValue << "\n";
  cout << my_binary_search(testIntVector1.begin(), testIntVector1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector2.begin(), testIntVector2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector3.begin(), testIntVector3.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList1.begin(), testIntList1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList2.begin(), testIntList2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList3.begin(), testIntList3.end(), searchValue, comp) << "\n";
  searchValue = 20;
  cout << searchValue << "\n";
  cout << my_binary_search(testIntVector1.begin(), testIntVector1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector2.begin(), testIntVector2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntVector3.begin(), testIntVector3.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList1.begin(), testIntList1.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList2.begin(), testIntList2.end(), searchValue, comp) << "\n";
  cout << my_binary_search(testIntList3.begin(), testIntList3.end(), searchValue, comp) << "\n";
  return 0;
}