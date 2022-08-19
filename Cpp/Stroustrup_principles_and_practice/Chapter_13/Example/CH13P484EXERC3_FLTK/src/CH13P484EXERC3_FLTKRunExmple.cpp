/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2022 18:32:14
	author                                          : Andrei-KS
*/

#include "CH13P484EXERC3_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Arrow.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P484EXERC3_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 800;
  constexpr int windowHeight = 800;
}

int CH13P484EXERC3_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P484EXERC3_FLTKRunExmple");
  Graph_lib::Arrow arrow1(Graph_lib::Point{ 100,100 }, Graph_lib::Point{ 200,200 }, 10, 10);
  arrow1.set_color(Graph_lib::Color::red);
  arrow1.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(arrow1);

  Graph_lib::Arrow arrow2(Graph_lib::Point{ 100,100 }, Graph_lib::Point{ 200,100 }, 20, 10);
  arrow2.set_fill_color(Graph_lib::Color::blue);
  arrow2.set_color(Graph_lib::Color::red);
  sWindow.attach(arrow2);

  Graph_lib::Arrow arrow3(Graph_lib::Point{ 100,220 }, Graph_lib::Point{ 100,200 }, 20, 10);
  arrow3.set_fill_color(Graph_lib::Color::blue);
  arrow3.set_color(Graph_lib::Color::red);
  sWindow.attach(arrow3);

  sWindow.wait_for_button();
	return 0;
}