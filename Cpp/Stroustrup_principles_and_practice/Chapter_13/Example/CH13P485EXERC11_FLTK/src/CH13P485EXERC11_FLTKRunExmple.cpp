/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 16:32:50
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC11_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC11_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 400;

  // The ellipse setting
  constexpr int xCenter = windowWidth / 2;
  constexpr int yCenter = windowHeight / 2;
  constexpr int ellipseWidth = 150;
  constexpr int ellipseHeight = 100;
}

int CH13P485EXERC11_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC11_FLTKRunExmple");

  Graph_lib::Ellipse ellipse{ Graph_lib::Point{xCenter, yCenter},ellipseWidth, ellipseHeight };
  ellipse.set_color(Graph_lib::Color::black);
  sWindow.attach(ellipse);

  Graph_lib::Axis xAxis{ Graph_lib::Axis::x,Graph_lib::Point{xCenter - ellipseWidth - 50, yCenter}, 400, 20,"x Axis" };
  xAxis.set_color(Graph_lib::Color::black);
  sWindow.attach(xAxis);

  Graph_lib::Axis yAxis{ Graph_lib::Axis::y,Graph_lib::Point{xCenter, yCenter + ellipseHeight + 50}, 300, 20,"y Axis" };
  yAxis.set_color(Graph_lib::Color::black);
  sWindow.attach(yAxis);

  Graph_lib::Mark foci1{ ellipse.focus1(), 'F' };
  sWindow.attach(foci1);

  Graph_lib::Mark foci2{ ellipse.focus2(), 'F' };
  sWindow.attach(foci2);

  Graph_lib::Mark pointAtEllipse{ Graph_lib::Point{xCenter + 106, yCenter + 70},'P' };
  sWindow.attach(pointAtEllipse);

  Graph_lib::Lines lines;
  lines.add(foci1.point(0), pointAtEllipse.point(0));
  lines.add(foci2.point(0), pointAtEllipse.point(0));
  lines.set_color(Graph_lib::Color::red);
  sWindow.attach(lines);

  sWindow.wait_for_button();
	return 0;
}