/*
  Hat.cpp
  author  : Andrei-KS
*/

#include "Hat.h"

namespace Graph_lib {
  Hat::Hat(Point base, int width, int height)
    : mWidth(width)
    , mHeight(height)
  {
    Shape::add(base);
  }

  Point Hat::base() const
  {
    return Point{ point(0).x,point(0).y };
  }

  int Hat::width() const
  {
    return mWidth;
  }

  int Hat::height() const
  {
    return mHeight;
  }

  Hats::Cap::Cap(Point base, int width, int height)
    : Hat(base, width, height)
  {
  }

  void Hats::Cap::draw_lines() const
  {
    if (fill_color().visibility()) {	// fill
      fl_color(fill_color().as_int());
      fl_pie(base().x - width() / 2, base().y - height(), width(), 2 * height(), 0, 180);
      fl_rectf(base().x - width() / 2, base().y - height() / 8, width(), height() / 8);
      fl_color(color().as_int());	// reset color
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(base().x - width() / 2, base().y - height(), width(), 2 * height(),0,180);
      fl_rect(base().x - width() / 2, base().y - height() / 8, width(), height() / 8);
    }
  }

  Hats::Cylinder::Cylinder(Point base, int width, int height)
    : Hat(base, width, height)
  {
  }

  void Hats::Cylinder::draw_lines() const
  {
    if (fill_color().visibility()) {	// fill
      fl_color(fill_color().as_int());
      fl_rectf(base().x - width() / 4, base().y - height(), width() / 2, height());
      fl_rectf(base().x - width() / 2, base().y - height() / 8, width(), height() / 8);
      fl_color(color().as_int());	// reset color
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      //fl_arc(base().x - width() / 2, base().y - height() / 2, width(), height(), 0, 180);
      fl_rect(base().x - width() / 2, base().y - height() / 8, width(), height() / 8);
    }
  }
}