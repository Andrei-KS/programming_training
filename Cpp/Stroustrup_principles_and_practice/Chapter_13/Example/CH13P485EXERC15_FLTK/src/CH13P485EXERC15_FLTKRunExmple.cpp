/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 18:55:45
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC15_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Right_triangle.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC15_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 400;

  // The tile setting
  constexpr int amountToX = 3;
  constexpr int amountToY = 4;
}

int CH13P485EXERC15_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC15_FLTKRunExmple");

  Graph_lib::Vector_ref<Graph_lib::Right_triangle> tile;
  int sideLength2 = windowWidth / amountToX;
  int sideLength1 = windowHeight / amountToY;
  for (int xIndex = 0; xIndex < amountToX; xIndex++)
  {
    for (int yIndex = 0; yIndex < amountToY; yIndex++)
    {
      tile.push_back(new Graph_lib::Right_triangle{ Graph_lib::Point{sideLength2 * xIndex , sideLength1 * yIndex },sideLength1,sideLength2, 270 });
      tile[tile.size() - 1].set_color(Graph_lib::Color::red);
      tile[tile.size() - 1].set_fill_color(Graph_lib::Color::dark_cyan);
      sWindow.attach(tile[tile.size() - 1]);
      tile.push_back(new Graph_lib::Right_triangle{ Graph_lib::Point{sideLength2 * (xIndex+1) , sideLength1 * (yIndex+1) },sideLength1,sideLength2, 90 });
      tile[tile.size() - 1].set_color(Graph_lib::Color::red);
      tile[tile.size() - 1].set_fill_color(Graph_lib::Color::cyan);
      sWindow.attach(tile[tile.size() - 1]);
    }
  }
  sWindow.wait_for_button();
	return 0;
}