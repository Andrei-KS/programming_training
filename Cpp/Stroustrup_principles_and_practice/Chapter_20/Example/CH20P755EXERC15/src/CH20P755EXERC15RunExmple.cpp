/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/04/2023 09:36:43
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC15RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC15RunExmple();

namespace {
  template<typename T>
  class pvector
  {
    /*\
    */
    vector<T*> mObjects;
  public:

    /*
    */
    pvector(){}

    /*
    */
    ~pvector()
    {
      for (vector<T*>::iterator it = mObjects.begin(); it != mObjects.end(); ++it)
      {
        delete *it;
      }
    }

    /*
    */
    void push_back(T* obj)
    {
      mObjects.push_back(obj);
    }
  };
}

int CH20P755EXERC15RunExmple::excute()
{
  pvector<int> mpv;
  for (int index = 0; index < 10; ++index)
  {
    mpv.push_back(new int(index));
  }
	return 0;
}