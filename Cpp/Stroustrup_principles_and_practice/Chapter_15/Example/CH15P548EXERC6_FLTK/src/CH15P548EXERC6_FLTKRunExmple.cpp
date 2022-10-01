/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 12:42:38
	author                                          : Andrei-KS
*/

#include "CH15P548EXERC6_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Bar_graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P548EXERC6_FLTKRunExmple();

namespace {
}

int CH15P548EXERC6_FLTKRunExmple::excute()
{
  Graph_lib::Simple_window sWindow(Graph_lib::Point{ 50,50 }, 600, 600, "CH15P548EXERC6_FLTKRunExmple");

  Graph_lib::Bar_graph bg{ Graph_lib::Point{100,100},200,200,{4.0, 32.0,2.0,3.0} };
  bg.set_color(Graph_lib::Color::black);
  bg.set_fill_color(Graph_lib::Color::blue);
  sWindow.attach(bg);
  sWindow.wait_for_button();
	return 0;
}