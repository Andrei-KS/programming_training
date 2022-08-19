/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/19/2022 13:15:22
	author                                          : Andrei-KS
*/

#include "CH13P484EXERC4_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI_Utility_function.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P484EXERC4_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 800;
  constexpr int windowHeight = 800;

  vector<Graph_lib::Point(*)(const Graph_lib::Rectangle&)> funcs= {
    Graph_lib::n,
    Graph_lib::ne,
    Graph_lib::nw,
    Graph_lib::s,
    Graph_lib::se,
    Graph_lib::sw,
    Graph_lib::e,
    Graph_lib::w,
    Graph_lib::center,
  };

}

int CH13P484EXERC4_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P484EXERC4_FLTKRunExmple");

  Graph_lib::Rectangle rect{ Graph_lib::Point{100,100},100,200 };
  rect.set_color(Graph_lib::Color::red);

  Graph_lib::Vector_ref<Graph_lib::Circle> circles;
  const int circleRadius = 10;
  for (Graph_lib::Point(*func)(const Graph_lib::Rectangle&) : funcs)
  {
    circles.push_back(new Graph_lib::Circle(func(rect), circleRadius));
    circles[circles.size() - 1].set_color(Graph_lib::Color::black);
    circles[circles.size() - 1].set_fill_color(Graph_lib::Color::blue);
    sWindow.attach(circles[circles.size() - 1]);
  }
  

  Graph_lib::Rectangle rect2{ Graph_lib::Point{300,300},200,200 };
  rect.set_color(Graph_lib::Color::red);

  const int circleRadius2 = 5;
  for (Graph_lib::Point(*func)(const Graph_lib::Rectangle&) : funcs)
  {
    circles.push_back(new Graph_lib::Circle(func(rect2), circleRadius2));
    circles[circles.size() - 1].set_color(Graph_lib::Color::black);
    circles[circles.size() - 1].set_fill_color(Graph_lib::Color::blue);
    sWindow.attach(circles[circles.size() - 1]);
  }

  sWindow.attach(rect);
  sWindow.wait_for_button();
	return 0;
}