/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2022 14:49:40
	author                                          : Andrei-KS
*/

#include "CH13P467ILLUST_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Vector_ref.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P467ILLUST_FLTKRunExmple();

namespace {
}

int CH13P467ILLUST_FLTKRunExmple::excute()
{
  const Graph_lib::Point x{ 100,100 };
  Graph_lib::Simple_window win{ x,600,400,"Rectangle" };

  Utility_lib::Vector_ref<Graph_lib::Rectangle> vr;
  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
      vr.push_back(new Graph_lib::Rectangle{ Graph_lib::Point{i * 20,j * 20},20,20 });
      vr[vr.size() - 1].set_fill_color(Graph_lib::Color{ i * 16 + j });
      vr[vr.size() - 1].set_color(Graph_lib::Color::black);
      win.attach(vr[vr.size() - 1]);
    }
  }

  win.wait_for_button();

  return 0;
}