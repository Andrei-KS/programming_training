/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/22/2022 14:56:25
	author                                          : Andrei-KS
*/

#include "CH13P484EXERC7_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P484EXERC7_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 5;
  constexpr int yWindowLeftTopCorner = 5;
  constexpr int windowWidth = 1600;
  constexpr int windowHeight = 400;

  // The color chart setting
  constexpr int lineLength = 1;
}

int CH13P484EXERC7_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P484EXERC7_FLTKRunExmple");

  Graph_lib::Vector_ref<Graph_lib::Line> lines;
  for(int indexR = 0; indexR < 32; indexR++)
  for(int indexG = 0; indexG < 32; indexG++)
  for (int indexB = 0; indexB < 32; indexB++)
  {
    lines.push_back(new Graph_lib::Line{ Graph_lib::Point{5 + indexB + (5 + 32)* indexR,5 + 10 * indexG}, Graph_lib::Point{7 + indexB + (5 + 32) * indexR,10 + 10 * indexG} });
    lines[lines.size() - 1].set_color(fl_rgb_color(static_cast<unsigned char>(indexR * 8), static_cast<unsigned char>(indexG*8), static_cast<unsigned char>(indexB*8)));
    sWindow.attach(lines[lines.size() - 1]);
  }

  sWindow.wait_for_button();
	return 0;
}