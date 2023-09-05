/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/05/2023 17:00:18
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC17RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC17RunExmple();

namespace {
  template<typename T>
  class ownership_vector
  {
    /*\
    */
    vector<T*> mObjects;

    /*
    */
    vector<T*> mOwnObjects;
  public:

    /*
    */
    ownership_vector() {}

    /*
    */
    ~ownership_vector()
    {
      for (vector<T*>::iterator it = mOwnObjects.begin(); it != mOwnObjects.end(); ++it)
      {
        delete* it;
      }
    }

    /*
    */
    void push_back(T* pObj)
    {
      mOwnObjects.push_back(pObj);
      mObjects.push_back(pObj);
    }

    /*
    */
    void push_back(T& pObj)
    {
      mObjects.push_back(&pObj);
    }

  };
}

int CH20P755EXERC17RunExmple::excute()
{
  vector<int> mv;
  {
    ownership_vector<int> mpv;
    for (int index = 0; index < 10; ++index)
    {
      mpv.push_back(new int(index));
      mv.push_back(index * 10);
      mpv.push_back(mv.back());
    }
  }
	return 0;
}