/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/19/2022 18:43:03
	author                                          : Andrei-KS
*/

#include "CH15P546DRILL1_5_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P546DRILL1_5_FLTKRunExmple();

namespace {
}

int CH15P546DRILL1_5_FLTKRunExmple::excute()
{
  Graph_lib::Window window(Graph_lib::Point{ 50,50 }, 600, 600, "Function graphs.");

  Graph_lib::Axis xAxis{ Graph_lib::Axis::Orientation::x,Graph_lib::Point{100,300},400,20,"1 == 20 pixels" };
  xAxis.set_color(Graph_lib::Color::red);
  window.attach(xAxis);

  Graph_lib::Axis yAxis{ Graph_lib::Axis::Orientation::y,Graph_lib::Point{300,500},400,20,"1 == 20 pixels" };
  yAxis.set_color(Graph_lib::Color::red);
  window.attach(yAxis);

  Graph_lib::gui_main();
  return 0;
}