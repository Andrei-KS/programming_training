/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/10/2023 08:38:47
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC3RunExmple();

namespace {
  template<typename T, typename U>
  class myPair {
  public:
    /* */
    T first;

    /* */
    U second;
  };

  class VarTable {
  public:
    /* */
    typedef myPair<string, double> varPair;

  private:
    /* */
    vector<varPair> var_table;
  
  public:
    /*
    */
    double get_value(const string& s)
    {
      for (const varPair& pair : var_table)
      {
        if (pair.first == s)
        {
          return pair.second;
        }
      }
      error("get: undefined variable ", s);
    }

    /*
    */
    void set_value(const string& s, double d)
    {
      for (varPair& pair : var_table)
      {
        if (pair.first == s)
        {
          pair.second =  d;
          return;
        }
      }
      error("set: undefined variable ", s);
    }

    bool is_declared(const string& var)
    {
      for (const varPair& v : var_table)
      {
        if (v.first == var)
        {
          return true;
        }
      }
      return false;
    }

    double define_name(const string& var, double val)
    {
      if (is_declared(var))
      {
        error(var, " declared twice");
      }
      var_table.push_back(varPair{ var, val });
      return val;
    }
  };
}

int CH19P709EXERC3RunExmple::excute()
{
  VarTable vt;
  vt.define_name("a", 1.0);
  vt.define_name("b", 2.0);

  cout << "a : " << vt.get_value("a") << "\n"
    << "b : " << vt.get_value("b") << "\n";

  vt.set_value("a", 3.0);

  cout << "a : " << vt.get_value("a") << "\n"
    << "b : " << vt.get_value("b") << "\n";
  cout << "b : " << vt.get_value("c") << "\n";

	return 0;
}