/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 12/06/2023 06:08:21
	author                                          : Andrei-KS
*/

#include "CH21P800EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P800EXERC5RunExmple();

namespace {
  /*
  * requires Input_iterator<In>()
  * && Equality_comparable<Value_type<T>>()
  * find the first element in [first,last) that equal val
  */
  template<typename In, typename T>
  In myfind(In first, In last, const T& val)
  {
    while (first != last && *first != val)
    {
      ++first;
    }
    return first;
  }

  template<typename T>
  void try_find(const vector<T>& vec, T val)
  {
    vector<T>::const_iterator EndIt = vec.end() - 1;
    vector<T>::const_iterator it = myfind(vec.begin(), EndIt, val);
    if (it != EndIt || *EndIt == val)
    {
      cout << val << " is found.\n";
    }
    else
    {
      cout << val << " isn't found.\n";
    }
  }

  template<typename Iter, typename T>
  typename iterator_traits<Iter>::difference_type mycount(Iter first, Iter second, const T& value)
  {
    typename iterator_traits<Iter>::difference_type ret = 0;
    while (first != second)
    {
      if (*first == value) ++ret;
      ++first;
    }
    return ret;
  }

  template<typename T>
  void testVector(const vector<T>& tVector, const T& value)
  {
    cout << "\n--- count(vector<" << typeid(T).name() << ">) and value " << value << " : ---\n";
    cout << "tVector : {";
    ostream_iterator<T> oit{ cout, "," };
    copy(tVector.begin(), tVector.end(), oit);
    cout << "\b}\n";
    cout << "value : " << value << "\n";
    vector<T>::const_iterator EndIt = tVector.end() - 1;
    iterator_traits<vector<T>::const_iterator>::difference_type number = mycount(tVector.begin(), EndIt, value);
    number += *EndIt == value? 1 : 0;
    cout << "count : " << number << "\n";
  }
}

int CH21P800EXERC5RunExmple::excute()
{
  vector<int> mv{ 10,4,5,2,2354,123,5,64,10,5,2,7,23,5,6,34,7,3,30 };

  try_find(mv, 5);
  try_find(mv, 13);
  try_find(mv, 30);

  testVector(mv, 10);
  testVector(mv, 5);
  testVector(mv, 30);
	return 0;
}