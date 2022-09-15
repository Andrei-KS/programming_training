/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/14/2022 16:45:36
	author                                          : Andrei-KS
*/

#include "CH14P517EXERC11_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Binary_tree.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P517EXERC11_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;
}

int CH14P517EXERC11_FLTKRunExmple::excute()
{
  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P517EXERC11_FLTKRunExmple");

  Graph_lib::Binary_tree binaryTree0{ Graph_lib::Point{10,100},0 };
  binaryTree0.set_fill_color(0);

  Graph_lib::Binary_tree binaryTree1{ Graph_lib::Point{100,100},1 };
  binaryTree1.set_fill_color(1);

  Graph_lib::Binary_tree binaryTree2{ Graph_lib::Point{200,100},2 };
  binaryTree2.set_fill_color(2);

  Graph_lib::Binary_tree binaryTree3{ Graph_lib::Point{300,100},3 };
  binaryTree3.set_fill_color(3);

  Graph_lib::Binary_tree binaryTree4{ Graph_lib::Point{100,300},4 };
  binaryTree4.set_fill_color(4);
  binaryTree4.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid,2 });
  binaryTree4.set_color(0);

  sWindow.attach(binaryTree0);
  sWindow.attach(binaryTree1);
  sWindow.attach(binaryTree2);
  sWindow.attach(binaryTree3);
  sWindow.attach(binaryTree4);

  sWindow.wait_for_button();
  binaryTree4.set_levels(5);
  binaryTree2.set_node_size(30);
  sWindow.wait_for_button();

  return 0;
}