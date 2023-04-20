/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/20/2023 09:19:25
	author                                          : Andrei-KS
*/

#include "CH18P663DRILL1_4_vectorRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P663DRILL1_4_vectorRunExmple();

namespace {
  vector<int> gv = { 1,2,4,8,16,32 };
  void f(vector<int>& v)
  {
    vector<int> lv(v.size());
    for (int index = 0; index < v.size(); ++index)
    {
      lv[index] = v[index];
    }

    cout << "--\n";
    for (int index = 0; index < lv.size(); ++index)
    {
      cout << lv[index] << " ";
    }
    cout << "\n";

    vector<int> lv2(v);
    cout << "\n";
    for (int index = 0; index < lv2.size(); ++index)
    {
      cout << lv2[index] << " ";
    }
    cout << "\n--\n";
  }
}

int CH18P663DRILL1_4_vectorRunExmple::excute()
{
  f(gv);

  vector<int> vv(1,1);
  for (int index = 0; index < 8; ++index)
  {
    vv.push_back(vv[index]*(index+1));
  }
  f(vv);
	return 0;
}