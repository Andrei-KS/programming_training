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
  constexpr int WIDTH_BAR_GRAPH = 400;
  constexpr int HEIGHT_BAR_GRAPH = 400;
  constexpr int X_LEFT_TOP_CORNER = 100;
  constexpr int Y_LEFT_TOP_CORNER = 100;


  /*
  */
  struct Data_block {
    int height{0};
    int people_amount{0};
  };

  /*
  */
  istream& operator>>(istream& ist, Data_block& dataBlock)
  {
    char ch;
    if (ist.get(ch) && ch == '(')
    {
      int height;
      if (ist >> height)
      {
        if (ist >> ch && ch == ',')
        {
          int people_amount;
          if (ist >> people_amount)
          {
            if (ist >> ch && ch == ')')
            {
              dataBlock.height = height;
              dataBlock.people_amount = people_amount;
              return ist;
            }
          }
        }
      }
    }

    ist.putback(ch);
    ist.clear(ios_base::failbit);
    return ist;
  }

  /*
  */
  vector<Data_block> getDataBlocks(string filename)
  {
    ifstream ifs{ filename };
    if (!ifs.is_open())
    {
      error("getDataBlocks: file is not opened");
    }
    vector<Data_block> result;

    Data_block dataBlock;
    while (ifs)
    {
      char ch;
      ifs.get(ch);
      if (ch == '(')
      {
        ifs.putback(ch);
        ifs >> dataBlock;
        if (ifs || ifs.eof())
        {
          result.push_back(dataBlock);
        }
        if (ifs.fail())
        {
          cout << "format fail\n";
          ifs.clear();
        }
      }
    }

    return result;
  }
}

int CH15P548EXERC8_FLTKRunExmple::excute()
{
  Graph_lib::Simple_window sWindow(Graph_lib::Point{ 50,50 }, 600, 600, "CH15P548EXERC8_FLTKRunExmple");

  vector<Data_block> db = getDataBlocks("data.txt");

  if (!db.size())
  {
    error("vector<Data_block> is empty");
  }

  vector<Graph_lib::Bar_graph::Bar_info> BarInfos(db.size());
  for (int index = 0; index < db.size(); index++)
  {
    BarInfos[index].value = db[index].people_amount;
  }



  Graph_lib::Bar_graph bg{ Graph_lib::Point{X_LEFT_TOP_CORNER, Y_LEFT_TOP_CORNER}, WIDTH_BAR_GRAPH, HEIGHT_BAR_GRAPH, BarInfos };
  bg.set_color(Graph_lib::Color::black);
  bg.set_fill_color(Graph_lib::Color::blue);

  Graph_lib::Axis xAxis{ Graph_lib::Axis::x, Graph_lib::Point{X_LEFT_TOP_CORNER, Y_LEFT_TOP_CORNER + HEIGHT_BAR_GRAPH}, WIDTH_BAR_GRAPH, static_cast<int>(BarInfos.size()), "height 1 == 5 cm"};
  xAxis.set_color(Graph_lib::Color::red);

  int nummber_of_notches = 10;
  double value_per_notch = (bg.maxValue() - bg.minValue()) / nummber_of_notches;

  Graph_lib::Axis yAxis{ Graph_lib::Axis::y, Graph_lib::Point{X_LEFT_TOP_CORNER, Y_LEFT_TOP_CORNER + HEIGHT_BAR_GRAPH}, HEIGHT_BAR_GRAPH, nummber_of_notches, string("people_amount 1 == ") + to_string(value_per_notch)};
  yAxis.set_color(Graph_lib::Color::red);

  Graph_lib::Text labelBottom{ Graph_lib::Point{X_LEFT_TOP_CORNER, Y_LEFT_TOP_CORNER + HEIGHT_BAR_GRAPH + 14},to_string(db[0].height)};
  labelBottom.set_color(Graph_lib::Color::red);

  string labelLefttext = to_string(db[0].people_amount);
  Graph_lib::Text lableLeft{ Graph_lib::Point{X_LEFT_TOP_CORNER - static_cast<int>(labelLefttext.size())*10, Y_LEFT_TOP_CORNER + HEIGHT_BAR_GRAPH}, labelLefttext };
  lableLeft.set_color(Graph_lib::Color::red);

  sWindow.attach(bg);
  sWindow.attach(xAxis);
  sWindow.attach(yAxis);
  sWindow.attach(labelBottom);
  sWindow.attach(lableLeft);
  sWindow.wait_for_button();
	return 0;
}