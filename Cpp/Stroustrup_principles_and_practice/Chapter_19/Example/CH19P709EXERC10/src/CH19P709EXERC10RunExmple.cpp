/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 06/22/2023 08:59:22
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC10RunExmple.h"
#include "std_lib_facilities.h"
#include <memory>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC10RunExmple();

namespace {

#ifdef DEBUG_BUILD
  template<typename T> class myUnique_ptr;

  class myUnique_ptrIdIndex {
    static int value;
    template<typename T> friend class myUnique_ptr;
  };

  int myUnique_ptrIdIndex::value = 0;
#endif // DEBUGEBUG

  /*
  */
  template<typename T>
  class myUnique_ptr {
  public:
    /*
    */
    myUnique_ptr() noexcept;

    /*
    */
    myUnique_ptr(T* ptr) noexcept;
    
    /*
    */
    myUnique_ptr(const myUnique_ptr& ) = delete;

    /*
    */
    myUnique_ptr& operator=(const myUnique_ptr& ) = delete;

    /*
    */
    myUnique_ptr(myUnique_ptr&& other) noexcept;

    /*
    */
    myUnique_ptr& operator=(myUnique_ptr&& other) noexcept;

    /*
    */
    ~myUnique_ptr() noexcept;
    
    /*
    */
    T* operator->();

    /*
    */
    T& operator*();

    /*
    */
    T* release() noexcept;

    /*
    */
    void reset(T* ptr = nullptr) noexcept;

  private:
#ifdef DEBUG_BUILD
    /*
    */
    void log(string message)
    {
      cout << "myUnique_ptr[" << id << "]<" << typeid(*obj).name() << "> executed : " << message << "\n";
      const int firstColumWidth = 10;
      cout << setiosflags(ios::left)  << setw(firstColumWidth) << "Data info\n"
        << setw(firstColumWidth) << "Id" << ": " << id << "\n"
        << setw(firstColumWidth) << "Typename" << ": " << typeid(*obj).name() << "\n"
        << setw(firstColumWidth) << "Address" << ": " << obj << "\n";
      cout << "\n";
    }

    int id;
#endif // DEBUGEBUG

    /**/
    T* obj;
    
  };

  template<typename T>
  myUnique_ptr<T>::myUnique_ptr() noexcept
    : obj{nullptr}
#ifdef DEBUG_BUILD
    , id{ myUnique_ptrIdIndex::value++ }
#endif // DEBUGEBUG
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  myUnique_ptr<T>::myUnique_ptr(T* ptr) noexcept
    : obj{ptr}
#ifdef DEBUG_BUILD
    , id{ myUnique_ptrIdIndex::value++ }
#endif // DEBUGEBUG
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  myUnique_ptr<T>::myUnique_ptr(myUnique_ptr&& other) noexcept
    : obj{other.release()}
#ifdef DEBUG_BUILD
    , id{ myUnique_ptrIdIndex::value++ }
#endif // DEBUGEBUG
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  myUnique_ptr<T>& myUnique_ptr<T>::operator=(myUnique_ptr&& other) noexcept
  {
    if (&other != this)
    {
      reset(other.release());
    }
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return *this;
  }


  template<typename T>
  myUnique_ptr<T>::~myUnique_ptr() noexcept
  {
    if (obj)
    {
      delete obj;
      obj = nullptr;
    }
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  T* myUnique_ptr<T>::release() noexcept
  {
    T* old = obj;
    obj = nullptr;
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return old;
  }

  template<typename T>
  void myUnique_ptr<T>::reset(T* ptr = nullptr) noexcept
  {
    T* old = obj;
    obj = ptr;
    if (old)
    {
      delete old;
    }
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  T* myUnique_ptr<T>::operator->()
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return obj;
  }

  template<typename T>
  T& myUnique_ptr<T>::operator*()
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return *obj;
  }

  class Test {
  public:
    int value = 1;
    void foo()
    {
      cout << "\nfoo()\n";
    }
  };

}

int CH19P709EXERC10RunExmple::excute()
{
  myUnique_ptr<int> uptri0(new int(5));
  myUnique_ptr<int> uptri1;
  uptri1 = move(uptri0);

  myUnique_ptr<double> uptrd0(new double(1.0));
  uptrd0.reset(new double(2.0));
  double* ptrd = uptrd0.release();
  delete ptrd;
  //unique_ptr<int[]> ptr(new int[] {1, 2, 3});

  myUnique_ptr<Test> uptrt(new Test);
  uptrt->foo();
  (*uptrt).foo();
	return 0;
}