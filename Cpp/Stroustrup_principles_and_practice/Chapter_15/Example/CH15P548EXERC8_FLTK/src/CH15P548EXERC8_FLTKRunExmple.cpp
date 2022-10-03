/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 20:07:11
	author                                          : Andrei-KS
*/

#include "CH15P548EXERC8_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Bar_graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P548EXERC8_FLTKRunExmple();

namespace {
  struct Data_block {
    int height{0};
    int people_amount{0};
  };

  istream& operator>>(istream& ist, Data_block dataBlock)
  {

    return ist;
  }

  vector<Data_block> getDataBlocks(string filename)
  {
    ifstream ifs{ filename };
    if (!ifs.is_open())
    {
      error("getDataBlocks: file is not opened");
    }
    vector<Data_block> result;
    return result;
  }
}

int CH15P548EXERC8_FLTKRunExmple::excute()
{
  Graph_lib::Simple_window sWindow(Graph_lib::Point{ 50,50 }, 600, 600, "CH15P548EXERC8_FLTKRunExmple");

  Graph_lib::Bar_graph bg{ Graph_lib::Point{100,100},200,200, vector<double>{0.0} };
  bg.set_color(Graph_lib::Color::black);
  bg.set_fill_color(Graph_lib::Color::blue);
  sWindow.attach(bg);
  sWindow.wait_for_button();
	return 0;
}