/*
  Striped_closed_polyline.h
  author  : Andrei-KS
*/

#ifndef __STRIPED_CLOSED_POLYLINE_H__
#define __STRIPED_CLOSED_POLYLINE_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  class Striped_closed_polyline : public Shape {
  public:
    /*
    */
    Striped_closed_polyline();

    /*
    */
    void draw_lines() const;

    /*
    */
    void add(Point p);

    /*
    */
    void set_fill_line_style(Line_style sty);

    /*
    */
    Line_style fill_line_style() const;

    /*
    */
    void set_distance_between_strips(int value);

    /*
    */
    int distance_between_strips() const;

  private:
    /**/
    void recalculateStrips() const;

    /**/
    mutable bool mNeedRecalculateStrips{ true };

    /**/
    mutable vector<pair<Point,Point>> mStrips;

    /**/
    int mYMax;
    
    /**/
    int mYMin;
    
    /**/
    int mXMax;
    
    /**/
    int mXMin;

    /**/
    Line_style mFillLineStyle{ 0 };

    /**/
    int mDistanceBetweenStrips{ -1 };
  };
}


#endif // !__STRIPED_CLOSED_POLYLINE_H__