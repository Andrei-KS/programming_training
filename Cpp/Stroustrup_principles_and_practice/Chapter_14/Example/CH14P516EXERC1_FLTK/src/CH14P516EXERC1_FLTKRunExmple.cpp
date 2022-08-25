/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2022 14:47:47
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC1_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Smiley.h"
#include "Frowny.h"
#include "Hat.h"
#include "SmileyWithHat.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC1_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;
}

int CH14P516EXERC1_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P516EXERC1_FLTKRunExmple");

  Graph_lib::Smiley smiley{ Graph_lib::Point{100,100},50 };
  smiley.set_fill_color(0);
  smiley.set_color(1);
  sWindow.attach(smiley);

  Graph_lib::Frowny frowny{ Graph_lib::Point{300,100},50 };
  frowny.set_fill_color(0);
  frowny.set_color(1);
  sWindow.attach(frowny);

  Graph_lib::Hats::Cap cap{ Graph_lib::Point{100,200},100,50 };
  cap.set_fill_color(1);
  sWindow.attach(cap);

  Graph_lib::SmileyWithHat smileyWithHat(Graph_lib::Point{ 300, 300 }, 50, new Graph_lib::Hats::Cap{ {0,0},80,30 });
  smileyWithHat.set_fill_color(0);
  smileyWithHat.set_color(1);
  smileyWithHat.set_hat_color(2);
  smileyWithHat.set_hat_fill_color(3);
  sWindow.attach(smileyWithHat);

  Graph_lib::SmileyWithHat smileyWithHat2(Graph_lib::Point{ 100, 300 }, 50);
  smileyWithHat2.set_fill_color(0);
  smileyWithHat2.set_color(1);
  smileyWithHat2.set_hat_color(2);
  smileyWithHat2.set_hat_fill_color(3);
  sWindow.attach(smileyWithHat2);

  sWindow.wait_for_button();

  smileyWithHat2.change_hat(new Graph_lib::Hats::Cylinder{ {0,0},80,30 });
  smileyWithHat2.set_hat_color(2);
  smileyWithHat2.set_hat_fill_color(3);

  sWindow.wait_for_button();
	return 0;
}