/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2022 19:37:32
	author                                          : Andrei-KS
*/

#include "CH13P484EXERC1_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Arc.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P484EXERC1_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 800;
  constexpr int windowHeight = 800;

  void getInfo(const Graph_lib::Arc& arc, const string& arcName = "")
  {
    cout << "info about " << arcName << ":\n"
      << "center: (" << arc.center().x << "," << arc.center().x << ")\n"
      << "xAxisHalfLength: " << arc.xAxisHalfLength() << "\n"
      << "yAxisHalfLength: " << arc.yAxisHalfLength() << "\n"
      << "start: " << arc.start() << "\n"
      << "end: " << arc.end() << "\n";
  }
}

int CH13P484EXERC1_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P484EXERC1_FLTKRunExmple");

  Graph_lib::Arc arc1(Graph_lib::Point{ 100,100 }, 100, 100, 0, 180);
  arc1.set_color(Graph_lib::Color::red);
  sWindow.attach(arc1);

  Graph_lib::Arc arc2(Graph_lib::Point{ 200,100 }, 100, 100, 180, 360);
  arc2.set_color(Graph_lib::Color::red);
  sWindow.attach(arc2);

  Graph_lib::Arc arc3(Graph_lib::Point{ 300,100 }, 100, 100, 90, 270);
  arc3.set_color(Graph_lib::Color::blue);
  sWindow.attach(arc3);

  Graph_lib::Arc arc4(Graph_lib::Point{ 500,100 }, 50, 100, 90, 270);
  arc4.set_color(Graph_lib::Color::blue);
  sWindow.attach(arc4);

  Graph_lib::Arc arc5(Graph_lib::Point{ 100,200 }, 50, 100, 90, 270);
  arc5.set_color(Graph_lib::Color::green);
  arc5.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 3));
  sWindow.attach(arc5);

  Graph_lib::Arc arc6(Graph_lib::Point{ 300,200 }, 50, 20, 45, 333);
  arc6.set_color(Graph_lib::Color::blue);
  arc6.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dashdotdot, 4));
  sWindow.attach(arc6);

  Graph_lib::Arc arc7(Graph_lib::Point{ 400,300 }, 50, 20, 45, 333);
  arc7.set_color(Graph_lib::Color::red);
  arc7.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dashdotdot, 4));
  sWindow.attach(arc7);

  getInfo(arc7, "arc7");

  sWindow.wait_for_button();

  // try to chack error case
  try
  {
    Graph_lib::Arc arcError(Graph_lib::Point{ 300,100 }, 100, 100, 100, 90);
    arcError.set_color(Graph_lib::Color::blue);
    sWindow.attach(arcError);
    sWindow.wait_for_button();
  }
  catch (exception& e)
  {
    cout << e.what() << "\n";
  }
  sWindow.wait_for_button();

  arc7.move(50, 0);
  arc7.setXAxisHalfLength(arc7.xAxisHalfLength() * 2);
  arc7.setYAxisHalfLength(arc7.yAxisHalfLength() * 2);
  arc7.setStart(arc7.start() + 45);
  arc7.setEnd(arc7.end() + 45);
  getInfo(arc7, "arc7");

  sWindow.wait_for_button();
	return 0;
}