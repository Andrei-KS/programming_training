/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/07/2022 17:43:39
	author                                          : Andrei-KS
*/

#include "CH16P578EXERC2_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "My_window.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P578EXERC2_FLTKRunExmple();

namespace {
  /*
  */
  struct CheckerBoard : Graph_lib::My_window {
    /*
    */
    CheckerBoard(Graph_lib::Point xy, int width, int height, int cellSize, const string& title)
      : My_window(xy, width, height, title)
      , mRowsNumber(4)
      , mColumnsNumber(4)
      , mCellSize(cellSize)
      , mSelectedChecker(-1)
      , mOutBox(Graph_lib::Point{ x_max() - 200, 0 }, 100, 20,"current position:")
    {
      for (int rowIndex = 0; rowIndex < mRowsNumber; rowIndex++)
      {
        for (int colIndex = 0; colIndex < mColumnsNumber; colIndex++)
        {
          Graph_lib::Button* pButton = new Graph_lib::Button{ {colIndex * mCellSize,rowIndex * mCellSize},mCellSize,mCellSize,"",cb_pushed_checker };
          mCheckers.push_back(pButton);
          attach(*pButton);

          Graph_lib::Rectangle* pRectangle = new Graph_lib::Rectangle{ {colIndex * mCellSize,rowIndex * mCellSize},mCellSize,mCellSize };
          mRectangles.push_back(pRectangle);
          pRectangle->set_fill_color((rowIndex + colIndex) % 2 ? firstTypeCell : secondTypeCell);
          attach(*pRectangle);
        }
      }
      attach(mOutBox);
      mOutBox.put("not info");
    }

    /*
    */
    void next()
    {
      if (mSelectedChecker >= 0)
      {
        mRectangles[mSelectedChecker].set_fill_color((mSelectedChecker % mColumnsNumber + (mSelectedChecker / mColumnsNumber)) % 2 ? firstTypeCell : secondTypeCell);
      }
      mSelectedChecker = -1;
      mOutBox.put("not info");
      My_window::next();
    }

  private:
    /**/
    Graph_lib::Vector_ref<Graph_lib::Button> mCheckers;
    
    /**/
    Graph_lib::Vector_ref<Graph_lib::Rectangle> mRectangles;

    /**/
    Graph_lib::Out_box mOutBox;

    /**/
    int mRowsNumber;

    /**/
    int mColumnsNumber;

    /**/
    int mCellSize;

    /**/
    int mSelectedChecker;

    /**/
    Graph_lib::Color firstTypeCell = Graph_lib::Color::blue;

    /**/
    Graph_lib::Color secondTypeCell = Graph_lib::Color::red;

    /**/
    Graph_lib::Color selectedTypeCell = Graph_lib::Color::yellow;

    /*
    */
    static void cb_pushed_checker(Graph_lib::Address pWidget, Graph_lib::Address pWindow)
    {
      Graph_lib::reference_to<CheckerBoard>(pWindow).pushed_checker(pWidget);
    }

    void pushed_checker(Graph_lib::Address pWidget)
    {
      Fl_Button& button = Graph_lib::reference_to<Fl_Button>(pWidget);
      int index = button.x() / mCellSize + button.y() / mCellSize * mColumnsNumber;
      if (index < mRectangles.size())
      {
        mRectangles[index].set_fill_color(selectedTypeCell);
        if (mSelectedChecker >= 0)
        {
          mRectangles[mSelectedChecker].set_fill_color((mSelectedChecker % mColumnsNumber + (mSelectedChecker / mColumnsNumber)) % 2 ? firstTypeCell : secondTypeCell);
        }
        mSelectedChecker = index;
      }
      stringstream ss;
      ss << '(' << button.x() << ", " << button.y() << ')';
      mOutBox.put(ss.str());
      redraw();
    }
  };

}

int CH16P578EXERC2_FLTKRunExmple::excute()
{
  CheckerBoard myWindow({ 100,100 }, 600, 400, 50, "CH16P578EXERC1_FLTKRunExmple");

  return Graph_lib::gui_main();
}