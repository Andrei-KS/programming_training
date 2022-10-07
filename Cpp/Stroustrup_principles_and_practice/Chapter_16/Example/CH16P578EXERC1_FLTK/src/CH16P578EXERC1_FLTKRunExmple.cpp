/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/06/2022 15:11:28
	author                                          : Andrei-KS
*/

#include "CH16P578EXERC1_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "My_window.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P578EXERC1_FLTKRunExmple();

namespace {
}

int CH16P578EXERC1_FLTKRunExmple::excute()
{
  Graph_lib::My_window myWindow({ 100,100 }, 600, 400, "CH16P578EXERC1_FLTKRunExmple");
	return Graph_lib::gui_main();
}