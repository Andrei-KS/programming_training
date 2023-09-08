/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 13:09:46
	author                                          : Andrei-KS
*/
#include <map>
#include <numeric>
#include "CH21P785TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P785TRYRunExmple();

namespace {
  // extract valuesand multiply
  double weighted_value( const pair<string, double>& a, const pair<string, double>& b)
  {
    return a.second * b.second;
  }

}

int CH21P785TRYRunExmple::excute()
{

  // Dow Jones Industrial index(symbol,price);
  // for up - to - date quotes see
  // www.djindexes.com
  // and
  // www.slickcharts.com
  map<string, double> dow_price = {
    {"MMM",81.86},
    {"AA",34.69},
    {"MO",54.45},
    {"UNH",481.95},
    {"MSFT",329.53},
    {"HD",327.75},
  };

  // Dow(symbol,weight)
  map<string, double> dow_weight = {
    {"MMM", 5.8549},
    {"AA",2.4808},
    {"MO",3.8940},
    {"UNH",9.1081},
    {"MSFT",6.3570},
    {"HD",6.2256},
  };

  // Dow(symbol,name)
  map<string, string> dow_name = {
    {"MMM","3M Co."},
    {"AA","Alcoa Inc."},
    {"MO","Altria Group Inc."},
    {"UNH","Unitedhealth Group Inc."},
    {"MSFT","Microsoft Corp"},
    {"HD","Home Depot Inc"},
  };

  //  read values from a map
  double alcoa_price = dow_price["AA"];
  double boeing_price = dow_price["HD"];
  // find an entry in a map
  if (dow_price.find("INTC") != dow_price.end())
  {
    cout << "Intel is in the Dow\n";
  }
  
  // write price for each company in the Dow index :
  for (const auto& p : dow_price)
  {
    // the “ticker” symbol
    const string& symbol = p.first;
    cout << symbol << '\t'
      << p.second << '\t'
      << dow_name[symbol] << '\n';
  }

  double dji_index = inner_product(dow_price.begin(), dow_price.end(), //all companies
      dow_weight.begin(), //their weights
      0.0, //initial value
      plus<double>(), //add(as usual)
      weighted_value); //extract valuesand weightsand multiply
  cout << "dji_index\t" << dji_index << "\n";
	return 0;
}