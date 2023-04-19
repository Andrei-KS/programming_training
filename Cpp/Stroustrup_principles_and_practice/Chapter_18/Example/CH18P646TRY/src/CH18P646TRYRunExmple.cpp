/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/12/2023 07:38:26
	author                                          : Andrei-KS
*/

#include "CH18P646TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P646TRYRunExmple();

namespace {
  class MyVector {
    /* the size */
    int sz;

    /* a pointer to the elements */
    double* elem;
  public:
    /*  constructor
        @param s - the elements count
    */
    MyVector(int s);

    /* initializer-list constructor */
    MyVector(initializer_list<double> lst);

    /* copy constructor: define copy */
    MyVector(const MyVector& arg);

    /*move constructor*/
    MyVector(MyVector&& arg);

    /* destructor */
    ~MyVector();

    /* copy assignment */
    MyVector& operator=(const MyVector& arg);

    /*move assignment*/
    MyVector& operator=(MyVector&& arg);

    /*return element*/
    double operator[](int n) { return elem[n]; }
  };

  MyVector::MyVector(int s)
    : sz(s)
    , elem{new double[s]}
  {
    for (int i = 0; i < sz; ++i) elem[i] = 0.0;
  }

  MyVector::MyVector(initializer_list<double> lst)
    : sz{ static_cast<int>(lst.size()) }, elem{ new double[sz] }
  {
    copy(lst.begin(), lst.end(), elem);
  }

  MyVector::MyVector(const MyVector& arg)
    :sz{ arg.sz }, elem{ new double[arg.sz] } // allocate elements, then initialize them by copying
  {
    copy(arg.elem, arg.elem + sz, elem);
  }

  MyVector::MyVector(MyVector&& arg)
    :sz{ arg.sz }, elem{ arg.elem } // copy a’s elemand sz
  {
    // make a the empty vector
    arg.sz = 0;
    arg.elem = nullptr;
  }

  MyVector::~MyVector()
  {
    delete[] elem;
  }

  // make this vector a copy of arg
  MyVector& MyVector::operator=(const MyVector& arg)
  {
    // allocate new space
    double* p = new double[arg.sz];
    // copy elements
    copy(arg.elem, arg.elem +sz, p);
    // deallocate old space
    delete[] elem;
    // now we can reset elem
    elem = p;
    sz = arg.sz;
    // return a self - reference
    return *this;
  }
  
  MyVector& MyVector::operator=(MyVector&& arg)
  {
    // deallocate old space
    delete[] elem;
    // copy a’s elemand sz
    elem = arg.elem;
    sz = arg.sz;
    // make a the empty vector
    arg.elem = nullptr;
    arg.sz = 0;
    // return a self - reference
    return *this;
  }
}

int CH18P646TRYRunExmple::excute()
{
  MyVector v(10);
  double x = v[2];
  //v[3] = x; // expression must be modifiable lvalue;
	return 0;
}