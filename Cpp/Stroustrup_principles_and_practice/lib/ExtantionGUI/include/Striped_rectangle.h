/*
  Striped_rectangle.h
  author  : Andrei-KS
*/

#ifndef __STRIPED_RECTANGLE_H__
#define __STRIPED_RECTANGLE_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  class Striped_rectangle : public Shape {
  public:
    /*
    */
    Striped_rectangle(Point xy, int ww, int hh);
    
    /*
    */
    Striped_rectangle(Point x, Point y);

    /*
    */
    void draw_lines() const;

    /*
    */
    int height() const;
    
    /*
    */
    int width() const;

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
    int mHeight;

    /**/
    int mWidth;

    /**/
    Line_style mFillLineStyle{0};

    /**/
    int mDistanceBetweenStrips{-1};
  };
}


#endif // !__STRIPED_RECTANGLE_H__