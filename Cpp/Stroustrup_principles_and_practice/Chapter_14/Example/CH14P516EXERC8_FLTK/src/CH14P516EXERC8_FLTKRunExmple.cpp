/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/13/2022 13:36:43
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC8_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Octagon.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC8_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;
}

int CH14P516EXERC8_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P516EXERC8_FLTKRunExmple");
  
  Graph_lib::Octagon octo10{ Graph_lib::Point{100,100},10 };
  octo10.set_color(0);
  Graph_lib::Octagon octo100{ Graph_lib::Point{100,100},100 };
  octo100.set_color(0);
  Graph_lib::Octagon octo50R5{ Graph_lib::Point{100,100},50,5 };
  octo50R5.set_color(0);
  Graph_lib::Octagon octo50R5C1{ Graph_lib::Point{200,200},50,5 };
  octo50R5C1.set_color(0);
  octo50R5C1.set_fill_color(1);

  sWindow.attach(octo10);
  sWindow.attach(octo100);
  sWindow.attach(octo50R5);
  sWindow.attach(octo50R5C1);

  sWindow.wait_for_button();
  return 0;
}