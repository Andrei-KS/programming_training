/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 14:22:31
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC2_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC2_FLTKRunExmple();

namespace {
}

int CH12P438EXERC2_FLTKRunExmple::excute()
{
  // Make window
  const int yUpperLeftWindowCorner = 100;
  const int xUpperLeftWindowCorner = 100;
  const int yMaxWindow = 200;
  const int xMaxWindow = 200;
  Graph_lib::Point topLeft(yUpperLeftWindowCorner, xUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(topLeft, xMaxWindow, yMaxWindow, "EXERC2");

  // Make rectangle
  int xtopLeftRectangleCorner = 50;
  int ytopLeftRectangleCorner = 100;
  int widthRectangle = 100;
  int hightRectangle = 30;
  Graph_lib::Point topLeftRectangleCorner(xtopLeftRectangleCorner, ytopLeftRectangleCorner);
  Graph_lib::Rectangle rectangle(topLeftRectangleCorner, widthRectangle, hightRectangle);
  rectangle.set_color(Graph_lib::Color::blue);
  sWindow.attach(rectangle);

  // Make text
  int xBottomLeftText = xtopLeftRectangleCorner + widthRectangle * 2 / 7;
  int yBottomLeftText = ytopLeftRectangleCorner + hightRectangle * 2 / 3;
  Graph_lib::Text text(Graph_lib::Point(xBottomLeftText, yBottomLeftText), "Howdy!");
  text.set_color(Graph_lib::Color::blue);
  text.set_font(Graph_lib::Font::times_bold);
  sWindow.attach(text);

  // Display
  sWindow.wait_for_button();
	return 0;
}