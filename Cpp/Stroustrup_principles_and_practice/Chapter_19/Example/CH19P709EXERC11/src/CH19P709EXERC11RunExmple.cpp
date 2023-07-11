/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/11/2023 12:01:18
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC11RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC11RunExmple();

namespace {
#ifdef DEBUG_BUILD
  template<typename T> class counted_ptr;

  class counted_ptrIdIndex {
    static int value;
    template<typename T> friend class counted_ptr;
  };

  int counted_ptrIdIndex::value = 0;
#endif // DEBUGEBUG

  /*
  */
  template<typename T>
  class counted_ptr
  {
  public:
    /*
    */
    counted_ptr() noexcept;

    /*
    */
    counted_ptr(T* ptr) noexcept;

    /*
    */
    counted_ptr(const counted_ptr& other) noexcept;

    /*
    */
    counted_ptr& operator=(const counted_ptr& other) noexcept;

    /*
    */
    counted_ptr(counted_ptr&& other) noexcept;

    /*
    */
    counted_ptr& operator=(counted_ptr&& other) noexcept;

    /*
    */
    ~counted_ptr() noexcept;

    /*
    */
    T* operator->() noexcept;

    /*
    */
    T& operator*() noexcept;

    /*
    */
    void reset(T* ptr = nullptr) noexcept;

    /*
    */
    int use_count() noexcept;

  private:
#ifdef DEBUG_BUILD
    /*
    */
    void log(string message)
    {
      cout << "counted_ptr[" << id << "] executed : " << message << "\n";
      const int firstColumWidth = 10;
      cout << setiosflags(ios::left) << setw(firstColumWidth) << "Data info\n"
        << setw(firstColumWidth) << "Id" << ": " << id << "\n"
        << setw(firstColumWidth) << "Typename" << ": " << typeid(T).name() << "\n"
        << setw(firstColumWidth) << "Counter" << ": " << (counter? *counter : 0) << "\n"
        << setw(firstColumWidth) << "Address" << ": " << m_ptr << "\n"
        << "\n";
    }

    int id;
#endif // DEBUGEBUG

    void destroy();

    /**/
    T* m_ptr;

    /**/
    int* counter;
  };

  template<typename T>
  counted_ptr<T>::counted_ptr() noexcept
    : m_ptr{nullptr}
    , counter{nullptr}
#ifdef DEBUG_BUILD
    , id{ counted_ptrIdIndex::value++ }
#endif // DEBUGEBUG
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  counted_ptr<T>::counted_ptr(T* ptr) noexcept
    : m_ptr{ ptr }
    , counter{ new int(1)}
#ifdef DEBUG_BUILD
    , id{ counted_ptrIdIndex::value++ }
#endif // DEBUGEBUG
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  counted_ptr<T>::counted_ptr(const counted_ptr& other) noexcept
    : m_ptr{ other.m_ptr }
    , counter{ other.counter }
#ifdef DEBUG_BUILD
    , id{ counted_ptrIdIndex::value++ }
#endif // DEBUGEBUG
  {
    if (m_ptr)
    {
      ++(*counter);
    }
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr& other) noexcept
  {
    if (this != &other)
    {
      destroy();

      m_ptr = other.m_ptr;
      counter = other.counter;
      if (m_ptr)
      {
        ++(*counter);
      }
    }
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return *this;
  }

  template<typename T>
  counted_ptr<T>::counted_ptr(counted_ptr&& other) noexcept
    : m_ptr{ other.m_ptr }
    , counter{ other.counter }
#ifdef DEBUG_BUILD
    , id{ counted_ptrIdIndex::value++ }
#endif // DEBUGEBUG
  {
    other.m_ptr = nullptr;
    other.counter = nullptr;
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr&& other) noexcept
  {
    if (this != &other)
    {
      destroy();

      m_ptr = other.m_ptr;
      counter = other.counter;
      other.m_ptr = nullptr;
      other.counter = nullptr;
    }
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return *this;
  }

  template<typename T>
  counted_ptr<T>::~counted_ptr() noexcept
  {
    destroy();

#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  T* counted_ptr<T>::operator->() noexcept
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return m_ptr;
  }

  template<typename T>
  T& counted_ptr<T>::operator*() noexcept
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return *m_ptr;
  }

  template<typename T>
  void counted_ptr<T>::reset(T* ptr = nullptr) noexcept
  {
    destroy();

    m_ptr = ptr;
    if (m_ptr)
    {
      counter = new int(1);
    }
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
  }

  template<typename T>
  int counted_ptr<T>::use_count() noexcept
  {
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
    return (counter ? *counter : 0);
  }

  template<typename T>
  void counted_ptr<T>::destroy()
  {
    if (m_ptr)
    {
      --(*counter);
      if (!(*counter))
      {
        delete m_ptr;
        delete counter;
      }
    }

    m_ptr = nullptr;
    counter = nullptr;
#ifdef DEBUG_BUILD
    log(__FUNCTION__);
#endif // DEBUGEBUG
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

int CH19P709EXERC11RunExmple::excute()
{
  int probIndex = 0;
  counted_ptr<int> cptri0;
  counted_ptr<int> cptri1(new int(25));
  cout << "\n--- Prob[" << probIndex++ << "] ---\n"
    << "cptri1 value : " << *cptri1 << "\n"
    << "cptri1 use_count : " << cptri1.use_count() << "\n\n";

  {
    counted_ptr<int> cptri2(cptri1);
    cout << "\n--- Prob[" << probIndex++ << "] ---\n"
      << "cptri1 value : " << *cptri1 << "\n"
      << "cptri1 use_count : " << cptri1.use_count() << "\n\n";

    counted_ptr<int> cptri3(new int(20));
    cptri3 = cptri2;
    cout << "\n--- Prob[" << probIndex++ << "] ---\n"
      << "cptri1 value : " << *cptri1 << "\n"
      << "cptri1 use_count : " << cptri1.use_count() << "\n\n";

    counted_ptr<int> cptri4(move(cptri3));
    cout << "\n--- Prob[" << probIndex++ << "] ---\n"
      << "cptri1 value : " << *cptri1 << "\n"
      << "cptri1 use_count : " << cptri1.use_count() << "\n\n";

    cptri3 = move(cptri4);
    cout << "\n--- Prob[" << probIndex++ << "] ---\n"
      << "cptri1 value : " << *cptri1 << "\n"
      << "cptri1 use_count : " << cptri1.use_count() << "\n\n";
  }

  cout << "\n--- Prob[" << probIndex++ << "] ---\n"
    << "cptri1 value : " << *cptri1 << "\n"
    << "cptri1 use_count : " << cptri1.use_count() << "\n\n";

  counted_ptr <Test> uptrt(new Test);
  uptrt->foo();
  (*uptrt).foo();

	return 0;
}