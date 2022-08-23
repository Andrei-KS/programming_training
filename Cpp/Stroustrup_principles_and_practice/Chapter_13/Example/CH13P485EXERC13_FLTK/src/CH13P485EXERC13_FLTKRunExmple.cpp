/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 17:41:17
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC13_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC13_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 400;
}

int CH13P485EXERC13_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC13_FLTKRunExmple");

  Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;
  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
      vr.push_back(new Graph_lib::Rectangle{ Graph_lib::Point{i * 20,j * 20},20,20 });
      vr[vr.size() - 1].set_fill_color(Graph_lib::Color{ i * 16 + j });
      vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
      sWindow.attach(vr[vr.size() - 1]);
    }
  }

  sWindow.wait_for_button();
	return 0;
}