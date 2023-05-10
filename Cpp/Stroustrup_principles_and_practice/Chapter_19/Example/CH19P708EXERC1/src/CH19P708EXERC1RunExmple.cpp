/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/10/2023 07:17:51
	author                                          : Andrei-KS
*/

#include "CH19P708EXERC1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P708EXERC1RunExmple();

namespace {
  template<typename T>
  void f(vector<T>& v1, const vector<T>& v2)
  {
    if (v1.size() != v2.size())
    {
      error("f(vector<T>& v1, const vector<T>& v2): v1.size != v2.size");
    }

    for (int index = 0; index < v1.size(); ++index)
    {
      v1[index] += v2[index];
    }
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

int CH19P708EXERC1RunExmple::excute()
{
  vector<int> intsV1 = { 1,2,3,4 };
  vector<int> intsV2 = { 1,1,1,1 };
  vector<int> intsV3 = { 1,1,1 };
  
  print(intsV1);
  print(intsV1);
  
  f(intsV1, intsV2);
  print(intsV1);

  f(intsV1, intsV3);
  print(intsV1);

	return 0;
}