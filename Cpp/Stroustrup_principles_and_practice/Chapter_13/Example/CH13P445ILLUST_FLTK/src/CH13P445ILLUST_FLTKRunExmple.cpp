/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/16/2022 19:03:50
	author                                          : Andrei-KS
*/

#include "CH13P445ILLUST_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P445ILLUST_FLTKRunExmple();

namespace {
}

int CH13P445ILLUST_FLTKRunExmple::excute()
{
  const Graph_lib::Point x{ 100,100 };
  Graph_lib::Simple_window win1{ x,600,400,"two line" };
  
  Graph_lib::Line horizontal{ x, Graph_lib::Point{200,100} };
  horizontal.set_color(Graph_lib::Color::black);
  
  Graph_lib::Line vertical { Graph_lib::Point{150, 50} , Graph_lib::Point{150,150} };
  vertical.set_color(Graph_lib::Color::black);
  
  win1.attach(horizontal);
  win1.attach(vertical);
  
  win1.wait_for_button();
	return 0;
}