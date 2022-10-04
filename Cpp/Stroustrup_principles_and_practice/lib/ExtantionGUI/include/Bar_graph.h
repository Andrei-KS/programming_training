/*
  Bar_graph.h
  author  : Andrei-KS
*/

#ifndef __BAR_GRAPH_H__
#define __BAR_GRAPH_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Bar_graph : Shape {
    /*
    */
    struct Bar_info {
      /**/
      double value = NAN;

      /**/
      Color fill_color = Color::invisible;

      /**/
      Color line_color = Color::invisible;

      /**/
      string label = "";

      /**/
      Font font{ fl_font() };

      /**/
      int font_size{ (14 < fl_size()) ? fl_size() : 14 };	// at least 14 point
    };

    /*
    */
    Bar_graph( Point leftTopCorner, int width, int height, const vector<double>& values );

    /*
    */
    Bar_graph(Point leftTopCorner, int width, int height, const vector<Bar_info>& Bar_infos);

    /*
    */
    void draw_lines() const;

    /*
    */
    const Bar_info& getBarInfo(int index) const;

    /*
    */
    void setBarInfo(int index, const Bar_info& barInfo);

    /*
    */
    double minValue()
    {
      return mMinValue;
    }

    /*
    */
    double maxValue()
    {
      return mMaxValue;
    }

  private:
    /**/
    vector<Bar_info> mBars;

    /**/
    Point mLeftTopCorner;

    /**/
    int mWidth;

    /**/
    int mHeight;

    /**/
    double mMaxValue;

    /**/
    double mMinValue;
  };

}

#endif // !__BAR_GRAPH_H__