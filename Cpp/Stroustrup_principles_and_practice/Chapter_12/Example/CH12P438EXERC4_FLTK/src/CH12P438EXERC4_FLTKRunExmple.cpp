/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 16:03:35
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC4_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC4_FLTKRunExmple();

namespace {
}

int CH12P438EXERC4_FLTKRunExmple::excute()
{
  // Make window
  const int yUpperLeftWindowCorner = 100;
  const int xUpperLeftWindowCorner = 100;
  const int widthhWindow = 300;
  const int heigthWindow = 300;
  Graph_lib::Point topLeft(yUpperLeftWindowCorner, xUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(topLeft, widthhWindow, heigthWindow, "EXERC2");

  // Make board
  const int margin = 20;
  const int xLengthBoard = 3;
  const int yLengthBoard = 3;
  const int widthOneField = (widthhWindow - 2 * margin) / xLengthBoard;
  const int heigthOneField = (heigthWindow - 2 * margin) / yLengthBoard;
  vector<Graph_lib::Rectangle*> rectangles;
  for (int indexByX = 0; indexByX < xLengthBoard; indexByX++)
  {
    for (int indexByY = 0; indexByY < yLengthBoard; indexByY++)
    {
      Graph_lib::Rectangle* rectangle = new Graph_lib::Rectangle(Graph_lib::Point(widthOneField * indexByX + margin, heigthOneField * indexByY + margin), widthOneField, heigthOneField);
      rectangle->set_fill_color(((indexByX + indexByY) % 2 ? Graph_lib::Color::white : Graph_lib::Color::red));
      rectangles.push_back(rectangle);
      sWindow.attach(*rectangle);
    }
  }

  // Display
  sWindow.wait_for_button();
  for (Graph_lib::Rectangle* ptrRectangle : rectangles)
  {
    delete ptrRectangle;
  }
	return 0;
}