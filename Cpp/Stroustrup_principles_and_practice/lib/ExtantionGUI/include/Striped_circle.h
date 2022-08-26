/*
  Striped_circle.h
  author  : Andrei-KS
*/

#ifndef __STRIPED_CIRCLE_H__
#define __STRIPED_CIRCLE_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  class Striped_circle : public Shape {
  public:
    /*
    */
    Striped_circle(Point center, int radius);


    /*
    */
    void draw_lines() const;

    /*
    */
    Point center() const;

    /*
    */
    void set_radius(int rr);
    
    /*
    */
    int radius() const;
    
    /*
    */
    void set_fill_line_style(Line_style lineStyle);

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
    int mRadius;

    /**/
    Line_style mFillLineStyle{ 0 };

    /**/
    int mDistanceBetweenStrips{ -1 };
  };
}


#endif // !__STRIPED_CIRCLE_H__