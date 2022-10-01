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
    Bar_graph( Point leftTopCorner, int width, int height, const vector<double>& values );

    /*
    */
    void draw_lines() const;

  private:
    /**/
    vector<double> mValues;

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