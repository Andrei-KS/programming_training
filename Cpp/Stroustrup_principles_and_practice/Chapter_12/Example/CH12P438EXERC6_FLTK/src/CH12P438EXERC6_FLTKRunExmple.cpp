/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 18:00:18
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC6_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC6_FLTKRunExmple();

namespace {
}

int CH12P438EXERC6_FLTKRunExmple::excute()
{
  {
    Graph_lib::Point topLeftWindowCorner(200, 100);
    Graph_lib::Simple_window firstWindow(topLeftWindowCorner, 200, 100, "EXERC6 firstWindow");

    Graph_lib::Rectangle rectOutsideFirstWindow(Graph_lib::Point(300, 200), 100, 100);
    rectOutsideFirstWindow.set_fill_color(Graph_lib::Color::red);
    firstWindow.attach(rectOutsideFirstWindow);

    firstWindow.wait_for_button();
  }
  {
    Graph_lib::Point topLeftWindowCorner(-10000, -10000);
    Graph_lib::Simple_window secondWindow(topLeftWindowCorner, 200, 100, "EXERC6 secondWindow");
    secondWindow.wait_for_button();
  }
  return 0;
}