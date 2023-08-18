/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 09:42:17
	author                                          : Andrei-KS
*/

#include "CH20P739TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P739TRYRunExmple();

namespace {
  /*
  * requires Bidirectional_iterator<Iter>
  */
  template<typename Iter>
  void myAdvance(Iter& p, int n)
  {
    if (n > 0)
    {
      while (0 < n) { ++p; --n; }
    }
    else
    {
      while (0 > n) { --p; ++n; }
    }
  }
}

int CH20P739TRYRunExmple::excute()
{
  int* data = new int[10];
  for (int i = 0; i < 10; ++i)
  {
    data[i] = i;
  }


  int* it = data;
  myAdvance(it, 5);
  myAdvance(it, -2);
  myAdvance(it, -5);


  delete[] data;
	return 0;
}