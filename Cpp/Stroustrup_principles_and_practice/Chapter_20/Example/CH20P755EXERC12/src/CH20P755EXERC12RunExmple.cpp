/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2023 17:40:46
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC12RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC12RunExmple();

namespace {
  /*
  */
  template<typename Elem>
  struct Link
  {
    /* previous link */
    Link* prev;

    /* successor link */
    Link* succ;

    /* the value */
    Elem val;

    /**/
    Link(const Elem& v)
      : val { v }
      , prev { nullptr }
      , succ { nullptr }
    {}
  };

  /*
  */
  template<typename Elem>
  class myList
  {
    // representation and implementation details
  public:


  private:
    /**/
    Link<Elem>* mFirst;
    
    /* one beyond the last link*/
    Link<Elem>* mLast;

    /**/
    int mSize;

  public:
    /*
    */
    myList()
      : mFirst{ nullptr }
      , mLast{ new Link<Elem>(Elem()) }
      , mSize{ 0 }
    {
      mFirst = mLast;
    }

    ~myList()
    {
      while (mFirst != mLast)
      {
        Link<Elem>* successorLink = mFirst->succ;
        delete mFirst;
        mFirst = successorLink;
      }
      delete mFirst;
    }

    int size() { return mSize; }

    /* meber type: iterator */
    class iterator;

    /*
    * iterator to first element
    */
    iterator begin();

    /*
    * iterator to one beyond last element
    */
    iterator end();

    /*
    * insert v into list after p
    */
    iterator insert(iterator p, const Elem& v);

    /*
    * remove p from the list
    */
    iterator erase(iterator p);

    /*
    * insert v at end
    */
    void push_back(const Elem& v);

    /*
    * insert v at front
    */
    void push_front(const Elem& v);

    /*
    * remove the first element
    */
    void pop_front();

    /*
    * remove the lats element
    */
    void pop_back();

    /*
    * the first element
    */
    Elem& front();

    /*
    * the last element
    */
    Elem& back();
  };

  template<typename Elem> // requires Element<Elem>()
  class myList<Elem>::iterator
  {
    /* current link */
    Link<Elem>* curr;
  public:
    /**/
    iterator(Link<Elem>*p):curr(p){}

    /* forward */
    iterator& operator++() { curr = curr->succ; return *this; }
  
    /* backward */
    iterator& operator--() { curr = curr->prev; return *this; }

    /* get value (dereference) */
    Elem& operator*() { return curr->val; }

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
  };

  //------------------------
  //  Implimentation
  //------------------------

  // myList
  template<typename Elem>
  typename myList<Elem>::iterator myList<Elem>::begin()
  {
    return iterator(mFirst);
  }

  template<typename Elem>
  typename myList<Elem>::iterator myList<Elem>::end()
  {
    return iterator(mLast);
  }

  template<typename Elem>
  typename myList<Elem>::iterator myList<Elem>::insert(iterator p, const Elem& v)
  {
    error("it isn't implemented");
  }

  template<typename Elem>
  typename myList<Elem>::iterator myList<Elem>::erase(iterator p)
  {
    error("it isn't implemented");
  }

  template<typename Elem>
  void myList<Elem>::push_front(const Elem& v)
  {
    mFirst->prev = new Link<Elem>(v);
    mFirst->prev->succ = mFirst;
    mFirst = mFirst->prev;
    ++mSize;
  }

  template<typename Elem>
  void myList<Elem>::push_back(const Elem& v)
  {
    mLast->val = v;
    mLast->succ = new Link<Elem>(v);
    mLast->succ->prev = mLast;
    mLast = mLast->succ;
    ++mSize;
  }

  template<typename Elem>
  void myList<Elem>::pop_front()
  {
    Link<Elem>* first = mFirst;
    mFirst = first->succ;
    delete first;
    --mSize;
  }

  template<typename Elem>
  void myList<Elem>::pop_back()
  {
    if (mLast == mFirst)
    {
      return;
    }
    
    Link<Elem>* prev = mLast->prev
    if (prev->prev)
    {
      mLast->prev = prev->prev;
      prev->prev->succ = mLast;
    }
    else
    {
      mFirst = mLast;
    }

    delete prev;
    --mSize;
  }

  template<typename Elem>
  Elem& myList<Elem>::front()
  {
    if (mLast == mFirst)
    {
      error("Range error :: myList is empty");
    }
    return mFirst->val;
  }

  template<typename Elem>
  Elem& myList<Elem>::back()
  {
    if (mLast == mFirst)
    {
      error("Range error :: myList is empty");
    }
    return mLast->prev->val;
  }

  /* @return an iterator to the element in [first,last) that has the highest value */
  template<typename Iter> //  requires Input_Iter<Iter>()
  Iter high(Iter first, Iter last)
  {
    if (first == last)
    {
      return last;
    }

    Iter high = first;
    for (Iter p = first; p != last; ++p)
    {
      if (*high < *p)
      {
        high = p;
      }
    }

    return high;
  }
}

int CH20P755EXERC12RunExmple::excute()
{
  myList<int> lst;

  for (int x; cin >> x; )
  {
    lst.push_front(x);
  }

  myList<int>::iterator p = high(lst.begin(), lst.end());

  if (p != lst.end())
  {
    cout << "the highest value was " << *p << '\n';
  }
  else
  {
    cout << "the list is empty\n";
  }
	return 0;
}