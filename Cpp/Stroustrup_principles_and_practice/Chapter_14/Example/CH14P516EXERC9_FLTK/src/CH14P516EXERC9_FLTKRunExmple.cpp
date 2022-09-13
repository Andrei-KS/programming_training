/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/13/2022 17:49:21
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC9_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Group.h"
#include "Striped_circle.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC9_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;

  // Board setting
  constexpr int xBoardLeftTopCorner = 100;
  constexpr int yBoardLeftTopCorner = 100;
  constexpr int cellSize = 50;


}

int CH14P516EXERC9_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P516EXERC9_FLTKRunExmple");

  Graph_lib::Group board;
  for (int colIndex = 0; colIndex < 8; colIndex++)
  {
    for (int rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      board.attach(new Graph_lib::Rectangle(Graph_lib::Point{ cellSize * colIndex + xBoardLeftTopCorner , cellSize * rowIndex + yBoardLeftTopCorner }, cellSize, cellSize));
      board[board.size() - 1].set_fill_color((colIndex + rowIndex) % 2 ? Graph_lib::Color::black : Graph_lib::Color::white);
    }
  }
  
  Graph_lib::Group blackGroup;
  for (int rowIndex = 0; rowIndex < 3; rowIndex ++)
  {
    for (int colIndex = 0; colIndex < 4; colIndex++)
    {
      blackGroup.attach(new Graph_lib::Striped_circle(Graph_lib::Point{ cellSize * (rowIndex % 2)+cellSize * colIndex * 2 + xBoardLeftTopCorner + cellSize / 2, cellSize * rowIndex + yBoardLeftTopCorner + cellSize / 2 }, cellSize / 2));
      Graph_lib::Striped_circle* item = dynamic_cast<Graph_lib::Striped_circle*>(&blackGroup[blackGroup.size() - 1]);
      if (item != nullptr)
      {
        item->set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 3 });
        item->set_fill_color(Graph_lib::Color::dark_blue);
        item->set_fill_line_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 1 });
        item->set_distance_between_strips(1);
      }
    }
  }

  Graph_lib::Group whiteGroup;
  for (int rowIndex = 5; rowIndex < 8; rowIndex++)
  {
    for (int colIndex = 0; colIndex < 4; colIndex++)
    {
      whiteGroup.attach(new Graph_lib::Striped_circle(Graph_lib::Point{ cellSize * (rowIndex % 2) + cellSize * colIndex * 2 + xBoardLeftTopCorner + cellSize / 2, cellSize * rowIndex + yBoardLeftTopCorner + cellSize / 2 }, cellSize / 2));
      Graph_lib::Striped_circle* item = dynamic_cast<Graph_lib::Striped_circle*>(&whiteGroup[whiteGroup.size() - 1]);
      if (item != nullptr)
      {
        item->set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 3 });
        item->set_fill_color(Graph_lib::Color::blue);
        item->set_fill_line_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 1 });
        item->set_distance_between_strips(1);
      }
    }
  }

  sWindow.attach(board);
  sWindow.attach(blackGroup);
  sWindow.attach(whiteGroup);

  sWindow.wait_for_button();
  blackGroup.move(0, cellSize);

  sWindow.wait_for_button();
  return 0;
}