/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/14/2023 08:24:22
	author                                          : Andrei-KS
*/

#include "CH21P800EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P800EXERC3RunExmple();

namespace {
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
    cout << "count : " << mycount(tVector.begin(), tVector.end(), value) << "\n";
  }
}

int CH21P800EXERC3RunExmple::excute()
{
  vector<int> vi{ 10,4,5,2,2354,123,5,64,10,5,2,7,23,5,6,34,7,3 };
  testVector(vi, 10);
  testVector(vi, 5);

  vector<double> vd{ 1.1, 2.8, 1.1, 2.9, -5.2, -66, -3, 1.1 };
  testVector(vd, 1.1);
  testVector(vd, 1.0);

  cout << "\n--- Test string ---\n";
  string sTest = "adsaefsdfawdasdaswaf";
  cout << "string : " << sTest << "\n";
  char cSymbol = 'a';
  cout << "value : " << cSymbol << "\n";
  cout << "count : " << mycount(sTest.begin(), sTest.end(), cSymbol) << "\n";

  return 0;
}