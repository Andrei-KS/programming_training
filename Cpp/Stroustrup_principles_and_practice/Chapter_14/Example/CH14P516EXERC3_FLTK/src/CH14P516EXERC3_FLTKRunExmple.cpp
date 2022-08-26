/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/26/2022 12:24:28
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC3_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC3_FLTKRunExmple();

namespace {
  class AbstractMyClass {
  public:
    virtual void check() = 0;
  };
}

int CH14P516EXERC3_FLTKRunExmple::excute()
{
  AbstractMyClass abstract; // error: '`anonymous-namespace'::AbstractMyClass': cannot instantiate abstract class
	return 0;
}