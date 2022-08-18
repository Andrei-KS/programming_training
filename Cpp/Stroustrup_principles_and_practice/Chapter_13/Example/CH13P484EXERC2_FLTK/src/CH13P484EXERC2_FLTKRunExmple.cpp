/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2022 14:31:40
	author                                          : Andrei-KS
*/

#include "CH13P484EXERC2_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Box.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P484EXERC2_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 800;
  constexpr int windowHeight = 800;
}

int CH13P484EXERC2_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P484EXERC2_FLTKRunExmple");
  
  Graph_lib::Box box1(Graph_lib::Point{ 100,100 }, 100, 100, 10, 10);
  box1.set_fill_color(Graph_lib::Color::red);
  sWindow.attach(box1);

  Graph_lib::Box box2(Graph_lib::Point{ 300,300 }, 200, 200, 100, 20);
  box2.set_fill_color(Graph_lib::Color::green);
  box2.set_color(Graph_lib::Color::black);
  sWindow.attach(box2);

  Graph_lib::Box box3(Graph_lib::Point{ 0,300 }, 100, 100, 50, 50);
  box3.set_fill_color(Graph_lib::Color::green);
  box3.set_color(Graph_lib::Color::black);
  sWindow.attach(box3);

  sWindow.wait_for_button();
	return 0;
}