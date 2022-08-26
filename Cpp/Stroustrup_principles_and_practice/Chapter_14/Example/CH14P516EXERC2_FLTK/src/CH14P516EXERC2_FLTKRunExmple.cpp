/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/26/2022 12:18:58
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC2_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC2_FLTKRunExmple();

namespace {
}

int CH14P516EXERC2_FLTKRunExmple::excute()
{
  Graph_lib::Circle circleCopy = Graph_lib::Circle{ {100,100},10 }; //error: 'Graph_lib::Circle::Circle(const Graph_lib::Circle &)': attempting to reference a deleted function
	return 0;
}