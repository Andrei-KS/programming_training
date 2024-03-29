/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/11/2023 08:46:51
	author                                          : Andrei-KS
*/

#include "CH18P645TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P645TRYRunExmple();

namespace {
  struct X {
    int val;

    void out(const string& s, int nv)
    {
      cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
    }

    X() { out("X()", 0); val = 0; }
    X(int v) { val = v; out("X(int)", v); }
    X(const X& x) { val = x.val; out("X(X&)", x.val); }
    X& operator=(const X& a) { out("X::operator=()", a.val); val = a.val; return *this; }
    ~X() { out("~X()", 0); }
  };

  X glob(2); //a global variable
  X copy(X a) { return a; }
  X copy2(X a) { X aa = a; return aa; }
  X& ref_to(X& a) { return a; }
  X* make(int i) { X a(i); return new X(a); }
  struct XX { X a; X b; };
}

int CH18P645TRYRunExmple::excute()
{
  X loc{ 4 }; //local variable
  X loc2{ loc }; //copy construction
  loc = X{ 5 }; //copy assignment
  loc2 = copy(loc); //call by valueand return
  loc2 = copy2(loc);
  X loc3{ 6 };
  X& r = ref_to(loc); //call by referenceand return
  delete make(7);
  delete make(8);
  vector<X> v(4); //default values
  XX loc4;
  X* p = new X{ 9 }; //an X on the free store
  delete p;
  X* pp = new X[5]; //an array of Xs on the free store
  delete[] pp;
	return 0;
}