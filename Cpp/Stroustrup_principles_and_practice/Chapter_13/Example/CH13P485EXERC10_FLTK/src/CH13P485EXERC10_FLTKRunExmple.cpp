/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 16:17:03
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC10_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Arrow.h"
#include "Regular_polygon.h"
#include "Vector2D.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC10_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 400;
}

int CH13P485EXERC10_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC10_FLTKRunExmple");


  Graph_lib::Regular_polygon regular_polygon3{ Graph_lib::Point{100,100},50,10,90 };
  regular_polygon3.set_color(Graph_lib::Color::red);
  regular_polygon3.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(regular_polygon3);

  Graph_lib::Regular_polygon regular_polygon5{ Graph_lib::Point{200,100},35,5,5 };
  regular_polygon5.set_color(Graph_lib::Color::red);
  regular_polygon5.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(regular_polygon5);

  Graph_lib::Regular_polygon regular_polygon7{ Graph_lib::Point{300,100},40,7,10 };
  regular_polygon7.set_color(Graph_lib::Color::red);
  regular_polygon7.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(regular_polygon7);

  Utility_lib::Vector2D vect{ 100,0 };
  Graph_lib::Point start{ 50,200 };
  Graph_lib::Arrow ar1{ Graph_lib::Point{start.x, start.y}, Graph_lib::Point{start.x + static_cast<int>(vect.x), start.y + static_cast<int>(vect.y)} };
  ar1.set_color(Graph_lib::Color::red);
  sWindow.attach(ar1);

  vect.rotate(30);
  Graph_lib::Arrow ar2{ Graph_lib::Point{start.x, start.y}, Graph_lib::Point{start.x + static_cast<int>(vect.x), start.y + static_cast<int>(vect.y)} };
  ar2.set_color(Graph_lib::Color::red);
  sWindow.attach(ar2);

  sWindow.wait_for_button();
  return 0;
}