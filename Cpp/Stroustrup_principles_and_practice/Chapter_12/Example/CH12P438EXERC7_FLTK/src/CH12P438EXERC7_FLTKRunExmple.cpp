/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 18:25:53
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC7_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC7_FLTKRunExmple();

namespace {
  // The simple window setting
  constexpr int xUpperLeftWindowCorner          = 100;
  constexpr int yUpperLeftWindowCorner          = 100;
  constexpr int windowWidth                     = 600;
  constexpr int windowHeight                    = 400;

  // The upper background setting
  constexpr int upperBackgroundWidth            = windowWidth;
  constexpr int upperBackgroundHeight           = windowHeight * 2 / 3;
  const Graph_lib::Color upperBackgroundColor   = Graph_lib::Color::cyan;
  constexpr int xUpperBackgroundUpperLeftCorner = 0;
  constexpr int yUpperBackgroundUpperLeftCorner = 0;

  // The lower background setting
  constexpr int lowerBackgroundWidth            = windowWidth;
  constexpr int lowerBackgroundHeight           = windowHeight - upperBackgroundHeight;
  const Graph_lib::Color lowerBackgroundColor   = Graph_lib::Color::dark_green;
  constexpr int xLowerBackgroundUpperLeftCorner = 0;
  constexpr int yLowerBackgroundUpperLeftCorner = upperBackgroundHeight;

  // The main wall setting
  constexpr int mainWallShiftToleft             = windowWidth * 1 / 12;
  constexpr int mainWallShiftToUpper            = windowHeight * 1 / 12;
  constexpr int mainWallWidth                   = windowWidth * 1 / 3;
  constexpr int mainWallHeight                  = windowHeight * 1 / 3;
  const Graph_lib::Color mainWallColor          = Graph_lib::Color::dark_magenta;
  constexpr int xMainWallUpperLeftCorner        = (windowWidth - mainWallWidth)/2 - mainWallShiftToleft;
  constexpr int yMainWallUpperLeftCorner        = windowHeight - mainWallHeight - mainWallShiftToUpper;

  // The roof setting
  constexpr int roofWidth                       = mainWallWidth * 6 / 5;
  constexpr int roofHeight                      = mainWallHeight * 4 / 5;
  const Graph_lib::Color roofColor              = Graph_lib::Color::dark_red;
  constexpr int xUpperAngle                     = xMainWallUpperLeftCorner + mainWallWidth / 2;
  constexpr int yUpperAngle                     = yMainWallUpperLeftCorner - roofHeight;

  // The chimney setting
  constexpr int chimneyWidth                    = roofWidth * 1 / 6;
  constexpr int chimneyHeight                   = roofHeight;
  const Graph_lib::Color chimneyColor           = mainWallColor;
  constexpr int xChimneyUpperLeftCorner         = xMainWallUpperLeftCorner + mainWallWidth - 3 * chimneyWidth / 2;
  constexpr int yChimneyUpperLeftCorner         = yMainWallUpperLeftCorner - chimneyHeight;

  // The smoke setting
  constexpr int smokeCircleAmount               = 4;
  constexpr int firstSmokeCircleRadius          = chimneyWidth / 2;
  constexpr int lastSmokeCircleRadius           = chimneyWidth;
  const Graph_lib::Color smokeColor             = Graph_lib::Color::black;
  constexpr int xfirstSmokeCircleCenter         = xChimneyUpperLeftCorner + chimneyWidth / 2;
  constexpr int yfirstSmokeCircleCenter         = yChimneyUpperLeftCorner;
  constexpr int xlastSmokeCircleCenter          = xMainWallUpperLeftCorner + mainWallWidth;
  constexpr int ylastSmokeCircleCenter          = 0;
  constexpr int xDiffSmokePosition              = xlastSmokeCircleCenter - xfirstSmokeCircleCenter;
  constexpr int yDiffSmokePosition              = ylastSmokeCircleCenter - yfirstSmokeCircleCenter;
  constexpr int diffSmokeRadius                 = lastSmokeCircleRadius - firstSmokeCircleRadius;

  // The left window setting
  constexpr int leftWindowWidth                 = mainWallWidth * 1 / 4;
  constexpr int leftWindowHeight                = mainWallHeight * 1 / 3;
  const Graph_lib::Color leftWindowColor        = Graph_lib::Color::blue;
  constexpr int xLeftWindowUpperLeftCorner      = xMainWallUpperLeftCorner + leftWindowWidth * 1 / 4;
  constexpr int yLeftWindowUpperLeftCorner      = yMainWallUpperLeftCorner + (mainWallHeight - leftWindowHeight) * 1 / 3;

  // The right window setting
  constexpr int rightWindowWidth                = leftWindowWidth;
  constexpr int rightWindowHeight               = leftWindowHeight;
  const Graph_lib::Color rightWindowColor       = Graph_lib::Color::blue;
  constexpr int xRightWindowUpperLeftCorner     = xMainWallUpperLeftCorner + mainWallWidth - rightWindowWidth * 5 / 4;
  constexpr int yRightWindowUpperLeftCorner     = yLeftWindowUpperLeftCorner;

  // The Door setting
  constexpr int doorWidth                       = mainWallWidth - (leftWindowWidth + rightWindowWidth) * 6 / 4;
  constexpr int doorHeight                      = mainWallHeight - (mainWallHeight - leftWindowHeight) * 1 / 3;
  const Graph_lib::Color doorColor              = Graph_lib::Color::dark_yellow;
  constexpr int xDoorUpperLeftCorner            = xMainWallUpperLeftCorner + leftWindowWidth * 6 / 4;
  constexpr int yDoorUpperLeftCorner            = yLeftWindowUpperLeftCorner;
}

int CH12P438EXERC7_FLTKRunExmple::excute()
{
  // Make the simple window
  Graph_lib::Point upperLeftWindowcorner(xUpperLeftWindowCorner, yUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(upperLeftWindowcorner, windowWidth, windowHeight, "EXERC7");

  // Make the upper background setting
  Graph_lib::Rectangle upperBackground(Graph_lib::Point(xUpperBackgroundUpperLeftCorner, yUpperBackgroundUpperLeftCorner), upperBackgroundWidth, upperBackgroundHeight);
  upperBackground.set_fill_color(upperBackgroundColor);
  upperBackground.set_color(upperBackgroundColor);

  // Make the lower background setting
  Graph_lib::Rectangle lowerBackground(Graph_lib::Point(xLowerBackgroundUpperLeftCorner, yLowerBackgroundUpperLeftCorner), lowerBackgroundWidth, lowerBackgroundHeight);
  lowerBackground.set_fill_color(lowerBackgroundColor);
  lowerBackground.set_color(lowerBackgroundColor);
  

  // Make smoke
  vector<Graph_lib::Circle*> smokeVect;
  for (int indexSmokeCircle = 0; indexSmokeCircle < smokeCircleAmount; indexSmokeCircle++)
  {
    Graph_lib::Circle* smoke = new Graph_lib::Circle(
      Graph_lib::Point(
        xfirstSmokeCircleCenter + xDiffSmokePosition * indexSmokeCircle / smokeCircleAmount,
        yfirstSmokeCircleCenter + yDiffSmokePosition * indexSmokeCircle / smokeCircleAmount),
      firstSmokeCircleRadius + diffSmokeRadius * indexSmokeCircle / smokeCircleAmount
    );
    smoke->set_fill_color(smokeColor);
    smoke->set_color(smokeColor);
    smokeVect.push_back(smoke);
  }

  // Make the main wall
  Graph_lib::Rectangle mainWall(Graph_lib::Point(xMainWallUpperLeftCorner, yMainWallUpperLeftCorner), mainWallWidth, mainWallHeight);
  mainWall.set_fill_color(mainWallColor);
  mainWall.set_color(mainWallColor);

  // Make the left window
  Graph_lib::Rectangle leftWindow(Graph_lib::Point(xLeftWindowUpperLeftCorner, yLeftWindowUpperLeftCorner), leftWindowWidth, leftWindowHeight);
  leftWindow.set_fill_color(leftWindowColor);
  leftWindow.set_color(leftWindowColor);

  // Make the right window
  Graph_lib::Rectangle rightWindow(Graph_lib::Point(xRightWindowUpperLeftCorner, yRightWindowUpperLeftCorner), rightWindowWidth, rightWindowHeight);
  rightWindow.set_fill_color(rightWindowColor);
  rightWindow.set_color(rightWindowColor);

  // Make the door
  Graph_lib::Rectangle door(Graph_lib::Point(xDoorUpperLeftCorner, yDoorUpperLeftCorner), doorWidth, doorHeight);
  door.set_fill_color(doorColor);
  door.set_color(doorColor);

  // Make the roof
  Graph_lib::Polygon roof;
  roof.add(Graph_lib::Point(xUpperAngle, yUpperAngle));
  roof.add(Graph_lib::Point(xUpperAngle - roofWidth / 2, yUpperAngle + roofHeight));
  roof.add(Graph_lib::Point(xUpperAngle + roofWidth / 2, yUpperAngle + roofHeight));
  roof.set_fill_color(roofColor);
  roof.set_color(roofColor);

  // Make the chimney
  Graph_lib::Rectangle chimney(Graph_lib::Point(xChimneyUpperLeftCorner, yChimneyUpperLeftCorner), chimneyWidth, chimneyHeight);
  chimney.set_fill_color(mainWallColor);
  chimney.set_color(mainWallColor);


  sWindow.attach(upperBackground);
  sWindow.attach(lowerBackground);
  for (Graph_lib::Circle* item : smokeVect)
  {
    sWindow.attach(*item);
  }
  sWindow.attach(mainWall);
  sWindow.attach(leftWindow);
  sWindow.attach(rightWindow);
  sWindow.attach(door);
  sWindow.attach(chimney);
  sWindow.attach(roof);

  sWindow.wait_for_button();
	

  for (Graph_lib::Circle* item : smokeVect)
  {
    delete item;
  }
  return 0;
}