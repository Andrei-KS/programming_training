/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/22/2023 10:09:52
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC8RunExmple();

namespace {
  template<typename T>
  class myAllocator {
  public:
    /* allocate space for n objects of type T
    * @param n - object amount of type T
    * @return the pointer on allocated space
    */
    T* allocate(int n);

    /* deallocate n objects of type T starting at p
    */
    void deallocate(T* p, int n);

    /* construct a T with the value v in p
    */
    void construct(T* p, const T& v);

    /* destroy the T in p
    */
    void destroy(T* p);

  private:
    void report(T* p, std::size_t n, bool alloc = true) const
    {
      std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
        << " bytes at " << std::hex << std::showbase
        << reinterpret_cast<void*>(p) << std::dec << '\n';
    }
  };

  template<typename T>
  T* myAllocator<T>::allocate(int n)
  {
    T* ptr = static_cast<T*>(malloc(sizeof(T) * n));
    if (ptr)
    {
      report(ptr, n);
      return ptr;
    }
    throw bad_alloc();
  }

  template<typename T>
  void myAllocator<T>::deallocate(T* p, int n)
  {
    report(p, n, false);
    free(p);
  }

  template<typename T>
  void myAllocator<T>::construct(T* p, const T& v)
  {
    new(p)T{ v };
  }

  template<typename T>
  void  myAllocator<T>::destroy(T* p)
  {
    p->~T();
  }

  template<class T, class U>
  bool operator==(const myAllocator <T>&, const myAllocator <U>&) { return true; }

  template<class T, class U>
  bool operator!=(const myAllocator <T>&, const myAllocator <U>&) { return false; }

  template<typename T, typename A = allocator<T>>
  class myVector {
    /* use allocate to handle memory for elements */
    A alloc;

    /* */
    int sz;

    /* */
    T* elem;

    /* */
    int space;

  public:
    /*
    */
    myVector()
      : sz{ 0 }
      , elem{ nullptr }
      , space{ 0 }
    {}

    /*
    */
    explicit myVector(int s)
      : sz{ s }
      , elem{ alloc.allocate(s) }
      , space{ s }
    {
      for (int i = 0; i < sz; ++i)
      {
        alloc.construct(&elem[i], T());
      }
    }

    /* copy constructor
    */
    myVector(const myVector& arg)
      : sz{ arg.sz }
      , elem{ alloc.allocate(arg.sz) }
      , space{ arg.sz }
    {
      for (int i = 0; i < sz; ++i)
      {
        alloc.construct(&elem[i], arg[i]);
      }
    }

    /* copy assignment
    */
    myVector& operator=(const myVector& arg)
    {
      // self - assignment, no work needed
      if (this == &arg)
      {
        return *this;
      }

      if (arg.sz <= space)
      {
        for (int i = 0; i < arg.sz; ++i)
        {
          elem[i] = arg.elem[i];
        }
        for (int i = sz; i < arg.sz; ++i)
        {
          alloc.destroy(&elem[i]);
        }
        sz = arg.sz;
        return *this;
      }

      // allocate new space
      unique_ptr<T> p(alloc.allocate(arg.sz));
      // copy
      for (int i = 0; i < arg.sz; ++i)
      {
        alloc.construct(&(p.get()[i]), arg.elem[i]);
      }
      alloc.deallocate(elem, space);

      elem = p.release();
      space = sz = arg.sz;
      return *this;
    }

    /* move constructor
    */
    myVector(myVector&& arg)
      : sz{ arg.sz }
      , elem{ arg.elem }
      , space{ arg.space }
    {
      swap(alloc, arg.alloc);
      arg.space = arg.sz = 0;
      arg.elem = nullptr;
    }

    /* move assignment
    */
    myVector& operator=(myVector&& arg)
    {
      alloc.deallocate(elem, space);
      elem = arg.elem;
      sz = arg.sz;
      space = arg.space;
      swap(alloc, arg.alloc);

      arg.elem = nullptr;
      arg.space = arg.sz = 0;

      return *this;
    }

    /* destructor
    */
    ~myVector() { alloc.deallocate(elem, space); }


    /* access: return reference
    */
    T& operator[](int n) { return elem[n]; }

    /*
    */
    T& at(int n);

    /*
    */
    const T& operator[](int n) const { return elem[n]; }

    /*
    */
    const T& at(int n) const;

    /* the current size
    */
    int size() const { return sz; }

    /*
    */
    int capacity() const { return space; }


    /*
    */
    void resize(int newsize, T val = T());

    /*
    */
    void push_back(const T& val);

    /*
    */
    void reserve(int newalloc);

    /*
    */
    void printAll();
  };

  template<typename T, typename A>
  T& myVector<T, A>::at(int n)
  {
    if (n < 0 || sz <= 0)
    {
      throw out_of_range();
    }
    return elem[n];
  }

  template<typename T, typename A>
  const T& myVector<T, A>::at(int n) const
  {
    if (n < 0 || sz <= 0)
    {
      throw out_of_range();
    }
    return elem[n];
  }

  template<typename T, typename A>
  void myVector<T, A>::reserve(int newalloc)
  {
    if (newalloc <= space)
    {
      return;
    }

    // allocate new space
    unique_ptr<T> p(alloc.allocate(newalloc));
    // copy
    for (int i = 0; i < sz; ++i)
    {
      alloc.construct(&(p.get()[i]), elem[i]);
    }
    // destroy
    for (int i = 0; i < sz; ++i)
    {
      alloc.destroy(&elem[i]);
    }

    elem = p.release();
    space = newalloc;
  }

  template<typename T, typename A>
  void myVector<T, A>::push_back(const T& val)
  {
    if (space == 0)
    {
      reserve(8);
    }
    else if (sz == space)
    {
      reserve(2 * space);
    }

    alloc.construct(&elem[sz], val);
    ++sz;
  }

  template< typename T, typename A>
  void myVector<T, A>::resize(int newsize, T val)
  {
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
    {
      alloc.construct(&elem[i], val);
    }
    for (int i = newsize; i < sz; ++i)
    {
      alloc.destroy(&elem[i]);
    }
    sz = newsize;
  }
  template< typename T, typename A>
  void myVector<T, A>::printAll()
  {
    cout << "initialized\n";
    for (int index = 0; index < sz; ++index)
    {
      cout << elem[index] << " ";
    }
    cout << "\nnot initialized\n";
    for (int index = sz; index < space; ++index)
    {
      cout << elem[index] << " ";
    }
    cout << "\n";
  }
}

int CH19P709EXERC8RunExmple::excute()
{
  {
    myVector<double> mv(10);
    mv.printAll();
    for (int i = 0; i < mv.size(); ++i)
    {
      mv[i] = i;
    }
    myVector<double> mv2(move(mv));
    mv2.resize(5);
    mv = move(mv2);
    mv2 = mv;
    mv.printAll();
    mv2.printAll();
  }

  {
    myVector<double,myAllocator<double>> mv(10);
    for (int i = 0; i < mv.size(); ++i)
    {
      mv[i] = i;
    }
    myVector<double, myAllocator<double>> mv2(move(mv));
    mv2.resize(5);
    mv = move(mv2);
    mv2 = mv;
    mv.printAll();
    mv2.printAll();
  }

  return 0;
}