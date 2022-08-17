/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2022 17:24:53
	author                                          : Andrei-KS
*/

#include "CH13P483DRILL1_5_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Vector_ref.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P483DRILL1_5_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 1000;
  constexpr int windowHeight = 800;

  // The grid setting
  constexpr int gridHorizontalCellAmount = 8;
  constexpr int gridVerticalCellAmount = 8;
  constexpr int gridOneCellWidth = 100;
  constexpr int gridOneCellHeight = 100;

}

int CH13P483DRILL1_5_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow( windowLeftTopCorner, windowWidth, windowHeight, "CH13P483DRILL1_5_FLTKRunExmple" );


  // make the grid
  Graph_lib::Lines grid;
  for (int horizontalLineIndex = 0; horizontalLineIndex <= gridHorizontalCellAmount; ++horizontalLineIndex)
  {
    grid.add(Graph_lib::Point{ 0, horizontalLineIndex * gridOneCellHeight }, Graph_lib::Point{ gridOneCellWidth * gridVerticalCellAmount, horizontalLineIndex * gridOneCellHeight });
  }
  for (int verticlalLineIndex = 0; verticlalLineIndex <= gridVerticalCellAmount; ++verticlalLineIndex)
  {
    grid.add(Graph_lib::Point{ verticlalLineIndex* gridOneCellWidth, 0 }, Graph_lib::Point{ verticlalLineIndex * gridOneCellWidth,  gridOneCellHeight * gridHorizontalCellAmount });
  }

  grid.set_color(Graph_lib::Color::black);
  sWindow.attach(grid);

  // make red rectangle
  Utility_lib::Vector_ref<Graph_lib::Rectangle> redRectangles;
  for (int redRectangleIndex = 0; redRectangleIndex < gridHorizontalCellAmount; ++redRectangleIndex)
  {
    redRectangles.push_back(new Graph_lib::Rectangle(Graph_lib::Point{ gridOneCellWidth * redRectangleIndex, gridOneCellHeight * redRectangleIndex }, gridOneCellWidth, gridOneCellHeight));
    redRectangles[redRectangles.size() - 1].set_fill_color(Graph_lib::Color::red);
    redRectangles[redRectangles.size() - 1].set_color(Graph_lib::Color::invisible);
    sWindow.attach(redRectangles[redRectangles.size() - 1]);
  }

  // make three copies of the image
  Utility_lib::Vector_ref<Graph_lib::Image> images;
  for (int imageIndex = 0; imageIndex < 3; ++imageIndex)
  {
    images.push_back(new Graph_lib::Image(Graph_lib::Point{ 2 * gridOneCellWidth * (imageIndex + 1), 2 * gridOneCellHeight * imageIndex }, "Image.jpg"));
    images[images.size() - 1].set_mask(Graph_lib::Point{ 0,0 }, 2 * gridOneCellWidth, 2 * gridOneCellHeight);
    sWindow.attach(images[images.size() - 1]);
  }


  // make 100-by-100 image
  Graph_lib::Image image100by100(Graph_lib::Point{ gridOneCellWidth,0 }, "Image100by100.jpg");
  image100by100.set_mask(Graph_lib::Point{ 0,0 }, gridOneCellWidth, gridOneCellHeight);
  sWindow.attach(image100by100);

  sWindow.put_on_top(grid);

  for (int i = 1; i < gridHorizontalCellAmount; i++)
  {
    sWindow.wait_for_button();
    image100by100.move(gridOneCellWidth, 0);
  }
	return 0;
}