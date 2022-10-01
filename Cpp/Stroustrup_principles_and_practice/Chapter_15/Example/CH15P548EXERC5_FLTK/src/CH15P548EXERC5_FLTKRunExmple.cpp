/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 11:27:56
	author                                          : Andrei-KS
*/

#include "CH15P548EXERC5_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P548EXERC5_FLTKRunExmple();

namespace {
  template<int members_number>
  double leibnizs_series(double x)
  {
    if (members_number < 0)
    {
      error("leibnizs_series: leibniz series cannot contain negative members number ");
    }
    double result = 0;
    double currentX = x;
    double currentDivider = 1;
    for (int index = 0; index < members_number; index++)
    {
      result += currentX / currentDivider * (index % 2 ? -1 : 1);
      currentX = currentX * x * x;
      currentDivider += 2;
    }
    return result;
  }
}

int CH15P548EXERC5_FLTKRunExmple::excute()
{
  Graph_lib::Simple_window sWindow(Graph_lib::Point{ 50,50 }, 600, 600, "CH15P548EXERC2_FLTK");

  Graph_lib::Axis xAxis{ Graph_lib::Axis::Orientation::x,Graph_lib::Point{100,300},400,20,"1 == 20 pixels" };
  xAxis.set_color(Graph_lib::Color::red);
  sWindow.attach(xAxis);

  Graph_lib::Axis yAxis{ Graph_lib::Axis::Orientation::y,Graph_lib::Point{300,500},400,20,"1 == 20 pixels" };
  yAxis.set_color(Graph_lib::Color::red);
  sWindow.attach(yAxis);

  {
    Graph_lib::Function fn{ leibnizs_series<0> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }

  {
    Graph_lib::Function fn{ leibnizs_series<1> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }

  {
    Graph_lib::Function fn{ leibnizs_series<2> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }

  {
    Graph_lib::Function fn{ leibnizs_series<3> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }

  {
    Graph_lib::Function fn{ leibnizs_series<4> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }

  {
    Graph_lib::Function fn{ leibnizs_series<5> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }

  {
    Graph_lib::Function fn{ leibnizs_series<6> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }

  {
    Graph_lib::Function fn{ leibnizs_series<7> , -10, 11,Graph_lib::Point{300,300},400,20,20 };
    fn.set_color(Graph_lib::Color::black);
    sWindow.attach(fn);
    sWindow.wait_for_button();
    sWindow.detach(fn);
  }
  return 0;
}