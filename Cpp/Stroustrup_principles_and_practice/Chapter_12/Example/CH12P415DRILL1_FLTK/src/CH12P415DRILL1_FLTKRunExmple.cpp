/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/09/2022 13:17:35
	author                                          : Andrei-KS
*/

#include "CH12P415DRILL1_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P415DRILL1_FLTKRunExmple();

namespace {
}

int CH12P415DRILL1_FLTKRunExmple::excute()
{
  Graph_lib::Point tl{ 100,100 };
  Graph_lib::Simple_window win{ tl,600,400,"My window" };
  win.wait_for_button();
	return 0;
}