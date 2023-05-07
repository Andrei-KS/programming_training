/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/04/2023 07:30:01
	author                                          : Andrei-KS
*/

#include "CH19P707DRILL1_14RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P707DRILL1_14RunExmple();

#define __PARAMETR__PRIVATE_VAL__

namespace {
  // Important note: we can't split the file into
  // two files *.h and *.cpp, which will have
  // a declaration and definition of the template.
  // But we can split the declaration and definition
  // of the template into one file or the unit.
  template<typename T>
  struct S
  {
#ifdef __PARAMETR__PRIVATE_VAL__
  private:
#endif // __PARAMETR__PRIVATE_VAL__
    /* */
    T val;

#ifdef __PARAMETR__PRIVATE_VAL__
  public:
#endif // __PARAMETR__PRIVATE_VAL__
    /*
    */
    S();
    
    /*
    */
    S(T Val);
    
    /*
    */
    T& get();
    
    /*
    */
    const T& get() const;
    
    /*
    */
    void set(T newVal);
    
    /*
    */
    S& operator=(const S& arg);
    
    /*
    */
    S& operator=(const T& arg);
  };

  template<typename T>
  S<T>::S()
    : val(T())
  {}

  template<typename T>
  S<T>::S(T Val)
    : val(Val)
  {}

  template<typename T>
  T& S<T>::get()
  {
    return val;
  }

  template<typename T>
  const T& S<T>::get() const
  {
    return val;
  }

  template<typename T>
  void S<T>::set(T newVal)
  {
    val = newVal;
  }

  template<typename T>
  S<T>& S<T>::operator=(const S<T>& arg)
  {
    if (this == &arg)
    {
      return *this;
    }
    val = arg.val;
    return *this;
  }

  template<typename T>
  S<T>& S<T>::operator=(const T& arg)
  {
    val = arg;
    return *this;
  }

  template<typename T>
  istream& operator>>(istream& is, S<T>& reading)
  {
    if (!is) return is;
    is >> reading.get();
    return is;
  }

  template<typename T>
  istream& operator>>(istream& is, S<vector<T>>& reading)
  {
    char ch1;
    T val = T();
    vector<T> temp;
    if (!is) return is;
    cin >> ch1;
    if (ch1 == '{')
    {
      while (true)
      {
        is >> val >> ch1;
        if (is.fail() || (ch1 != ',' && ch1 != '}'))
        {
          error("reading from is is fail");
        }
        temp.push_back(val);
        if (ch1 == '}')
        {
          break;
        }
      }
    }
    else
    {
      error("reading from is is fail:: first symbol isn't \"{\"");
    }
    reading.get() = temp;
    return is;
  }

  template<typename T>
  void read_val(T& val)
  {
    cin >> val;
  }
}

int CH19P707DRILL1_14RunExmple::excute()
{

  S<int> intS(1);
  S<char> charS('a');
  S<double> doubleS(1.0);
  S<string> stringS("alp");
  S<vector<int>> vectorIntS({1,2});

#ifndef __PARAMETR__PRIVATE_VAL__
  cout << "--- print all data using directly calling to val: ---\n"
    << "intS:\n val -> " << intS.val << "\n"
    << "charS:\n val -> " << charS.val << "\n"
    << "doubleS:\n val -> " << doubleS.val << "\n"
    << "stringS:\n val -> " << stringS.val << "\n"
    << "vectorIntS:\n val -> {";
  for (int index = 0; index < vectorIntS.val.size(); ++index)
  {
    cout << " " << vectorIntS.val[index] << ",";
  }
  cout << "\b }\n--- end print ---\n";
#endif // __PARAMETR__PRIVATE_VAL__

  cout << "--- print all data using get(): ---\n"
    << "intS:\n get() -> " << intS.get() << "\n"
    << "charS:\n get() -> " << charS.get() << "\n"
    << "doubleS:\n get() -> " << doubleS.get() << "\n"
    << "stringS:\n get() -> " << stringS.get() << "\n"
    << "vectorIntS:\n get() -> {";
  for (int index = 0; index < vectorIntS.get().size(); ++index)
  {
    cout << " " << vectorIntS.get()[index] << ",";
  }
  cout << "\b }\n--- end print ---";


  intS.set(2);
  charS.set('b');
  doubleS.set(2.0);
  stringS.set("bet");
  vectorIntS.set({ 3,4,5 });

  cout << "--- print all data using set() amd get(): ---\n"
    << "intS:\n get() -> " << intS.get() << "\n"
    << "charS:\n get() -> " << charS.get() << "\n"
    << "doubleS:\n get() -> " << doubleS.get() << "\n"
    << "stringS:\n get() -> " << stringS.get() << "\n"
    << "vectorIntS:\n get() -> {";
  for (int index = 0; index < vectorIntS.get().size(); ++index)
  {
    cout << " " << vectorIntS.get()[index] << ",";
  }
  cout << "\b }\n--- end print ---";


  intS = 3;
  charS = 'c';
  doubleS = 3.0;
  stringS = "bet";
  vectorIntS = {6,7,8};

  cout << "--- print all data using operator= amd get(): ---\n"
    << "intS:\n get() -> " << intS.get() << "\n"
    << "charS:\n get() -> " << charS.get() << "\n"
    << "doubleS:\n get() -> " << doubleS.get() << "\n"
    << "stringS:\n get() -> " << stringS.get() << "\n"
    << "vectorIntS:\n get() -> {";
  for (int index = 0; index < vectorIntS.get().size(); ++index)
  {
    cout << " " << vectorIntS.get()[index] << ",";
  }
  cout << "\b }\n--- end print ---";

  cout << "\nenter intS: ";
  read_val(intS);
  cout << "\nenter charS: ";
  read_val(charS);
  cout << "\nenter doubleS: ";
  read_val(doubleS);
  cout << "\nenter stringS: ";
  read_val(stringS);
  cout << "\nenter vectorIntS: ";
  read_val(vectorIntS);

  cout << "--- print all data using read_val amd get(): ---\n"
    << "intS:\n get() -> " << intS.get() << "\n"
    << "charS:\n get() -> " << charS.get() << "\n"
    << "doubleS:\n get() -> " << doubleS.get() << "\n"
    << "stringS:\n get() -> " << stringS.get() << "\n"
    << "vectorIntS:\n get() -> {";
  for (int index = 0; index < vectorIntS.get().size(); ++index)
  {
    cout << " " << vectorIntS.get()[index] << ",";
  }
  cout << "\b }\n--- end print ---";

	return 0;
}