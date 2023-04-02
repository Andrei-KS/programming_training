/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/31/2023 09:09:01
	author                                          : Andrei-KS
*/

#include "CH17P605TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH17P605TRYRunExmple();

namespace {
  class Base {
  public:
    Base()
      :number(0)
    {
      static int counter = 0;
      ++counter;
      number = counter;
      cout << "Base() :: number==" << number << "\n";
    }

    ~Base()
    {
      cout << "~Base() :: number==" << number << "\n";
    }

  private:
    int number;
  };

  class Deriver : public Base
  {
  public:
    Deriver()
      :number2(0)
    {
      static int counter = 0;
      ++counter;
      number2 = counter;
      cout << "Deriver() :: number2:=" << number2 << "\n";
    }

    ~Deriver()
    {
      cout << "~Deriver() :: number2==" << number2 << "\n";
    }

  private:
    int number2;
  };

  class VBase {
  public:
    VBase() :number3(1)
    {
      static int counter = 0;
      ++counter;
      number3 = counter;
      cout << "VBase() :: number3:=" << number3 << "\n";
    }
    virtual ~VBase()
    {
      cout << "~VBase() :: number3:=" << number3 << "\n";
    }
  private:
    int number3;
  };


  class VDeriver : public VBase
  {
  public:
    VDeriver()
      :number4(0)
    {
      static int counter = 0;
      ++counter;
      number4 = counter;
      cout << "VDeriver() :: number4:=" << number4 << "\n";
    }

    ~VDeriver()
    {
      cout << "~VDeriver() :: number4==" << number4 << "\n";
    }

  private:
    int number4;
  };
}

int CH17P605TRYRunExmple::excute()
{
  cout << "A ->\n";
  Base A;
  cout << "B ->\n";
  Base B[5];
  cout << "DeriverA ->\n";
  Deriver DeriverA;
  cout << "VDeriverA as VBase ->\n";
  VBase* VA = new VDeriver();
  cout << "--- End ---\n";
  delete VA;
	return 0;
}