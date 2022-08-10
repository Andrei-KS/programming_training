/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 17:02:25
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC5_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC5_FLTKRunExmple();

namespace {
  constexpr double INCH_TO_CM = 2.54;
  constexpr double CM_TO_PIXEL = 50;
  constexpr int INCH1_4 = static_cast<int>((INCH_TO_CM / 4) * CM_TO_PIXEL);
}

int CH12P438EXERC5_FLTKRunExmple::excute()
{
  // Window setting
  const int yUpperLeftWindowCorner = 100;
  const int xUpperLeftWindowCorner = 100;
  const int windowWidth = 500;
  const int windowHeight = 500;


  // Rectangle setting
  const int rectagleWidth = windowWidth * 2 / 3;
  const int rectagleHeight = windowHeight * 3 / 4;
  const int xTopLeftRectangleCorner = windowWidth * 1 / (3 * 2);
  const int yTopLeftRectangleCorner = windowHeight * 1 / (4 * 2);
  const Graph_lib::Color rectangleColor = Graph_lib::Color::white;

  // Frame setting
  const int xtopLeftFrameCorner = xTopLeftRectangleCorner - INCH1_4;
  const int ytopLeftFrameCorner = yTopLeftRectangleCorner - INCH1_4;
  const int frameWidth = rectagleWidth + 2 * INCH1_4;
  const int frameHeight = rectagleHeight + 2 * INCH1_4;
  const Graph_lib::Color frameColor = Graph_lib::Color::red;


  // Make window
  Graph_lib::Point topLeft(yUpperLeftWindowCorner, xUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(topLeft, windowWidth, windowHeight, "EXERC5");


  // Make rectangel
  Graph_lib::Rectangle rectangle(Graph_lib::Point(xTopLeftRectangleCorner, yTopLeftRectangleCorner), rectagleWidth, rectagleHeight);
  rectangle.set_fill_color(rectangleColor);
  rectangle.set_color(rectangleColor);


  // Make frame
  Graph_lib::Rectangle frame(Graph_lib::Point(xtopLeftFrameCorner, ytopLeftFrameCorner), frameWidth, frameHeight);
  frame.set_fill_color(frameColor);
  frame.set_color(frameColor);
  
  
  // The sequence of the attaching of shapes
  sWindow.attach(frame);
  sWindow.attach(rectangle);


  // Display
  sWindow.wait_for_button();
	return 0;
}