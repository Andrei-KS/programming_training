/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/11/2022 12:24:20
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC8_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC8_FLTKRunExmple();

namespace {
  // The simple window setting
  constexpr int xUpperLeftWindowCorner                          = 100;
  constexpr int yUpperLeftWindowCorner                          = 100;
  constexpr int windowWidth                                     = 600;
  constexpr int windowHeight                                    = 600;

  // Olympic rings setting
  constexpr int xFirstRingCenter                                = windowWidth * 1 / 4;
  constexpr int yFirstRingCenter                                = windowHeight * 2 / 5;
  constexpr int ringRadius                                      = 50;
  // From considering simple auxiliary task we can get good technique
  // for paint Olympic rings or ring chains. Given right triangle
  // where ends of cathet are rings centers and one cathet equal ring radius.
  //  A_____C__O
  //   --      |
  //     --    |
  //       --  |
  //         --B
  //  |BO| = r,
  //  |AC| = r,
  //  |AB| = 2r - delta, where delta is value how deep does one ring go into the other
  //  |CO| is xShift
  //  solution this task give next result
  //  CO = sqrt((radius - delta) * (3 * radius - delta)) - radius
  // ringDelta can be only from 0 to ringRadius
  constexpr int ringDelta                                       = ringRadius * 1 / 3;
  const int ringsAmount                                         = 5;
  const Graph_lib::Line_style::Line_style_type ringLineStyle    = Graph_lib::Line_style::dashdotdot;
  const int ringLineThickness                                   = 10;
  const vector<Graph_lib::Color> ColorSet                       = {
    Graph_lib::Color::blue,
    Graph_lib::Color::yellow,
    Graph_lib::Color::black,
    Graph_lib::Color::green,
    Graph_lib::Color::red,
  };

  int calculateXShift(int radius, int delta)
  {
    return static_cast<int>(sqrt((radius - delta) * (3 * radius - delta))) - radius;
  }
}

int CH12P438EXERC8_FLTKRunExmple::excute()
{
  // Make the simple window
  Graph_lib::Point upperLeftWindowcorner(xUpperLeftWindowCorner, yUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(upperLeftWindowcorner, windowWidth, windowHeight, "EXERC8");

  vector<Graph_lib::Circle*> olympicRings;
  int xRingShift = calculateXShift(ringRadius, ringDelta);
  cout << xRingShift;
  for (int index = 0; index < ringsAmount; index++)
  {
    Graph_lib::Circle* ring = new Graph_lib::Circle(Graph_lib::Point(xFirstRingCenter + (xRingShift + ringRadius) * index, yFirstRingCenter + ringRadius * (index%2)), ringRadius);
    ring->set_color(ColorSet[index % ColorSet.size()]);
    ring->set_style(Graph_lib::Line_style(ringLineStyle, ringLineThickness));
    olympicRings.push_back(ring);
  }


  for (Graph_lib::Circle* item : olympicRings)
  {
    sWindow.attach(*item);
  }

  sWindow.wait_for_button();


  for (Graph_lib::Circle* item : olympicRings)
  {
    delete item;
  }
  olympicRings.clear();

	return 0;
}