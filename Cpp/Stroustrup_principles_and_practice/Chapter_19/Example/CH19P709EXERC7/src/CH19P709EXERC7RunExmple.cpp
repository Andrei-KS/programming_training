/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/22/2023 09:29:24
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC7RunExmple();



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
    Number& operator+=(const Number& other)
    {
      value += other.value;
      return *this;
    }

    /*
    */
    Number& operator-=(const Number& other)
    {
      value -= other.value;
      return *this;
    }

    /*
    */
    Number& operator*=(const Number& other)
    {
      value *= other.value;
      return *this;
    }

    /*
    */
    Number& operator/=(const Number& other)
    {
      if (other.value == 0)
      {
        error("error: divider is zero");
      }
      value /= other.value;
      return *this;
    }

    /*
    */
    Number operator%=(const Number& other)
    {
      if (other.value == 0)
      {
        error("error: divider is zero");
      }

      value %= other.value;
      return *this;
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
    template<typename T> friend Number<T> operator+(Number<T> lhs, const Number<T>& rhs);

    /*
    */
    template<typename T> friend Number<T> operator-(Number<T> lhs, const Number<T>& rhs);

    /*
    */
    template<typename T> friend Number<T> operator*(Number<T> lhs, const Number<T>& rhs);

    /*
    */
    template<typename T> friend Number<T> operator/(Number<T> lhs, const Number<T>& rhs);

    /*
    */
    template<typename T> friend Number<T> operator%(Number<T> lhs, const Number<T>& rhs);

    /*
    */
    template<typename T> friend ostream& operator<<(ostream& os, const Number<T>& value);

    /*
    */
    friend istream& operator>> <>(istream& is, Number& value);

  };

  template<typename T>
  Number<T> operator+(Number<T> lhs, const Number<T>& rhs)
  {
    lhs += rhs;
    return lhs;
  }

  template<typename T>
  Number<T> operator-(Number<T> lhs, const Number<T>& rhs)
  {
    lhs -= rhs;
    return lhs;
  }

  template<typename T>
  Number<T> operator*(Number<T> lhs, const Number<T>& rhs)
  {
    lhs *= rhs;
    return lhs;
  }

  template<typename T>
  Number<T> operator/(Number<T> lhs, const Number<T>& rhs)
  {
    lhs /= rhs;
    return lhs;
  }

  template<typename T>
  Number<T> operator%(Number<T> lhs, const Number<T>& rhs)
  {
    lhs %= rhs;
    return lhs;
  }

  template<typename T>
  ostream& operator<<(ostream& os, const Number<T>& value)
  {
    return os << value.value << "(Number<int>)";
  }

  template<typename T>
  istream& operator>>(istream& is, Number<T>& value)
  {
    return is >> value.value;
  }

  template<typename T, typename U>
  T f(const vector<T>& vt, const vector<U>& vu)
  {
    T result = 0;
    if (vt.size() != vu.size())
    {
      error("f(vector<T>& v1, const vector<T>& v2): v1.size != v2.size");
    }

    for (int index = 0; index < vt.size(); ++index)
    {
      result += vt[index] * vu[index];
    }

    return result;
  }

  template<typename T>
  void print(vector<T> v)
  {
    cout << "\n--- vector<" << typeid(v).name() << "> ---\n{ ";
    for (int index = 0; index < v.size(); ++index)
    {
      cout << v[index] << ", ";
    }
    cout << "\b\b }\n";
  }
}

int CH19P709EXERC7RunExmple::excute()
{
  vector<Number<int>> intsV1 = { 1,2,3,4 };
  vector<Number<int>> intsV2 = { 1,2,3,4 };
  vector<Number<int>> intsV3 = { 1,1,1 };

  print(intsV1);
  print(intsV2);
  print(intsV3);

  cout << f(intsV1, intsV2) << "\n";

  cout << f(intsV1, intsV3) << "\n";

	return 0;
}