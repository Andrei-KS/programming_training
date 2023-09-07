/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/07/2023 22:55:45
	author                                          : Andrei-KS
*/

#include "CH21P761TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P761TRYRunExmple();

namespace {
  namespace version1
  {
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
      vector<T>::const_iterator it = myfind(vec.begin(), vec.end(), val);
      if (it != vec.end())
      {
        cout << val << " is found.\n";
      }
      else
      {
        cout << val << " isn't found.\n";
      }
    }
  }

  namespace version2
  {
    /*
    * requires Input_iterator<In>()
    * && Equality_comparable<Value_type<T>>()
    * find the first element in [first,last) that equal val
    */
    template<typename In, typename T>
    In myfind(In first, In last, const T& val)
    {
      for (In p = first; p != last; ++p)
      {
        if (*p == val)
        {
          return p;
        }
      }
      return last;
    }

    template<typename T>
    void try_find(const vector<T>& vec, T val)
    {
      vector<T>::const_iterator it = myfind(vec.begin(), vec.end(), val);
      if (it != vec.end())
      {
        cout << val << " is found.\n";
      }
      else
      {
        cout << val << " isn't found.\n";
      }
    }
  }


}

int CH21P761TRYRunExmple::excute()
{
  vector<int> mv = { 1,5,10,2,4,8 };

  version1::try_find(mv, 5);
  version1::try_find(mv, 13);
  version2::try_find(mv, 5);
  version2::try_find(mv, 13);

	return 0;
}