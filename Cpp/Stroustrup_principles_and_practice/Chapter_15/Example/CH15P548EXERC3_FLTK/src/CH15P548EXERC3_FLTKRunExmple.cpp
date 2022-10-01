/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/30/2022 19:16:16
	author                                          : Andrei-KS
*/

#include "CH15P548EXERC3_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Extended_function.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P548EXERC3_FLTKRunExmple();

namespace {
  double one(double x)
  {
    return 1;
  }

  double slope(double x)
  {
    return x / 2;
  }

  double square(double x)
  {
    return x * x;
  }

  double sloping_cos(double x)
  {
    return slope(x) + cos(x);
  }
}

int CH15P548EXERC3_FLTKRunExmple::excute()
{
  Graph_lib::Simple_window sWindow(Graph_lib::Point{ 50,50 }, 600, 600, "CH15P548EXERC2_FLTK");

  Graph_lib::Axis xAxis{ Graph_lib::Axis::Orientation::x,Graph_lib::Point{100,300},400,20,"1 == 20 pixels" };
  xAxis.set_color(Graph_lib::Color::red);
  sWindow.attach(xAxis);

  Graph_lib::Axis yAxis{ Graph_lib::Axis::Orientation::y,Graph_lib::Point{300,500},400,20,"1 == 20 pixels" };
  yAxis.set_color(Graph_lib::Color::red);
  sWindow.attach(yAxis);

  Graph_lib::Extended_function efn{ slope , { -10, 11},Graph_lib::Point{300,300},400,{20,20}, 5.0 };
  efn.set_color(Graph_lib::Color::black);

  sWindow.attach(efn);
  sWindow.wait_for_button();

  efn.reset(square, { -10, 11 }, Graph_lib::Point{ 300,300 }, 400, { 20,20 });
  sWindow.wait_for_button();

  efn.reset(square, { -10, 11 }, Graph_lib::Point{ 300,300 }, 20, { 20,20 });
  sWindow.wait_for_button();
  return 0;
}