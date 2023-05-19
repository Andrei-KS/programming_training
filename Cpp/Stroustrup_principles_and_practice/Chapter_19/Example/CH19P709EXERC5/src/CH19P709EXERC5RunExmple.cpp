/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/17/2023 08:22:47
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC5RunExmple();

namespace {
  class Int {
    /**/
    int value;

  public:
    /*
    */
    Int()
      : value{0}
    {}

    /*
    */
    Int(int newValue)
      : value{newValue}
    {}

    /*
    */
    Int(const Int& other)
      : value(other.value)
    {}

    /*
    */
    Int(Int&& other)
      : value(other.value)
    {}

    /*
    */
    Int& operator=(const Int& other)
    {
      value = other.value;
      return *this;
    }

    /*
    */
    Int& operator=(Int&& other)
    {
      if (this == &other)
      {
        return *this;
      }

      value = other.value;
      return *this;
    }

    /*
    */
    Int operator+(const Int& other)
    {
      return Int(value + other.value);
    }

    /*
    */
    Int operator-(const Int& other)
    {
      return Int(value - other.value);
    }

    /*
    */
    Int operator/(const Int& other)
    {
      if (other.value == 0)
      {
        error("error: divider is zero");
      }
      return Int(value / other.value);
    }

    /*
    */
    Int operator%(const Int& other)
    {
      if (other.value == 0)
      {
        error("error: divider is zero");
      }
      return Int(value % other.value);
    }

    /*
    */
    Int operator*(const Int& other)
    {
      return Int(value * other.value);
    }

    /*
    */
    friend ostream& operator<<(ostream& os, const Int& intValue);

    /*
    */
    friend istream& operator>>(ostream& is, Int& intValue);

  };

  ostream& operator<<(ostream& os, const Int& intValue)
  {
    return os << intValue.value;
  }

  istream& operator>>(ostream& is, Int& intValue)
  {
    return is >> intValue.value;
  }
}

int CH19P709EXERC5RunExmple::excute()
{
  Int i1 = 1;
  Int i2 = 2;
  Int i3 = 3;
  cout << i1 << "\n"
    << i2 << "\n"
    << i3 << "\n\n";

  i1 = i2 + i3;
  cout << i1 << "\n"
    << i2 << "\n"
    << i3 << "\n\n";
	return 0;
}