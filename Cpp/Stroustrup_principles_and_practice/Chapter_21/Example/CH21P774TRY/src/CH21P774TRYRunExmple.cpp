/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 13:02:38
	author                                          : Andrei-KS
*/
#include <numeric>
#include "CH21P774TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P774TRYRunExmple();

namespace {
  /*
  */
  struct Record {
    /**/
    double unit_price;

    /* number of units sold */
    int units;
  };

  /*
  * calculate priceand accumulate
  */
  double price(double v, const Record& r)
  {
    return v + r.unit_price * r.units;
  }

  void f(const vector<Record>& vr)
  {
    double total = accumulate(vr.begin(), vr.end(), 0.0, price);
  }
}

int CH21P774TRYRunExmple::excute()
{
  vector<Record> vr =
  {
    {25,4},
    {20,5},
    {5,4},
    {4,50},
  };

  f(vr);

	return 0;
}