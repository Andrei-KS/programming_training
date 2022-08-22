/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/19/2022 16:19:47
	author                                          : Andrei-KS
*/

#include "CH13P484EXERC6_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "TextBox.h"
#include "GUI_Utility_function.h"
#include "Arrow.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P484EXERC6_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 800;
  constexpr int windowHeight = 800;

  vector<Graph_lib::Point(*)(const Graph_lib::TextBox&)> textBoxFuncs = {
    Graph_lib::n,
    Graph_lib::ne,
    Graph_lib::nw,
    Graph_lib::s,
    Graph_lib::se,
    Graph_lib::sw,
    Graph_lib::e,
    Graph_lib::w,
    Graph_lib::center,
  };
}

int CH13P484EXERC6_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH13P484EXERC6_FLTKRunExmple");

  {
    Graph_lib::TextBox textBox(Graph_lib::Point{ 100,100 }, "AaBbCcDdEeFfGgHhIiJjKkLlMmOoPpQqRrSsTtuuVvWwXxYyZz", 50);
    textBox.set_color(Graph_lib::Color::black);
    sWindow.attach(textBox);
    sWindow.wait_for_button();

    textBox.set_label("Alp");
    sWindow.wait_for_button();

    textBox.set_font_size(20);
    sWindow.wait_for_button();

    textBox.set_font(Graph_lib::Font::helvetica_bold_italic);
    sWindow.wait_for_button();

    textBox.set_label("");
    sWindow.wait_for_button();

    Graph_lib::Vector_ref<Graph_lib::Circle> circles;
    const int circleRadiusC = 2;
    for (Graph_lib::Point(*func)(const Graph_lib::TextBox&) : textBoxFuncs)
    {
      circles.push_back(new Graph_lib::Circle(func(textBox), circleRadiusC));
      circles[circles.size() - 1].set_color(Graph_lib::Color::black);
      circles[circles.size() - 1].set_fill_color(Graph_lib::Color::blue);
      sWindow.attach(circles[circles.size() - 1]);
    }
    sWindow.wait_for_button();
    sWindow.detach(textBox);
    for (int index = 0; index < circles.size(); index++)
    {
      sWindow.detach(circles[index]);
    }
  }

  {
    Graph_lib::Vector_ref<Graph_lib::Arrow> arrows;
    const int arrowLength = 10;
    Graph_lib::Vector_ref<Graph_lib::TextBox> board;
    // 0
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Window",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Line_style",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Color",5 });

    // 3
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Simple_window",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Shape",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Point",5 });
    
    // 6
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Line",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Lines",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Polygon",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Axis",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Rectangle",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Text",5 });
    board.push_back(new Graph_lib::TextBox{ Graph_lib::Point{0,0},"Image",5 });
    
    for (int index = 0; index < board.size(); index++)
    {
      board[index].set_color(Graph_lib::Color::black);
      board[index].set_fill_color(Graph_lib::Color::dark_yellow);
      board[index].set_font(Graph_lib::Font::times_bold);
      board[index].set_font_size(16);
      sWindow.attach(board[index]);
    }

    int thirdLineIndent = 20;
    int secondLineIndent = thirdLineIndent + board[6].width() / 2;
    int firstLineIndent = secondLineIndent + board[3].width() / 2 - board[0].width() / 2;

    int heightShift = 50;
    int shift = 60;
    int currLeftPosition = firstLineIndent;
    for (int index = 0; index < 3; index++)
    {
      board[index].move(currLeftPosition, heightShift);
      currLeftPosition += shift + board[index].width();
    }

    heightShift = Graph_lib::s(board[0]).y + 75;
    shift = 70;
    currLeftPosition = secondLineIndent;
    for (int index = 3; index < 6; index++)
    {
      board[index].move(currLeftPosition, heightShift);
      currLeftPosition += shift + board[index].width();
    }

    arrows.push_back(new Graph_lib::Arrow{ Graph_lib::n(board[3]),Graph_lib::s(board[0]),arrowLength,5 });
    

    heightShift = Graph_lib::s(board[3]).y + 75;
    shift = 10;
    currLeftPosition = thirdLineIndent;
    for (int index = 6; index < board.size(); index++)
    {
      board[index].move(currLeftPosition, heightShift);
      Graph_lib::Point swPoint = Graph_lib::sw(board[4]);
      arrows.push_back(new Graph_lib::Arrow{ Graph_lib::n(board[index]),Graph_lib::Point{swPoint.x + board[4].width() * (index - 6) / (board.size() - 6),swPoint.y},arrowLength,5});
      currLeftPosition += shift + board[index].width();
    }

    for (int index = 0; index < arrows.size(); index++)
    {
      arrows[index].set_color(Graph_lib::Color::black);
      arrows[index].set_fill_color(Graph_lib::Color::black);
      sWindow.attach(arrows[index]);
    }
    sWindow.wait_for_button();
  }
	return 0;
}