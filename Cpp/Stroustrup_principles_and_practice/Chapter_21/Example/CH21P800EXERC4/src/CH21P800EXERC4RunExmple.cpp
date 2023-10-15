/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/15/2023 06:42:55
	author                                          : Andrei-KS
*/

#include "CH21P800EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P800EXERC4RunExmple();

namespace {
  template<typename Iter, typename UnaryPredicate>
  typename iterator_traits<Iter>::difference_type mycount_if(Iter first, Iter second, UnaryPredicate upre)
  {
    typename iterator_traits<Iter>::difference_type ret = 0;
    while (first != second)
    {
      if (upre(*first)) ++ret;
      ++first;
    }
    return ret;
  }

  template<typename T, typename UnaryPredicate>
  void testVector(const vector<T>& tVector, UnaryPredicate upre)
  {
    cout << "\n--- count(vector<" << typeid(T).name() << ">) : ---\n";
    cout << "tVector : {";
    ostream_iterator<T> oit{ cout, "," };
    copy(tVector.begin(), tVector.end(), oit);
    cout << "\b}\n";
    cout << "count : " << mycount_if(tVector.begin(), tVector.end(), upre) << "\n";
  }
}

int CH21P800EXERC4RunExmple::excute()
{
  vector<int> vi{ 10,4,5,2,2354,123,5,64,10,5,2,7,23,5,6,34,7,3 };
  testVector(vi, [](int value) { return value < 10; });
  testVector(vi, [](int value) {return value >= 10; });

  vector<double> vd{ 1.1, 2.8, 1.1, 2.9, -5.2, -66, -3, 1.1 };
  testVector(vd, [](double value) { return value < 1.1; });
  testVector(vd, [](double value) {return value >= 1.0 && value <= 2; });

  cout << "\n--- Test string ---\n";
  string sTest = "adsaefsdfawdasdaswaf";
  cout << "string : " << sTest << "\n";
  cout << "count : " << mycount_if(sTest.begin(), sTest.end(), [](char value) {return value == 'a'; }) << "\n";
	return 0;
}