/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 18:12:19
	author                                          : Andrei-KS
*/

#include "CH15P548EXERC7_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Bar_graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P548EXERC7_FLTKRunExmple();

namespace {
  vector<double> values = {
    4.0,
    32.0,
    2.0,
    3.0
  };
}

int CH15P548EXERC7_FLTKRunExmple::excute()
{
  Graph_lib::Simple_window sWindow(Graph_lib::Point{ 50,50 }, 600, 600, "CH15P548EXERC6_FLTKRunExmple");

  Graph_lib::Bar_graph bg{ Graph_lib::Point{100,100},200,200,values };
  bg.set_color(Graph_lib::Color::black);
  bg.set_fill_color(Graph_lib::Color::blue);
  sWindow.attach(bg);

  vector<Graph_lib::Bar_graph::Bar_info> BarInfos(values.size());
  for (int index = 0; index < values.size(); index++)
  {
    BarInfos[index].value = values[index];
  }
  BarInfos[0].fill_color = Graph_lib::Color::red;

  Graph_lib::Bar_graph bg1{ Graph_lib::Point{100,350},200,200,BarInfos };
  bg1.set_color(Graph_lib::Color::black);
  bg1.set_fill_color(Graph_lib::Color::blue);
  sWindow.attach(bg1);
  sWindow.wait_for_button();

  {
    Graph_lib::Bar_graph::Bar_info barInfo = bg1.getBarInfo(0);
    barInfo.fill_color = Graph_lib::Color::cyan;
    barInfo.label = "name";
    bg1.setBarInfo(0, barInfo);
  }
  sWindow.wait_for_button();

  {
    Graph_lib::Bar_graph::Bar_info barInfo = bg1.getBarInfo(1);
    barInfo.fill_color = Graph_lib::Color::dark_green;
    barInfo.label = "name2";
    bg1.setBarInfo(1, barInfo);
  }
  sWindow.wait_for_button();
  return 0;
}