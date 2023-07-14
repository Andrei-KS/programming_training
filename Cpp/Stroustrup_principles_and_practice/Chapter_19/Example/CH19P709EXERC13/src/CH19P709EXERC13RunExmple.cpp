/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/12/2023 09:47:51
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC13RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC13RunExmple();

namespace {
  /*
  */
  class Tracer {
  public:
    /*
    */
    Tracer()
      : Tracer("Default")
    {
    }

    /*
    */
    Tracer(const string& str)
      : m_str{str}
    {
      log();
    }

    /*
    */
    ~Tracer()
    {
      log(false);
    }
    
    /*
    */
    string GetString()
    {
      return m_str;
    }

  private:
    /**/
    string m_str;

    /**/
    void log(bool isConstructor = true)
    {
      cout << setiosflags(ios::left) << "Tracer log :: " << setw(12) << (isConstructor ? "Constructor" : "Destructor") << " :: " << m_str << "\n";
    }
  };

  class Object {
  public:
    /*
    */
    Object()
      : m_tracer(new Tracer("Default Object"))
    {
    }

    /*
    */
    Object(string nameObjetc)
      : m_tracer(new Tracer(nameObjetc))
    {
    }

    /*
    */
    Object(const Object& other)
      : m_tracer(new Tracer("Default Object of the copy constructor"))
    {
      Tracer scopeTracer("the scope of the copy constructor");
      delete m_tracer;
      m_tracer = new Tracer(other.m_tracer->GetString());
    }

    /*
    */
    Object& operator=(const Object& other)
    {
      Tracer scopeTracer("the scope of the copy assignment");
      if (this != &other)
      {
        delete m_tracer;
        m_tracer = new Tracer(other.m_tracer->GetString());
      }
      return *this;
    }

    /*
    */
    ~Object()
    {
      delete m_tracer;
    }

  private:
    /**/
    Tracer* m_tracer;
  };

  class ComplexObject {
  public:
    /*
    */
    ComplexObject()
      : m_tracer("Default Complex Object")
      , m_obj{"Member of Complex Object"}
    {
    }

    /*
    */
    ComplexObject(string nameObjetc)
      : m_tracer(nameObjetc)
      , m_obj{ "Member of Complex Object (" + nameObjetc + ")"}
    {
    }
  private:
    /**/
    Tracer m_tracer;
    
    /**/
    Object m_obj;
  };

  Object globalObject("globalObject");
  ComplexObject globalComplexObject("globalComplexObject");
}

int CH19P709EXERC13RunExmple::excute()
{
  Object localObject("localObject");
  Object copy1LocalObject(localObject);
  Object copy2LocalObject("copy2LocalObject");
  copy2LocalObject = localObject;
  ComplexObject localComplexObject("localComplexObject");
  ComplexObject* complexObjectPtr;
  complexObjectPtr = new ComplexObject("allocatedComplexObject");
  delete complexObjectPtr;
	return 0;
}