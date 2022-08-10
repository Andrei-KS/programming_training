/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 14:41:14
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC3_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC3_FLTKRunExmple();

namespace {
}

int CH12P438EXERC3_FLTKRunExmple::excute()
{
  // Make window
  const int xUpperLeftWindowCorner = 100;
  const int yUpperLeftWindowCorner = 100;
  const int xMaxWindow = 400;
  const int yMaxWindow = 300;
  Graph_lib::Point topLeft(yUpperLeftWindowCorner, xUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(topLeft, xMaxWindow, yMaxWindow, "EXERC3");

  // Make initials
  int xBottomLeftText = xMaxWindow * 2 / 7;
  int yBottomLeftText = yMaxWindow * 7 / 11;
  Graph_lib::Text text(Graph_lib::Point(xBottomLeftText, yBottomLeftText), "  .  .");
  text.set_color(Graph_lib::Color::red);
  text.set_font(Graph_lib::Font::times_bold);
  text.set_font_size(150);
  sWindow.attach(text);

  int xShift = -30;
  Graph_lib::Text firstInitial(Graph_lib::Point(xBottomLeftText + xShift, yBottomLeftText), "A");
  firstInitial.set_color(Graph_lib::Color::dark_red);
  firstInitial.set_font(Graph_lib::Font::times_bold);
  firstInitial.set_font_size(150);
  sWindow.attach(firstInitial);

  xShift = 110;
  Graph_lib::Text secondInitial(Graph_lib::Point(xBottomLeftText + xShift, yBottomLeftText), "S");
  secondInitial.set_color(Graph_lib::Color::dark_blue);
  secondInitial.set_font(Graph_lib::Font::times_bold);
  secondInitial.set_font_size(150);
  sWindow.attach(secondInitial);

  // Display
  sWindow.wait_for_button();
	return 0;
}