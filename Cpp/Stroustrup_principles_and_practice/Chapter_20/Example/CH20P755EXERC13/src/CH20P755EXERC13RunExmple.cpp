/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/28/2023 02:38:18
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC13RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC13RunExmple();

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
      : val{ v }
      , prev{ nullptr }
      , succ{ nullptr }
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

    /**/
    int mSize;

  public:
    /*
    */
    myList()
      : mFirst{ nullptr }
      , mSize{ 0 }
    {
    }

    ~myList()
    {
      while (mFirst != nullptr)
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
    iterator(Link<Elem>* p) :curr(p) {}

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
    return iterator(nullptr);
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
    if (!mFirst)
    {
      mFirst = new Link<Elem>(v);
      return;
    }

    mFirst->prev = new Link<Elem>(v);
    mFirst->prev->succ = mFirst;
    mFirst = mFirst->prev;
    ++mSize;
  }

  template<typename Elem>
  void myList<Elem>::push_back(const Elem& v)
  {
    if (!mFirst)
    {
      mFirst = new Link<Elem>(v);
      return;
    }

    Link<Elem>* last = mFirst;
    while (last->succ)
    {
      last = last->succ;
    }
    last->succ = new Link<Elem>(v);
    last->succ->prev = last;
    ++mSize;
  }

  template<typename Elem>
  void myList<Elem>::pop_front()
  {
    if (!mFirst)
    {
      return;
    }

    Link<Elem>* first = mFirst;
    if (first->succ)
    {
      mFirst = first->succ;
      mFirst->prev = nullptr;
    }
    else
    {
      mFirst = nullptr;
    }

    delete first;
    --mSize;
  }

  template<typename Elem>
  void myList<Elem>::pop_back()
  {
    if (!mFirst)
    {
      return;
    }

    Link<Elem>* last = mFirst;
    while (last->succ)
    {
      last = last->succ;
    }

    if (last == mFirst)
    {
      mFirst = nullptr;
    }
    else
    {
      last->prev->succ = nullptr;
    }

    delete last;
    --mSize;
  }

  template<typename Elem>
  Elem& myList<Elem>::front()
  {
    if (!mFirst)
    {
      error("Range error :: myList is empty");
    }
    return mFirst->val;
  }

  template<typename Elem>
  Elem& myList<Elem>::back()
  {
    if (!mFirst)
    {
      error("Range error :: myList is empty");
    }

    Link<Elem>* last = mFirst;
    while (last->succ)
    {
      last = last->succ;
    }

    return last->val;
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

int CH20P755EXERC13RunExmple::excute()
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