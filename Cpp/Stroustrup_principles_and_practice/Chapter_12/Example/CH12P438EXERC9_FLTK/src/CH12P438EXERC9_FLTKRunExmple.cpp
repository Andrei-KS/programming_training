/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/11/2022 15:14:51
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC9_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC9_FLTKRunExmple();

namespace {
  // The simple window setting
  constexpr int xUpperLeftWindowCorner = 100;
  constexpr int yUpperLeftWindowCorner = 100;
  constexpr int windowWidth = 500;
  constexpr int windowHeight = 400;

  // The image setting
  const string imageName = "Image.jpg";
  constexpr int xUpperLeftImageCorner = windowWidth * 1 / 5;
  constexpr int yUpperLeftImageCorner = windowHeight * 1 / 5;

}

int CH12P438EXERC9_FLTKRunExmple::excute()
{
  // Make the simple window
  Graph_lib::Point upperLeftWindowcorner(xUpperLeftWindowCorner, yUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(upperLeftWindowcorner, windowWidth, windowHeight, "EXERC9 - Image.jpg");

  Graph_lib::Image image{ Graph_lib::Point{xUpperLeftImageCorner,yUpperLeftImageCorner},imageName };
  Graph_lib::Text title(Graph_lib::Point(xUpperLeftImageCorner, yUpperLeftImageCorner - 14), imageName);
  title.set_font_size(14);
  title.set_color(Graph_lib::Color::dark_blue);
  
  sWindow.attach(title);
  sWindow.attach(image);

  sWindow.wait_for_button();
	return 0;
}