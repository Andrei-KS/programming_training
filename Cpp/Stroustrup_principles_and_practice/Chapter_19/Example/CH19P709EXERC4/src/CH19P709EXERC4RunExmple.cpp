/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/11/2023 08:07:13
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC4RunExmple();

namespace {
  template<typename T>
  class MyLink{
  public:
    /**/
    T value;

    /*
    */
    MyLink(const T& v, MyLink* p = nullptr, MyLink* s = nullptr)
      : value{v}
      , prev{p}
      , succ{s}
    {}

    /*
    * insert n before p
    * @return n
    */
    MyLink* insert(MyLink* n);

    /*
    * insert n after p
    * @return n
    */
    MyLink* add(MyLink* n);

    /*
    * remove *p from list
    * @return p’s successor
    */
    MyLink* erase();

    /*
    * find value in list
    * @return nullptr for “not found”
    */
    MyLink* find(const T& s);

    /*
    * find value in list
    * @return nullptr for “not found”
    */
    const MyLink* find(const T& s) const;

    /*
    * move n positions in list
    * @return nullptr for “not found”
    */
    MyLink* advance(int n) const;

    /*
    */
    MyLink* next() const { return succ; }

    /*
    */
    MyLink* previous() const { return prev; }

  private:
    /**/
    MyLink* prev;

    /**/
    MyLink* succ;
  };

  template<typename T>
  MyLink<T>* MyLink<T>::insert(MyLink<T>* n)
  {
    if (n == nullptr)
    {
      return this;
    }

    if (this == nullptr)
    {
      return n;
    }

    n->succ = this;
    if (prev)
    {
      prev->succ = n;
    }
    n->prev = prev;
    prev = n;
    return n;
  }

  template<typename T>
  MyLink<T>* MyLink<T>::add(MyLink<T>* n)
  {
    if (n == nullptr)
    {
      return this;
    }

    if (this == nullptr)
    {
      return n;
    }

    n->prev = this;
    if (succ)
    {
      succ->prev = n;
    }
    n->succ = succ;
    succ = n;
    return n;
  }

  template<typename T>
  MyLink<T>* MyLink<T>::erase()
  {
    if (this == nullptr)
    {
      return nullptr;
    }

    if (succ)
    {
      succ->prev = prev;
    }

    if (prev)
    {
      prev->succ = succ;
    }
    return succ;
  }

  template<typename T>
  MyLink<T>* MyLink<T>::find(const T& s)
  {
    MyLink<T>* p = this;
    while (p)
    {
      if (p->value == value)
      {
        return p;
      }
      p = p->succ;
    }
    return nullptr;
  }

  template<typename T>
  const MyLink<T>* MyLink<T>::find(const T& s) const
  {
    const MyLink<T>* p = this;
    while (p)
    {
      if (p->value == value)
      {
        return p;
      }
      p = p->succ;
    }
    return nullptr;
  }

  template<typename T>
  MyLink<T>* MyLink<T>::advance(int n) const
  {
    if (this == nullptr)
    {
      return nullptr;
    }

    MyLink<T>* p = this;
    if (0 < n)
    {
      while (--n)
      {
        if (p->succ == nullptr)
        {
          return nullptr;
        }
        p = p->succ;
      }
    }
    else if (n < 0)
    {
      while (++n)
      {
        if (p->prev == nullptr)
        {
          return nullptr;
        }
        p = p->prev;
      }
    }
    return p;
  }

  /*
  * insert n befor p
  * @return n
  */
  template<typename T>
  MyLink<T>* insert(MyLink<T>* p, MyLink<T>* n)
  {
    if (n == nullptr)
    {
      return p;
    }

    if (p == nullptr)
    {
      return n;
    }

    return p->insert(n);
  }

  /*
   * insert n after p
   * @return n
   */
  template<typename T>
  MyLink<T>* add(MyLink<T>* p, MyLink<T>* n)
  {
    if (n == nullptr)
    {
      return p;
    }

    if (p == nullptr)
    {
      return n;
    }

    return p->add(n);
  }

  /*
   * remove *p from list
   * @return p’s successor
   */
  template<typename T>
  MyLink<T>* erase(MyLink<T>* p)
  {
    if (p == nullptr)
    {
      return nullptr;
    }

    return p->erase();
  }

  /*
   * find value in list
   * @return nullptr for “not found”
   */
  template<typename T>
  MyLink<T>* find(MyLink<T>* p, const T& value)
  {
    if (p == nullptr)
    {
      return nullptr;
    }

    return p->find(value);
  }

  /*
   * move n positions in list
   * return nullptr for “not found”
   * positive n moves forward, negative backward
   */
  template<typename T>
  MyLink<T>* advance(MyLink<T>* p, int n)
  {
    if (p == nullptr)
    {
      return nullptr;
    }

    return p->advance(n);
  }

  template<typename T>
  void print_all(MyLink<T>* p)
  {
    cout << "{";
    while (p)
    {
      cout << p->value;
      if (p = p->next())
      {
        cout << ", ";
      }
    }
    cout << "}";
  }

  struct God {
    string name;
    string mythology;
    string vehile;
    string wepon;
  };

  ostream& operator<<(ostream& os, const God& god)
  {
    return os << "{ " << god.name
      << ", " << god.mythology
      << ", " << god.vehile
      << ", " << god.wepon << " }";
  }

  MyLink<God>* add_ordered(MyLink<God>* p, MyLink<God>* n)
  {
    if (n == nullptr)
    {
      return p;
    }

    if (p == nullptr)
    {
      return n;
    }

    if (p->value.name > n->value.name)
    {
      return p->insert(n);
    }

    MyLink<God>* head = p;
    while (p->next() && p->next()->value.name < n->value.name)
    {
      p = p->next();
    }
    p->add(n);
    return head;
  }
}

int CH19P709EXERC4RunExmple::excute()
{
  {
    MyLink<string>* norse_gods = new MyLink<string>{ "Thor" };
    norse_gods = insert(norse_gods, new MyLink<string>{ "Odin" });
    add(norse_gods, new MyLink<string>{ "Odin2" });
    norse_gods = insert(norse_gods, new MyLink<string>{ "Zeus" });
    norse_gods = insert(norse_gods, new MyLink<string>{ "Freia" });

    MyLink<string>* greek_gods = new MyLink<string>{ "Hera" };
    greek_gods = insert(greek_gods, new MyLink<string>{ "Athena" });
    greek_gods = insert(greek_gods, new MyLink<string>{ "Mars" });
    greek_gods = insert(greek_gods, new MyLink<string>{ "Poseidon" });

    print_all(norse_gods);
    cout << "\n";
    print_all(greek_gods);
    cout << "\n\n";

    MyLink<string>* p = find<string>(norse_gods, "Zeus");
    if (p) {
      if (p == norse_gods) norse_gods = p->next();
      erase(p);
      greek_gods = insert(greek_gods, p);
    }

    print_all(norse_gods);
    cout << "\n";
    print_all(greek_gods);
    cout << "\n\n";
  }

  {
    MyLink<God>* norse_gods = new MyLink<God>{ God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"} };

    MyLink<God>* greek_gods = new MyLink<God>{ God{"Zeus", "Greek", "", "lightning"} };
    greek_gods = add_ordered(greek_gods, new MyLink<God>{ God{"Athena" , "Greek", "","" } });
    greek_gods = add_ordered(greek_gods, new MyLink<God>{ God{"Hera" , "Greek", "","" } });

    MyLink<God>* gods = new MyLink<God>{ God{"Zeus", "Greek", "", "lightning"} };
    gods = add_ordered(gods, new MyLink<God>{ God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"} });
    gods = add_ordered(gods, new MyLink<God>{ God{"Hapi", "Egyptian", "", ""} });

    print_all(norse_gods);
    cout << "\n";
    print_all(greek_gods);
    cout << "\n";
    print_all(gods);
    cout << "\n\n";
  }


  return 0;
}