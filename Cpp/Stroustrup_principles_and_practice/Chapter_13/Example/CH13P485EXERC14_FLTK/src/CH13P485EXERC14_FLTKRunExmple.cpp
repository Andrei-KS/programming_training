/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 18:26:42
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC14_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Right_triangle.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC14_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 400;

  // the right triangles setting
  constexpr int xIndent = 100;
  constexpr int yIndent = 50;
  constexpr int sideLength = 70;
}

int CH13P485EXERC14_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC14_FLTKRunExmple");

  int color = 0;
  Graph_lib::Right_triangle rightAngle1{ Graph_lib::Point{xIndent,yIndent}, sideLength,270 };
  rightAngle1.set_color(Graph_lib::Color(color++));
  rightAngle1.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle1);

  Graph_lib::Right_triangle rightAngle2{ Graph_lib::Point{xIndent + sideLength, yIndent + sideLength},sideLength,90 };
  rightAngle2.set_color(Graph_lib::Color(color++));
  rightAngle2.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle2);

  Graph_lib::Right_triangle rightAngle3{ Graph_lib::Point{xIndent + sideLength, yIndent + sideLength},sideLength,0 };
  rightAngle3.set_color(Graph_lib::Color(color++));
  rightAngle3.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle3);

  Graph_lib::Right_triangle rightAngle4{ Graph_lib::Point{xIndent + sideLength, yIndent + sideLength},sideLength,270 };
  rightAngle4.set_color(Graph_lib::Color(color++));
  rightAngle4.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle4);

  Graph_lib::Right_triangle rightAngle5{ Graph_lib::Point{xIndent + 2 * sideLength, yIndent + 2 * sideLength},sideLength,90 };
  rightAngle5.set_color(Graph_lib::Color(color++));
  rightAngle5.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle5);

  Graph_lib::Right_triangle rightAngle6{ Graph_lib::Point{xIndent + 2 * sideLength, yIndent + 2 * sideLength},sideLength,0 };
  rightAngle6.set_color(Graph_lib::Color(color++));
  rightAngle6.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle6);

  Graph_lib::Right_triangle rightAngle7{ Graph_lib::Point{xIndent + 1 * sideLength, yIndent + 2 * sideLength},sideLength,270 };
  rightAngle7.set_color(Graph_lib::Color(color++));
  rightAngle7.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle7);

  Graph_lib::Right_triangle rightAngle8{ Graph_lib::Point{xIndent + 2 * sideLength, yIndent + 3 * sideLength},sideLength,90 };
  rightAngle8.set_color(Graph_lib::Color(color++));
  rightAngle8.set_fill_color(Graph_lib::Color(color++));
  sWindow.attach(rightAngle8);

  sWindow.wait_for_button();
	return 0;
}