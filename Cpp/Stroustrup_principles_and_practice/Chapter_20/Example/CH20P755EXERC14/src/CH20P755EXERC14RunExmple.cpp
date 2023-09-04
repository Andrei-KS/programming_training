/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/28/2023 09:31:42
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC14RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC14RunExmple();

namespace {
  /*
*/
  template<typename Elem>
  struct SLink
  {
    /* successor SLink */
    SLink* succ;

    /* the value */
    Elem val;

    /**/
    SLink(const Elem& v)
      : val{ v }
      , succ{ nullptr }
    {}
  };

  /*
  */
  template<typename Elem>
  class mySList
  {
    // representation and implementation details
  public:


  private:
    /**/
    SLink<Elem>* mFirst;

    /**/
    int mSize;

  public:
    /*
    */
    mySList()
      : mFirst{ nullptr }
      , mSize{ 0 }
    {
    }

    ~mySList()
    {
      while (mFirst != nullptr)
      {
        SLink<Elem>* successorSLink = mFirst->succ;
        delete mFirst;
        mFirst = successorSLink;
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
  class mySList<Elem>::iterator
  {
    /* current SLink */
    SLink<Elem>* curr;
  public:
    /**/
    iterator(SLink<Elem>* p) :curr(p) {}

    /* forward */
    iterator& operator++() { curr = curr->succ; return *this; }

    /* get value (dereference) */
    Elem& operator*() { return curr->val; }

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
  };

  //------------------------
  //  Implimentation
  //------------------------

  // mySList
  template<typename Elem>
  typename mySList<Elem>::iterator mySList<Elem>::begin()
  {
    return iterator(mFirst);
  }

  template<typename Elem>
  typename mySList<Elem>::iterator mySList<Elem>::end()
  {
    return iterator(nullptr);
  }

  template<typename Elem>
  typename mySList<Elem>::iterator mySList<Elem>::insert(iterator p, const Elem& v)
  {
    error("it isn't implemented");
  }

  template<typename Elem>
  typename mySList<Elem>::iterator mySList<Elem>::erase(iterator p)
  {
    error("it isn't implemented");
  }

  template<typename Elem>
  void mySList<Elem>::push_front(const Elem& v)
  {
    if (!mFirst)
    {
      mFirst = new SLink<Elem>(v);
      return;
    }

    SLink<Elem>* newFirst = new SLink<Elem>(v);
    newFirst->succ = mFirst;
    ++mSize;
  }

  template<typename Elem>
  void mySList<Elem>::push_back(const Elem& v)
  {
    if (!mFirst)
    {
      mFirst = new SLink<Elem>(v);
      return;
    }

    SLink<Elem>* last = mFirst;
    while (last->succ)
    {
      last = last->succ;
    }
    last->succ = new SLink<Elem>(v);
    ++mSize;
  }

  template<typename Elem>
  void mySList<Elem>::pop_front()
  {
    if (!mFirst)
    {
      return;
    }

    SLink<Elem>* first = mFirst;
    if (first->succ)
    {
      mFirst = first->succ;
    }
    else
    {
      mFirst = nullptr;
    }

    delete first;
    --mSize;
  }

  template<typename Elem>
  void mySList<Elem>::pop_back()
  {
    if (!mFirst)
    {
      return;
    }

    SLink<Elem>* penultimate = nullptr;
    SLink<Elem>* last = mFirst;
    while (last->succ)
    {
      penultimate = last;
      last = last->succ;
    }

    if (last == mFirst)
    {
      mFirst = nullptr;
    }
    else
    {
      penultimate->succ = nullptr;
    }

    delete last;
    --mSize;
  }

  template<typename Elem>
  Elem& mySList<Elem>::front()
  {
    if (!mFirst)
    {
      error("Range error :: mySList is empty");
    }
    return mFirst->val;
  }

  template<typename Elem>
  Elem& mySList<Elem>::back()
  {
    if (!mFirst)
    {
      error("Range error :: mySList is empty");
    }

    SLink<Elem>* last = mFirst;
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

int CH20P755EXERC14RunExmple::excute()
{
  mySList<int> lst;

  for (int x; cin >> x; )
  {
    lst.push_front(x);
  }

  mySList<int>::iterator p = high(lst.begin(), lst.end());

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