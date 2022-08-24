/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/24/2022 12:17:39
	author                                          : Andrei-KS
*/

#include "CH13P485EXERC16_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Regular_hexagon.h"
#include "Vector2D.h"
#include "Utility_lib_Constatnt.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P485EXERC16_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;

  // The tile setting
  constexpr int lengthToCorner = 300;


  int toInt(double value)
  {
    int result = static_cast<int>(value * 10);
    return result / 10 + ((result % 10) > 5 ? 1 : 0);
  }
}

int CH13P485EXERC16_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P485EXERC16_FLTKRunExmple");

  Graph_lib::Vector_ref<Graph_lib::Regular_hexagon> tile;

  const double cellRotate = 0;
  Utility_lib::Vector2D mainDirection = Utility_lib::getRotateVector(Utility_lib::Vector2D{ 1,0 }, cellRotate);
  Utility_lib::Vector2D ortogonalDiraction = mainDirection.getNormal();
  double lenghtHeightToSide = lengthToCorner * cos(60 * Utility_lib::PI / 180);
  double lenghtSide = lengthToCorner * sin(60 * Utility_lib::PI / 180);
  double halfLengthSide = lenghtSide / 2;


  const int xCenter = 0;
  const int yCenter = 0;
  const int amountToMainDirection = toInt(windowWidth / (lengthToCorner + halfLengthSide)) + 2;
  const int amountToOrtogonalDirection = toInt(windowHeight / (2 * lenghtSide)) + 2;

  for (int indexToMainDirection = 0; indexToMainDirection < amountToMainDirection; indexToMainDirection++)
  {
    double projectToMain = (lengthToCorner + halfLengthSide) * indexToMainDirection;
    double shiftToOrtogonal = lenghtSide * (indexToMainDirection % 2);
    for (int indexToOrtogonalDirection = 0; indexToOrtogonalDirection < amountToOrtogonalDirection; indexToOrtogonalDirection++)
    {
      double projectToOrtogonal = 2 * lenghtSide * indexToOrtogonalDirection + shiftToOrtogonal;
      int x = toInt(mainDirection.x * projectToMain + ortogonalDiraction.x * projectToOrtogonal + xCenter);
      int y = toInt(mainDirection.y * projectToMain + ortogonalDiraction.y * projectToOrtogonal + yCenter);
      tile.push_back(new Graph_lib::Regular_hexagon{ Graph_lib::Point{x, y}, lengthToCorner, cellRotate });

    }
  }


  for (int index = 0; index < tile.size(); index++)
  {
    tile[index].set_color(Graph_lib::Color::red);
    tile[index].set_fill_color(Graph_lib::Color::green);
    sWindow.attach(tile[index]);
  }
  sWindow.wait_for_button();
	return 0;
}