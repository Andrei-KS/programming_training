/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 12:28:33
	author                                          : Andrei-KS
*/

#include "CH21P765TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P765TRYRunExmple();

namespace {
  // the value to which larger_than_v() compares its argument
  double v_val;
  // the global variable is not a good idea for a parallel program,
  // because we don't know what value it is equal at every time moment
  bool larger_than_v(double x) { return x > v_val; }
}

int CH21P765TRYRunExmple::excute()
{
  vector<double> v = {1.0, 2.0, 31.0, 28.0};

  // set v_val to 31 for the next call of larger_than_v
  v_val = 31;
  auto p = find_if(v.begin(), v.end(), larger_than_v);
  if (p != v.end()) {
    /* we found a value > 31 */
    cout << v_val  << " not found\n";
  }

  // set v_val to x for the next call of larger_than_v
  int x = 28;
  v_val = x;
  auto q = find_if(v.begin(), v.end(), larger_than_v);
  if (q != v.end()) {
    /* we found a value > x */
    cout << v_val << " not found\n";
  }

	return 0;
}