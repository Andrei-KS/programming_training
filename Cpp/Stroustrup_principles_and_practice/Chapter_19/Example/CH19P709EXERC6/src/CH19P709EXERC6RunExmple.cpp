/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/18/2023 09:40:11
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC6RunExmple();

// If use this definition, you will get a similar message
// "error C2296: '%': not valid as left operand has type 'T'".
// Because double doesn't have operation '%'
//#define __DOUBLE_CASE_ON__

namespace {
  template<typename T>
  class Number {
    /**/
    T value;

  public:
    /*
    */
    Number()
      : value{ T() }
    {}

    /*
    */
    Number(T newValue)
      : value{ newValue }
    {}

    /*
    */
    Number(const Number& other)
      : value(other.value)
    {}

    /*
    */
    Number(Number&& other)
      : value(other.value)
    {}

    /*
    */
    Number& operator=(const Number& other)
    {
      value = other.value;
      return *this;
    }

    /*
    */
    Number& operator=(Number&& other)
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
    Number operator+(const Number& other)
    {
      return Number(value + other.value);
    }

    /*
    */
    Number operator-(const Number& other)
    {
      return Number(value - other.value);
    }

    /*
    */
    Number operator/(const Number& other)
    {
      if (other.value == 0)
      {
        error("error: divider is zero");
      }
      return Number(value / other.value);
    }

    /*
    */
    Number operator%(const Number& other)
    {
      if (other.value == 0)
      {
        error("error: divider is zero");
      }
      return Number(value % other.value);
    }

    /*
    */
    Number operator*(const Number& other)
    {
      return Number(value * other.value);
    }

    //-----------------------------------------------------------------------------
    // The solution is to convince the compiler while it is examining the class body proper that
    // the operator+ and operator<< functions are themselves templates. There are several ways
    // to do this;
    // 
    // One simple approach is pre-declare each template friend function above the definition of template class 
    // template<typename T> std::ostream& operator<< (std::ostream& o, const Foo<T>& x);
    // 
    // OR
    // 
    // add <> after the name of the function to inform the compiler that the friend
    // declaration declares a template (without <>, it declares a non-template)
    //
    // @see https://isocpp.org/wiki/faq/templates#template-friends
    //-----------------------------------------------------------------------------

    /*
    */
    template<typename T> friend ostream& operator<<(ostream& os, const Number<T>& value);

    /*
    */
    friend istream& operator>> <>(istream& is, Number& value);

  };

  template<typename T>
  ostream& operator<<(ostream& os, const Number<T>& value)
  {
    return os << value.value;
  }

  template<typename T>
  istream& operator>>(istream& is, Number<T>& value)
  {
    return is >> value.value;
  }
}

int CH19P709EXERC6RunExmple::excute()
{
  Number<int> i1 = 1;
  Number<int> i2 = 2;
  Number<int> i3 = 3;
  cout << i1 << "\n"
    << i2 << "\n"
    << i3 << "\n\n";

  i1 = i2 + i3;
  cout << i1 << "\n"
    << i2 << "\n"
    << i3 << "\n\n";

  cin >> i1;
  i2 = i1 % i3;
  i3 = i3 * i1;
  cout << i1 << "\n"
    << i2 << "\n"
    << i3 << "\n\n";

#ifdef __DOUBLE_CASE_ON__
  Number<double> d1 = 15.0;
  Number<double> d2 = 4.0;
  Number<double> d3 = 7.0;
  cout << d1 << "\n"
    << d2 << "\n"
    << d3 << "\n\n";

  d1 = d2 + d3;
  cout << d1 << "\n"
    << d2 << "\n"
    << d3 << "\n\n";

  d2 = d1 % d3;
  cout << d1 << "\n"
    << d2 << "\n"
    << d3 << "\n\n";
#endif // !__DOUBLE_CASE_ON__

	return 0;
}