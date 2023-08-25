/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2023 17:25:27
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC11RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC11RunExmple();

namespace {
  template<typename T>
  vector<T> GetVectorFromList(const list<T>& list)
  {
    vector<T> resultVector;
    for (T element : list)
    {
      resultVector.push_back(element);
    }
    return resultVector;
  }

  template<typename T>
  void print(list<T> l)
  {
    cout << "list<" << typeid(T).name() << "> : ";
    if (l.begin() == l.end())
    {
      cout << "{}\n";
    }
    else
    {
      cout << "{";
      for (T el : l)
      {
        cout << el << ", ";
      }
      cout << "\b\b }\n";
    }
  }

  template<typename T>
  void print(vector<T> v)
  {
    cout << "vector<" << typeid(T).name() << "> : ";
    if (v.begin() == v.end())
    {
      cout << "{}\n";
    }
    else
    {
      cout << "{";
      for (T el : v)
      {
        cout << el << ", ";
      }
      cout << "\b\b }\n";
    }
  }
}

int CH20P755EXERC11RunExmple::excute()
{
  list<int> intsList{ 1,7,3,4,6,2,3,2,7 };
  vector<int> intsVector = GetVectorFromList(intsList);
  print(intsList);
  print(intsVector);

  cout << "sort vector\n";
  sort(intsVector.begin(), intsVector.end());
  print(intsVector);

	return 0;
}