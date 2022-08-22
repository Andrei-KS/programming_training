/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/22/2022 17:40:42
	author                                          : Andrei-KS
*/

#include "CH13P484EXERC8_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Regular_hexagon.h"
#include "Arrow.h"
#include "Vector2D.h"


RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P484EXERC8_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 400;
}

int CH13P484EXERC8_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P484EXERC8_FLTKRunExmple");


  Graph_lib::Regular_hexagon regular_hexagon1{ Graph_lib::Point{100,100},30 };
  regular_hexagon1.set_color(Graph_lib::Color::red);
  regular_hexagon1.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(regular_hexagon1);

  Graph_lib::Regular_hexagon regular_hexagon2{ Graph_lib::Point{200,100},35,5 };
  regular_hexagon2.set_color(Graph_lib::Color::red);
  regular_hexagon2.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(regular_hexagon2);

  Graph_lib::Regular_hexagon regular_hexagon3{ Graph_lib::Point{300,100},40,10 };
  regular_hexagon3.set_color(Graph_lib::Color::red);
  regular_hexagon3.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(regular_hexagon3);

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