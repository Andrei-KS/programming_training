/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/20/2022 15:52:20
	author                                          : Andrei-KS
*/

#include "CH15P547DRILL1_3_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P547DRILL1_3_FLTKRunExmple();

namespace {
  struct Person {
    string name;
    int age;
  };

  ostream& operator<<(ostream& ost, const Person& person)
  {
    return ost << "(" << person.name << ", "
      << person.age << ")";
  }

  istream& operator>>(istream& ist, Person& person)
  {
    ist >> person.name >> person.age;
    return ist;
  }
}

int CH15P547DRILL1_3_FLTKRunExmple::excute()
{
  Person pr1{ "Goofy",63 };
  cout << pr1 << "\n";
  cin >> pr1;
  cout << pr1;
	return 0;
}