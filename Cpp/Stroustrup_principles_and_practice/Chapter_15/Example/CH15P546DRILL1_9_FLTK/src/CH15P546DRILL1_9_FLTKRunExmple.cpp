/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/19/2022 19:17:25
	author                                          : Andrei-KS
*/

#include "CH15P546DRILL1_9_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P546DRILL1_9_FLTKRunExmple();

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

int CH15P546DRILL1_9_FLTKRunExmple::excute()
{
  Graph_lib::Window window(Graph_lib::Point{ 50,50 }, 600, 600, "Function graphs.");

  Graph_lib::Axis xAxis{ Graph_lib::Axis::Orientation::x,Graph_lib::Point{100,300},400,20,"1 == 20 pixels" };
  xAxis.set_color(Graph_lib::Color::red);
  window.attach(xAxis);

  Graph_lib::Axis yAxis{ Graph_lib::Axis::Orientation::y,Graph_lib::Point{300,500},400,20,"1 == 20 pixels" };
  yAxis.set_color(Graph_lib::Color::red);
  window.attach(yAxis);

  //Graph_lib::Function fn_one{ one , -10, 11,Graph_lib::Point{300,300},400};
  Graph_lib::Function fn_one{ one , -10, 11,Graph_lib::Point{300,300},400,20,20};
  fn_one.set_color(Graph_lib::Color::black);

  Graph_lib::Function fn_slope{ slope , -10, 11,Graph_lib::Point{300,300},400,20,20};
  fn_slope.set_color(Graph_lib::Color::black);
  Graph_lib::Text lable_fn_slope{ Graph_lib::Point{300 + (-10)*20, 300 - static_cast<int>(slope(-10)*20) - 10} , "x/2"};
  lable_fn_slope.set_color(Graph_lib::Color::black);

  Graph_lib::Function fn_square{ square , -10, 11,Graph_lib::Point{300,300},400,20,20 };
  fn_square.set_color(Graph_lib::Color::black);

  Graph_lib::Function fn_cos{ [](double x) {return cos(x); } , -10, 11,Graph_lib::Point{300,300},400,20,20 };
  fn_cos.set_color(Graph_lib::Color::blue);

  Graph_lib::Function fn_sloping_cos{ sloping_cos , -10, 11,Graph_lib::Point{300,300},400,20,20 };
  fn_sloping_cos.set_color(Graph_lib::Color::cyan);

  window.attach(fn_one);
  window.attach(fn_slope);
  window.attach(lable_fn_slope);
  window.attach(fn_square);
  window.attach(fn_cos);
  window.attach(fn_sloping_cos);
  Graph_lib::gui_main();
  return 0;
}