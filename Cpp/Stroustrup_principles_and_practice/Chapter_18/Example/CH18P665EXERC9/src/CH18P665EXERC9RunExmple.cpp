/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/26/2023 09:27:30
	author                                          : Andrei-KS
*/

#include "CH18P665EXERC9RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC9RunExmple();

namespace {
  class ProbeObject {
  public:
    ProbeObject()
    {
      cout << "This object have the adress: " << this << "\n";
    }
    ~ProbeObject()
    {}
  };

  void calcDirectionGrow(ProbeObject* first, ProbeObject* last)
  {
    int direction = reinterpret_cast<int>(last) - reinterpret_cast<int>(first);
    cout << (direction > 0 ? "UP" : "DOWN") << "\n";
  }
}

int CH18P665EXERC9RunExmple::excute()
{
  ProbeObject aPO1;
  ProbeObject aPO2;
  ProbeObject aPO3;
  ProbeObject aPO4;
  ProbeObject aPO5;
  cout << "--- stack ---\n";
  calcDirectionGrow(&aPO1, &aPO5);

  ProbeObject aPO[10];
  cout << "--- stack ---\n";
  calcDirectionGrow(aPO, &aPO[9]);

  ProbeObject* pPO1 = new ProbeObject[10];
  cout << "--\n";
  ProbeObject* pPO2 = new ProbeObject[10];
  cout << "--- on the free store ---\n";
  calcDirectionGrow(&pPO1[0], &pPO2[0]);

  delete[] pPO1;
  delete[] pPO2;
	return 0;
}