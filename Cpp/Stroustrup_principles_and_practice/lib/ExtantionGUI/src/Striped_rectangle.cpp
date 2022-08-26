/*
  Striped_rectangle.cpp
  author  : Andrei-KS
*/

#include "Striped_rectangle.h"

namespace Graph_lib {
  Striped_rectangle::Striped_rectangle(Point xy, int width, int height)
    : mWidth{ width }
    , mHeight{ height }
  {
    if (mHeight <= 0 || mWidth <= 0) error("Bad rectangle: non-positive side");
    add(xy);
  }

  Striped_rectangle::Striped_rectangle(Point x, Point y)
    : mWidth{ y.x - x.x }
    , mHeight{ y.y - x.y }
  {
    if (mHeight <= 0 || mWidth <= 0) error("Bad rectangle: first point is not top left");
    add(x);
  }

  void Striped_rectangle::draw_lines() const
  {
    if (fill_color().visibility()) {	// fill
      fl_color(fill_color().as_int());
      int widthStrip = fill_line_style().width();
      fl_line_style(fill_line_style().style(), widthStrip);
      int distanceBetweenStrips = distance_between_strips() < 0 ? widthStrip : distance_between_strips();
      int top = style().width() / 2  + distanceBetweenStrips;
      int down = height() - style().width() / 2 - distanceBetweenStrips;
      for (int currentYPosition = top; currentYPosition < down; currentYPosition += widthStrip + distanceBetweenStrips)
      {
        fl_line(point(0).x + style().width() / 2, point(0).y + currentYPosition, point(0).x + mWidth - style().width() / 2, point(0).y + currentYPosition);

      }
      
      // reset
      fl_color(color().as_int());	
      fl_line_style(style().style(), style().width());
    }

    if (color().visibility()) {	// edge on top of fill
      fl_color(color().as_int());
      fl_rect(point(0).x, point(0).y, mWidth, mHeight);
    }
  }

  int Striped_rectangle::height() const
  {
    return mHeight;
  }

  int Striped_rectangle::width() const
  {
    return mWidth;
  }

  void Striped_rectangle::set_fill_line_style(Line_style lineStyle)
  {
    mFillLineStyle = lineStyle;
  }

  Line_style Striped_rectangle::fill_line_style() const
  {
    return mFillLineStyle;
  }

  void Striped_rectangle::set_distance_between_strips(int value)
  {
    mDistanceBetweenStrips = value;
  }

  /*
  */
  int Striped_rectangle::distance_between_strips() const
  {
    return mDistanceBetweenStrips;
  }
}