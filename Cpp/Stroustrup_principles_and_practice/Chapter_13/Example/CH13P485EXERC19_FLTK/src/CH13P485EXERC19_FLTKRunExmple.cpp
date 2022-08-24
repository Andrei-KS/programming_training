/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/24/2022 15:15:49
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC19_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Star.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC19_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;
}

int CH13P485EXERC19_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC19_FLTKRunExmple");

  Graph_lib::Vector_ref<Graph_lib::Star> stars;

  const int amountStars = 5;

  for (int indexStar = 0; indexStar < amountStars; indexStar++)
  {
    stars.push_back(new Graph_lib::Star{ Graph_lib::Point{100 + 80 * indexStar,100 + 80 * indexStar},2 + indexStar,50,10 });
    stars[stars.size()-1].set_fill_color(indexStar);
    stars[stars.size() - 1].set_color(indexStar + 1);
    sWindow.attach(stars[stars.size() - 1]);
  }

  sWindow.wait_for_button();
	return 0;
}