/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/24/2022 13:12:40
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC18_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Poly.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC18_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;
}

int CH13P485EXERC18_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC18_FLTKRunExmple");

  Graph_lib::Poly poly{ {Graph_lib::Point{100,100},Graph_lib::Point{100,120},Graph_lib::Point{130,120},Graph_lib::Point{120,80}} };
  poly.set_fill_color(0);
  sWindow.attach(poly);

  try 
  {
    Graph_lib::Poly polyError{ {Graph_lib::Point{100,100},Graph_lib::Point{100,120}} };
    polyError.set_fill_color(0);
    sWindow.attach(polyError);
  }
  catch (std::exception& e)
  {
    cout << e.what() << "\n";
  }


  sWindow.wait_for_button();
	return 0;
}