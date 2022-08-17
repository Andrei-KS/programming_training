/*
Vector_ref.h
*/

/*
* This class is got from:
* Below linking chapters and exercises is linked to the
* book of Programming Principles and Practice Using C++/
* Second Edition/ Bjarne Stroustrup/ 2014/
* ISBN-13: 978-0-321-99278-9
* page 1212
* 
* Basically, Vector_ref simulates a vector of references. You can initialize it with
* references or with pointers:
*   • If an object is passed to Vector_ref as a reference, it is assumed to be
*     owned by the caller who is responsible for its lifetime (e.g., the object is a
*     scoped variable).
*   • If an object is passed to Vector_ref as a pointer, it is assumed to be allocated
*     by new and it is Vector_ref’s responsibility to delete it.
*/

#ifndef __VECTOR_REF_H__
#define __VECTOR_REF_H__

#include "std_lib_facilities.h"

namespace Utility_lib
{
  template<class T> class Vector_ref {
    vector<T*> v;
    vector<T*> owned;
  public:
    Vector_ref()
    {
    }
    Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0);
    
    ~Vector_ref()
    {
      for (int i = 0; i < owned.size(); ++i)
      {
        delete owned[i];
      }
    }

    void push_back(T& s)
    {
      v.push_back(&s);
    }

    void push_back(T* p)
    {
      v.push_back(p);
      owned.push_back(p);
    }

    T& operator[](int i)
    {
      return *v[i];
    }

    const T& operator[](int i) const
    {
      return *v[i];
    }

    int size() const
    {
      return v.size();
    }
  };
}

#endif