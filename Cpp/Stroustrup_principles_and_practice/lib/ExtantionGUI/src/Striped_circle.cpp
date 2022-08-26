/*
  Striped_circle.cpp
  author  : Andrei-KS
*/

#include "Striped_circle.h"

namespace Graph_lib {
  Striped_circle::Striped_circle(Point center, int radius)
    : mRadius(radius)
  {
    add(Point{ center.x - mRadius, center.y - mRadius });
  }

  void Striped_circle::draw_lines() const
  {
    if (fill_color().visibility()) {	// fill
      fl_color(fill_color().as_int());
      int widthStrip = fill_line_style().width();
      fl_line_style(fill_line_style().style(), widthStrip);
      int distanceBetweenStrips = distance_between_strips() < 0 ? widthStrip : distance_between_strips();
      int sqrR = radius() * radius();
      for (int currentYPosition = 0; currentYPosition < radius(); currentYPosition += widthStrip + distanceBetweenStrips)
      {
        int xPosition = static_cast<int>(sqrt(sqrR - currentYPosition * currentYPosition));
        fl_line(center().x - xPosition, center().y + currentYPosition, center().x + xPosition, center().y + currentYPosition);
        fl_line(center().x - xPosition, center().y - currentYPosition, center().x + xPosition, center().y - currentYPosition);
        //fl_line(point(0).x + style().width() / 2, point(0).y + currentYPosition, point(0).x + mWidth - style().width() / 2, point(0).y + currentYPosition);

      }

      // reset
      fl_color(color().as_int());
      fl_line_style(style().style(), style().width());
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(point(0).x, point(0).y, mRadius + mRadius, mRadius + mRadius, 0, 360);
    }
  }

  Point Striped_circle::center() const
  {
    return { point(0).x + mRadius, point(0).y + mRadius };
  }

  void Striped_circle::set_radius(int radius)
  {
    mRadius = radius;
  }

  /*
  */
  int Striped_circle::radius() const
  {
    return mRadius;
  }

  /*
  */
  void Striped_circle::set_fill_line_style(Line_style lineStyle)
  {
    mFillLineStyle = lineStyle;
  }

  /*
  */
  Line_style Striped_circle::fill_line_style() const
  {
    return mFillLineStyle;
  }

  /*
  */
  void Striped_circle::set_distance_between_strips(int value)
  {
    mDistanceBetweenStrips = value;
  }

  /*
  */
  int Striped_circle::distance_between_strips() const
  {
    return mDistanceBetweenStrips;
  }
}