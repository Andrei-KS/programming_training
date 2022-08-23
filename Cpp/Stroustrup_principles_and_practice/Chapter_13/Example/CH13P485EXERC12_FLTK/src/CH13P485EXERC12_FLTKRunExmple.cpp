/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 17:09:14
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC12_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Vector2D.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC12_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 400;

  // The circle setting
  constexpr int xCenter = windowWidth / 2;
  constexpr int yCenter = windowHeight / 2;
  constexpr int radius = 100;

  // The mark setting
  constexpr int amountFrame = 10;

}

int CH13P485EXERC12_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC12_FLTKRunExmple");

  Graph_lib::Circle circle{ Graph_lib::Point{xCenter,yCenter},radius };
  circle.set_color(Graph_lib::Color::blue);
  circle.set_fill_color(Graph_lib::Color::green);
  sWindow.attach(circle);

  double rotateAngle = 360 / amountFrame;
  Utility_lib::Vector2D prevDirection = Utility_lib::getRotateVector(Utility_lib::Vector2D{ radius, 0 }, -rotateAngle);
  Graph_lib::Mark mark{ Graph_lib::Point{static_cast<int>(prevDirection.x) + xCenter,static_cast<int>(prevDirection.y) + yCenter}, 'O'};
  sWindow.attach(mark);
  for (int indexFrame = 0; indexFrame <= amountFrame; indexFrame++)
  {
    Utility_lib::Vector2D currDirection = getRotateVector(prevDirection, rotateAngle);
    mark.move(static_cast<int>(currDirection.x - prevDirection.x), static_cast<int>(currDirection.y - prevDirection.y));
    prevDirection = currDirection;
    sWindow.wait_for_button();
  }
	return 0;
}