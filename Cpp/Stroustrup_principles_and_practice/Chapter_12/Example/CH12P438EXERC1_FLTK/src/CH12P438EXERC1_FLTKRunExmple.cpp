/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 13:14:06
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC1_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC1_FLTKRunExmple();

namespace {
}

int CH12P438EXERC1_FLTKRunExmple::excute()
{
  // Make window
  const int yUpperLeftWindowCorner = 100;
  const int xUpperLeftWindowCorner = 100;
  const int yMaxWindow = 200;
  const int xMaxWindow = 200;
  Graph_lib::Point topLeft(yUpperLeftWindowCorner, xUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(topLeft, xMaxWindow, yMaxWindow, "EXERC1");

  // Make rectangle using Rectagle
  int xtopLeftRectangleCorner = 50;
  int ytopLeftRectangleCorner = 100;
  int widthRectangle = 30;
  int hightRectangle = 20;
  Graph_lib::Point topLeftRectangleCorner(xtopLeftRectangleCorner, ytopLeftRectangleCorner);
  Graph_lib::Rectangle rectangle(topLeftRectangleCorner, widthRectangle, hightRectangle);
  rectangle.set_color(Graph_lib::Color::blue);
  sWindow.attach(rectangle);

  // make rectangle using Polygon
  int xtopLeftPRectangleCorner = 30;
  int ytopLeftPRectangleCorner = 30;
  int widthPRectangle = 50;
  int hightPRectangle = 10;
  Graph_lib::Polygon pRectangle;
  pRectangle.add(Graph_lib::Point(xtopLeftPRectangleCorner                  , ytopLeftPRectangleCorner                  ));
  pRectangle.add(Graph_lib::Point(xtopLeftPRectangleCorner + widthPRectangle, ytopLeftPRectangleCorner                  ));
  pRectangle.add(Graph_lib::Point(xtopLeftPRectangleCorner + widthPRectangle, ytopLeftPRectangleCorner + hightPRectangle));
  pRectangle.add(Graph_lib::Point(xtopLeftPRectangleCorner                  , ytopLeftPRectangleCorner + hightPRectangle));
  pRectangle.set_color(Graph_lib::Color::red);
  sWindow.attach(pRectangle);

  // Display
  sWindow.wait_for_button();
	return 0;
}