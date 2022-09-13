/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/12/2022 12:11:26
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC7_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Striped_closed_polyline.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC7_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;

  const vector<Graph_lib::Point> points = {
    { 40,10 },
    { 50,40 },
    { 40,80 },
    { 30,40 },
    { 10,10 },
    { 10,90 },
    { 40,60 },
    { 10,60 },
  };
}

int CH14P516EXERC7_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P516EXERC7_FLTKRunExmple");

  Graph_lib::Closed_polyline openPoly;
  for (const Graph_lib::Point& point : points)
  {
    openPoly.add({ point.x, point.y });
  }
  openPoly.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 3 });
  openPoly.set_fill_color(0);
  openPoly.set_color(1);

  const int xShift = 100;
  const int yShift = 100;

  Graph_lib::Striped_closed_polyline sClosedPoline;
  for (const Graph_lib::Point& point : points)
  {
    sClosedPoline.add({ point.x + xShift, point.y + yShift });
  }
  sClosedPoline.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 3 });
  sClosedPoline.set_color(1);
  sClosedPoline.set_fill_line_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 3 });
  sClosedPoline.set_distance_between_strips(1);
  sClosedPoline.set_fill_color(0);

  sWindow.attach(openPoly);
  sWindow.attach(sClosedPoline);

  sWindow.wait_for_button();
	return 0;
}