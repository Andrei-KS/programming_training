/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/05/2023 17:09:38
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC18RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC18RunExmple();

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
#ifdef DEBUG_BUILD
    void report(T* p, std::size_t n, bool alloc = true) const
    {
      std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
        << " bytes at " << std::hex << std::showbase
        << reinterpret_cast<void*>(p) << std::dec << '\n';
    }
#endif //DEBUG_BUILD
  };

  template<typename T>
  T* myAllocator<T>::allocate(int n)
  {
    T* ptr = static_cast<T*>(malloc(sizeof(T) * n));
    if (ptr)
    {
#ifdef DEBUG_BUILD
      report(ptr, n);
#endif //DEBUG_BUILD
      return ptr;
    }
    throw bad_alloc();
  }

  template<typename T>
  void myAllocator<T>::deallocate(T* p, int n)
  {
#ifdef DEBUG_BUILD
    report(p, n, false);
#endif //DEBUG_BUILD
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
  public:
    using allocator_type = A;
    using size_type = size_t;
    using value_type = T;
    using pointer_type = T*;
    using reference_type = T&;
    using const_reference_type = const T&;
    class iterator;

  private:
    /* use allocate to handle memory for elements */
    allocator_type alloc;

    /* */
    size_type sz;

    /* */
    pointer_type elem;

    /* */
    size_type space;

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
    explicit myVector(size_type s)
      : sz{ s }
      , elem{ alloc.allocate(s) }
      , space{ s }
    {
      for (size_type i = 0; i < sz; ++i)
      {
        alloc.construct(&elem[i], value_type());
      }
    }

    /*
    * copy constructor
    */
    myVector(const myVector& arg)
      : sz{ arg.sz }
      , elem{ alloc.allocate(arg.sz) }
      , space{ arg.sz }
    {
      for (size_type i = 0; i < sz; ++i)
      {
        alloc.construct(&elem[i], arg[i]);
      }
    }

    /*
    * copy assignment
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
        for (size_type i = 0; i < arg.sz; ++i)
        {
          elem[i] = arg.elem[i];
        }
        for (size_type i = arg.sz; i < sz; ++i)
        {
          alloc.destroy(&elem[i]);
        }
        sz = arg.sz;
        return *this;
      }

      // allocate new space
      unique_ptr<value_type> p(alloc.allocate(arg.sz));
      // copy
      for (size_type i = 0; i < arg.sz; ++i)
      {
        alloc.construct(&(p.get()[i]), arg.elem[i]);
      }
      alloc.deallocate(elem, space);

      elem = p.release();
      space = sz = arg.sz;
      return *this;
    }

    /*
    * move constructor
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

    /*
    * move assignment
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

    /*
    * destructor
    */
    ~myVector() { alloc.deallocate(elem, space); }


    /*
    * access: return reference
    */
    reference_type operator[](size_type n) { return elem[n]; }

    /*
    */
    reference_type at(size_type n);

    /*
    */
    const_reference_type operator[](size_type n) const { return elem[n]; }

    /*
    */
    const_reference_type at(size_type n) const;

    /*
    * the current size
    */
    size_type size() const { return sz; }

    /*
    */
    size_type capacity() const { return space; }


    /*
    */
    void resize(size_type newsize, value_type val = value_type());

    /*
    */
    void push_back(const_reference_type val);

    /*
    */
    void push_front(const_reference_type val);

    /*
    */
    void reserve(size_type newalloc);

    /*
    */
    void printAll();

    /*
    */
    template<typename T, typename A> friend istream& operator>>(istream& os, myVector<T, A>& container);

    /*
    */
    template<typename T, typename A> friend ostream& operator<<(ostream& os, const myVector<T, A>& container);

    /*
    */
    iterator begin();

    /*
    */
    iterator end();
  };

  /*
*/
  template<typename T, typename A>
  class myVector<T, A>::iterator
  {
    /**/
    pointer_type mpCurrElem;

    /**/
    pointer_type mpBeginElem;

    /**/
    pointer_type mpEndElem;

  public:
    /*
    */
    iterator(pointer_type pElem, pointer_type pBegin, pointer_type pEnd);

    /*
    */
    iterator(const iterator& other);

    /*
    */
    reference_type operator*();

    /*
    */
    pointer_type operator->();

    /*
    * forward
    */
    iterator& operator++();
    iterator& operator+=(size_type n);


    /*
    */
    template<typename T, typename A> friend iterator operator+(const typename myVector<T, A>::iterator& iter, size_type n);
    template<typename T, typename A> friend iterator operator+(size_type n, const typename myVector<T, A>::iterator& iter);

    /*
    * backward
    */
    iterator& operator--();
    iterator& operator-=(size_type n);

    /*
    */
    template<typename T, typename A> friend iterator operator-(const typename myVector<T, A>::iterator& iter, size_type n);
    template<typename T, typename A> friend size_type operator-(const typename myVector<T, A>::iterator& leftIter, const typename myVector<T, A>::iterator& rightIter);

    /*
    * relational operators
    */
    bool operator==(const iterator& other);
    bool operator!=(const iterator& other);
    bool operator<(const iterator& other);
    bool operator>(const iterator& other);
    bool operator<=(const iterator& other);
    bool operator>=(const iterator& other);

    /*
    */
    reference_type operator[](size_type n);
    const_reference_type operator[](size_type n) const;
  };

  template<typename T, typename A>
  T& myVector<T, A>::at(size_type n)
  {
    if (n < 0 || sz <= 0)
    {
      throw out_of_range();
    }
    return elem[n];
  }

  template<typename T, typename A>
  const T& myVector<T, A>::at(size_type n) const
  {
    if (n < 0 || sz <= 0)
    {
      throw out_of_range();
    }
    return elem[n];
  }

  template<typename T, typename A>
  void myVector<T, A>::reserve(size_type newalloc)
  {
    // never decrease allocation
    if (newalloc <= space)
    {
      return;
    }

    // allocate new space
    unique_ptr<value_type> p(alloc.allocate(newalloc));
    // copy
    for (size_type i = 0; i < sz; ++i)
    {
      alloc.construct(&(p.get()[i]), elem[i]);
    }

    // destroy
    for (size_type i = 0; i < sz; ++i)
    {
      alloc.destroy(&elem[i]);
    }

    // deallocate old space
    alloc.deallocate(elem, space);

    elem = p.release();
    space = newalloc;
  }

  template<typename T, typename A>
  void myVector<T, A>::push_back(const_reference_type val)
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

  template<typename T, typename A>
  void myVector<T, A>::push_front(const_reference_type val)
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

    int lastIndex = sz - 1;
    for (size_type i = 0; i < sz; ++i)
    {
      swap(elem[lastIndex], elem[i]);
    }
  }

  template< typename T, typename A>
  void myVector<T, A>::resize(size_type newsize, value_type val)
  {
    reserve(newsize);
    for (size_type i = sz; i < newsize; ++i)
    {
      alloc.construct(&elem[i], val);
    }
    for (size_type i = newsize; i < sz; ++i)
    {
      alloc.destroy(&elem[i]);
    }
    sz = newsize;
  }
  template< typename T, typename A>
  void myVector<T, A>::printAll()
  {
    cout << "initialized\n";
    for (size_type index = 0; index < sz; ++index)
    {
      cout << elem[index] << " ";
    }
    cout << "\nnot initialized\n";
    for (size_type index = sz; index < space; ++index)
    {
      cout << elem[index] << " ";
    }
    cout << "\n";
  }

  template<typename T, typename A>
  ostream& operator<<(ostream& os, const myVector<T, A>& container)
  {
    for (myVector<T, A>::size_type index = 0; index < container.sz; ++index)
    {
      cout << container.elem[index] << " ";
    }
    return os;
  }

  template<typename T, typename A>
  istream& operator>>(istream& is, myVector<T, A>& container)
  {
    T value;
    is >> value;
    container.push_back(value);
    return is;
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator myVector<T, A>::begin()
  {
    return iterator(elem, elem, elem + sz);
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator myVector<T, A>::end()
  {
    return iterator(elem + sz, elem, elem + sz);
  }

  template<typename T, typename A>
  myVector<T, A>::iterator::iterator(pointer_type pElem, pointer_type pBegin, pointer_type pEnd)
    : mpCurrElem{ pElem }
    , mpBeginElem{ pBegin }
    , mpEndElem{ pEnd }
  {
  }

  template<typename T, typename A>
  myVector<T, A>::iterator::iterator(const iterator& other)
    : mpCurrElem{ other.pElem }
    , mpBeginElem{ other.pBegin }
    , mpEndElem{ other.pEnd }
  {
  }

  template<typename T, typename A>
  typename myVector<T, A>::reference_type  myVector<T, A>::iterator::operator*()
  {
    if (mpCurrElem < mpBeginElem || mpCurrElem >= mpEndElem)
    {
      throw out_of_range((string(__func__) + string(" :: out of range")).c_str());
    }

    return *mpCurrElem;
  }

  template<typename T, typename A>
  typename myVector<T, A>::pointer_type  myVector<T, A>::iterator::operator->()
  {
    if (mpCurrElem < mpBeginElem || mpCurrElem >= mpEndElem)
    {
      throw out_of_range((string(__func__) + string(" :: out of range")).c_str());
    }

    return mpCurrElem;
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator& myVector<T, A>::iterator::operator++()
  {
    ++mpCurrElem;
    return *this;
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator& myVector<T, A>::iterator::operator+=(size_type n)
  {
    mpCurrElem = mpCurrElem + n;
    return *this;
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator& myVector<T, A>::iterator::operator--()
  {
    --mpCurrElem;
    return *this;
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator& myVector<T, A>::iterator::operator-=(size_type n)
  {
    mpCurrElem = mpCurrElem - n;
    return *this;
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator operator+(const typename myVector<T, A>::iterator& iter, typename myVector<T, A>::size_type n)
  {
    return iterator(iter.mpCurrElem + n, iter.mpBeginElem, iter.mpEndElem);
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator operator+(typename myVector<T, A>::size_type n, const typename myVector<T, A>::iterator& iter)
  {
    return iterator(iter.mpCurrElem + n, iter.mpBeginElem, iter.mpEndElem);
  }

  template<typename T, typename A>
  typename myVector<T, A>::iterator operator-(const typename myVector<T, A>::iterator& iter, typename myVector<T, A>::size_type n)
  {
    return iterator(iter.mpCurrElem - n, iter.mpBeginElem, iter.mpEndElem);
  }

  template<typename T, typename A>
  typename myVector<T, A>::size_type operator-(const typename myVector<T, A>::iterator& leftIter, const typename myVector<T, A>::iterator& rightIter)
  {
    return leftIter - rightIter;
  }

  template<typename T, typename A>
  bool myVector<T, A>::iterator::operator== (const iterator & other)
  {
    return mpCurrElem == other.mpCurrElem && mpBeginElem == other.mpBeginElem && mpEndElem == other.mpEndElem;
  }
  
  template<typename T, typename A>
  bool myVector<T, A>::iterator::operator!=(const iterator& other)
  {
    return !(*this == other);
  }
  
  template<typename T, typename A>
  bool myVector<T, A>::iterator::operator<(const iterator& other)
  {
    return mpCurrElem < other.mpCurrElem;
  }
  
  template<typename T, typename A>
  bool myVector<T, A>::iterator::operator>(const iterator& other)
  {
    return mpCurrElem > other;
  }
  
  template<typename T, typename A>
  bool myVector<T, A>::iterator::operator<=(const iterator& other)
  {
    return !(*this > other);
  }
  
  template<typename T, typename A>
  bool myVector<T, A>::iterator::operator>=(const iterator& other)
  {
    return !(*this < other);
  }

  template<typename T, typename A>
  typename myVector<T, A>::reference_type myVector<T, A>::iterator::operator[](size_type n)
  {
    pointer_type pElem = mpBeginElem + n;
    if (pElem >= mpEndElem)
    {
      throw out_of_range((string(__func__) + string(" :: out of range")).c_str());
    }
    return *pElem;
  }

  template<typename T, typename A>
  typename myVector<T, A>::const_reference_type myVector<T, A>::iterator::operator[](size_type n) const
  {
    pointer_type pElem = mpBeginElem + n;
    if (pElem >= mpEndElem)
    {
      throw out_of_range((string(__func__) + string(" :: out of range")).c_str());
    }
    return *pElem;
  }
}

int CH20P755EXERC18RunExmple::excute()
{
  myVector<double, myAllocator<double>> mv(10);
  for (int i = 0; i < mv.size(); ++i)
  {
    mv[i] = i;
  }
  mv.printAll();

  cout << "iterator test\n";
  for (auto it = mv.begin(); it != mv.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << "\n";
  auto it = mv.begin();
  try
  {
    cout << "test it[2]\n";
    cout << "it[2] :: " << it[2] << "\n";
  }
  catch (exception e)
  {
    cout << e.what() << "\n";
  }
  
  try
  {
    cout << "test it[mv.size()+2]\n";
    cout << "it[mv.size()+2] :: " << it[mv.size() + 2] << "\n";
  }
  catch (exception e)
  {
    cout << e.what() << "\n";
  }

  try
  {
    cout << "test mv.begin()\n";
    cout << "mv.begin() :: " << *(mv.begin()) << "\n";
  }
  catch (exception e)
  {
    cout << e.what() << "\n";
  }

  try
  {
    cout << "test mv.end()\n";
    cout << "mv.end() :: " << *(mv.end()) << "\n";
  }
  catch (exception e)
  {
    cout << e.what() << "\n";
  }
  cout << "\n";

  cout << "\n" << mv << "\n";
  cin >> mv;

  mv.printAll();
	return 0;
}