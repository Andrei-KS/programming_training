/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/16/2022 19:18:37
	author                                          : Andrei-KS
*/

#include "CH13P448ILLUST_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P448ILLUST_FLTKRunExmple();

namespace {
}

int CH13P448ILLUST_FLTKRunExmple::excute()
{
  const Graph_lib::Point x{ 100,100 };
  Graph_lib::Simple_window win{ x,600,400,"Grid" };

  int x_size = win.x_max();
  int y_size = win.y_max();
  int x_grid = 80;
  int y_grid = 40;

  Graph_lib::Lines grid;
  for (int x = x_grid; x < x_size; x += x_grid)
  {
    grid.add(Graph_lib::Point{ x,0 }, Graph_lib::Point{ x, y_size });
  }

  for (int y = y_grid; y < y_size; y += y_grid)
  {
    grid.add(Graph_lib::Point{ 0, y }, Graph_lib::Point{ x_size, y });
  }

  grid.set_color(Graph_lib::Color::black);

  win.attach(grid);

  win.wait_for_button();
  return 0;
}