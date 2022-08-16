/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/16/2022 19:11:03
	author                                          : Andrei-KS
*/

#include "CH13P447ILLUST_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P447ILLUST_FLTKRunExmple();

namespace {
}

int CH13P447ILLUST_FLTKRunExmple::excute()
{
  const Graph_lib::Point x{ 100,100 };
  Graph_lib::Simple_window win1{ x,600,400,"Lines" };

  Graph_lib::Lines lines;
  lines.add(Graph_lib::Point{ 100, 100 } , Graph_lib::Point{ 200, 100 } );
  lines.add(Graph_lib::Point{ 150, 50 } , Graph_lib::Point{ 150, 150 } );
  lines.set_color(Graph_lib::Color::black);
  
  win1.attach(lines);

  win1.wait_for_button();
  return 0;
}