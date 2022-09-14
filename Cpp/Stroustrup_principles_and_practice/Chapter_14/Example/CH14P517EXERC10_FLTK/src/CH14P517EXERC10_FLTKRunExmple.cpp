/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/14/2022 12:43:04
	author                                          : Andrei-KS
*/

#include "CH14P517EXERC10_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Pseudo_window.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P517EXERC10_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;
}

int CH14P517EXERC10_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P517EXERC10_FLTKRunExmple");
  Graph_lib::Pseudo_window psWindow1(Graph_lib::Point{ 100,100 }, 100, 40, "Title pog");
  psWindow1.set_fill_color(Graph_lib::Color::white);
  psWindow1.set_color(Graph_lib::Color::red);
  psWindow1.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid,3 });
  
  Graph_lib::Pseudo_window psWindow2(Graph_lib::Point{ 300,100 }, 50, 40, "Title pog2");
  psWindow2.set_fill_color(Graph_lib::Color::white);
  psWindow2.set_color(Graph_lib::Color::red);
  psWindow2.set_title_font(Graph_lib::Font::Font_type::times_bold);
  psWindow2.set_title_font_size(14);

  Graph_lib::Pseudo_window psWindow3(Graph_lib::Point{ 100,300 }, 50, 40, "T");
  psWindow3.set_fill_color(Graph_lib::Color::white);
  psWindow3.set_color(Graph_lib::Color::red);

  sWindow.attach(psWindow1);
  sWindow.attach(psWindow2);
  sWindow.attach(psWindow3);

  sWindow.wait_for_button();
  return 0;
}