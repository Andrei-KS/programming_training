/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/26/2022 15:09:48
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC6_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Striped_circle.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC6_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;
}

int CH14P516EXERC6_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P516EXERC5_FLTKRunExmple");

  Graph_lib::Striped_circle stripedCircle{ Graph_lib::Point{200,200},100 };

  stripedCircle.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 3 });
  stripedCircle.set_color(0);

  stripedCircle.set_fill_line_style(Graph_lib::Line_style{ Graph_lib::Line_style::dot, 2 });
  stripedCircle.set_distance_between_strips(-1);
  stripedCircle.set_fill_color(1);

  sWindow.attach(stripedCircle);


  sWindow.wait_for_button();
	return 0;
}