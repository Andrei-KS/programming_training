/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/05/2023 11:47:03
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC16RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC16RunExmple();

namespace {
  template<typename T>
  class ovector
  {
    /*\
    */
    vector<T*> mObjects;
  public:

    /*
    */
    ovector() {}

    /*
    */
    ~ovector()
    {
      for (vector<T*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
      {
        delete* it;
      }
    }

    /*
    */
    void push_back(T* obj)
    {
      mObjects.push_back(obj);
    }

    /*
    */
    T& operator[](size_t index)
    {
      return *mObjects[index];
    }

    /*
    */
    const T& operator[](size_t index) const
    {
      return *mObjects[index];
    }

    /*
    */
    T& operator*()
    {
      return *mObjects[0];
    }

    /*
    */
    const T& operator*() const
    {
      return *mObjects[0];
    }
  };
}

int CH20P755EXERC16RunExmple::excute()
{
  ovector<int> mov;
  for (int index = 0; index < 10; ++index)
  {
    mov.push_back(new int(index));
  }

  cout << mov[0] << " address: " << &(*mov) << "\n";
  for (int index = 0; index < 10; ++index)
  {
    cout << mov[index] << " address: " << &mov[index] << "\n";
  }

	return 0;
}