/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/08/2022 15:39:08
	author                                          : Andrei-KS
*/

#include "CH12P415_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P415_FLTKRunExmple();

namespace {
}

int CH12P415_FLTKRunExmple::excute()
{
  using namespace Graph_lib; // our graphics facilities are in Graph_lib
  Point tl{ 100,100 }; // to become top left corner of window
  Simple_window win{ tl,600,400,"Canvas" }; // make a simple window
  Graph_lib::Polygon poly; // make a shape (a polygon)
  poly.add(Point{ 300,200 }); // add a point
  poly.add(Point{ 350,100 }); // add another point
  poly.add(Point{ 400,200 }); // add a third point
  poly.set_color(Color::red); // adjust properties of poly
  win.attach(poly); // connect poly to the window
  win.wait_for_button(); // give control to the display engine
  return 0;
}