/*
  GUI_Utility_function.cpp
  author  : Andrei-KS
*/

#include "GUI_Utility_function.h"

namespace Graph_lib {
  Point n(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x + rect.width()/2,pNW.y);
  }

  Point ne(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x + rect.width(), pNW.y);
  }

  Point nw(const Rectangle& rect)
  {
    return rect.point(0);
  }

  Point s(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x + rect.width() / 2, pNW.y + rect.height());
  }

  Point se(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x + rect.width(), pNW.y + rect.height());
  }

  Point sw(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x, pNW.y + rect.height());
  }

  Point e(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x + rect.width(), pNW.y + rect.height() / 2);
  }

  Point w(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x, pNW.y + rect.height()/2);
  }

  Point center(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x + rect.width() / 2, pNW.y + rect.height() / 2);
  }
}