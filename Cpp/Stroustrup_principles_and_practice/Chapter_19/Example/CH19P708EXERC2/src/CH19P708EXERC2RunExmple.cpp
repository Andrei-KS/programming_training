/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/10/2023 07:44:57
	author                                          : Andrei-KS
*/

#include "CH19P708EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P708EXERC2RunExmple();

namespace {
  template<typename T, typename U>
  T f(const vector<T>& vt, const vector<U>& vu)
  {
    T result = 0;
    if (vt.size() != vu.size())
    {
      error("f(vector<T>& v1, const vector<T>& v2): v1.size != v2.size");
    }

    for (int index = 0; index < vt.size(); ++index)
    {
      result += vt[index] * vu[index];
    }

    return result;
  }

  template<typename T>
  void print(vector<T> v)
  {
    cout << "\n--- vector<" << typeid(v).name() << "> ---\n{ ";
    for (int index = 0; index < v.size(); ++index)
    {
      cout << v[index] << ", ";
    }
    cout << "\b\b }\n";
  }
}

int CH19P708EXERC2RunExmple::excute()
{
  vector<int> intsV1 = { 1,2,3,4 };
  vector<int> intsV2 = { 1,2,3,4 };
  vector<int> intsV3 = { 1,1,1 };

  print(intsV1);
  print(intsV2);
  print(intsV3);

  cout << f(intsV1, intsV2) << "\n";

  cout << f(intsV1, intsV3) << "\n";

	return 0;
}