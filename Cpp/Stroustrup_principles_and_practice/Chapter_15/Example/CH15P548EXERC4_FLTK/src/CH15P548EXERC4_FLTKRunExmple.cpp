/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 10:58:46
	author                                          : Andrei-KS
*/

#include "CH15P548EXERC4_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P548EXERC4_FLTKRunExmple();

namespace {
  double sum_s_c(double x) { return sin(x) + cos(x); }
  double sqr_sum_s_c(double x) { return sin(x)*sin(x) + cos(x)*cos(x); }
  vector<double(*)(double)> functions = {
    sin,
    cos,
    sum_s_c,
    sqr_sum_s_c,
  };

  vector<string> function_names =
  {
    "sin(x)",
    "cos(x)",
    "sin(x)+cos(x)",
    "sin(x)^2 + cos(x)^2"
  };
}

int CH15P548EXERC4_FLTKRunExmple::excute()
{
  Graph_lib::Simple_window sWindow(Graph_lib::Point{ 50,50 }, 600, 600, "CH15P548EXERC4_FLTKRunExmple");

  Graph_lib::Axis xAxis{ Graph_lib::Axis::Orientation::x,Graph_lib::Point{100,300},400,20,"1 == 20 pixels" };
  xAxis.set_color(Graph_lib::Color::red);
  sWindow.attach(xAxis);

  Graph_lib::Axis yAxis{ Graph_lib::Axis::Orientation::y,Graph_lib::Point{300,500},400,20,"1 == 20 pixels" };
  yAxis.set_color(Graph_lib::Color::red);
  sWindow.attach(yAxis);

  Graph_lib::Vector_ref<Graph_lib::Shape> function_shapes;

  for (double(*fn)(double)  : functions)
  {
    function_shapes.push_back(new Graph_lib::Function{ fn , -10, 11,Graph_lib::Point{300,300},400, 20, 20 });
    int index = function_shapes.size()-1;
    function_shapes[index].set_color(Graph_lib::Color(index+2));
    sWindow.attach(function_shapes[index]);
    if (index/2 < function_names.size())
    {
      function_shapes.push_back(new Graph_lib::Text{ Graph_lib::Point{300 - 10 * 20,100 + index/2*14},function_names[index/2].c_str()});
      function_shapes[function_shapes.size() - 1].set_color(Graph_lib::Color(index + 2));
      sWindow.attach(function_shapes[function_shapes.size() - 1]);
    }
  }

  sWindow.wait_for_button();
  return 0;
}