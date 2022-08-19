/*
  GUI_Utility_function.cpp
  author  : Andrei-KS
*/

#include "GUI_Utility_function.h"
namespace {
  const double root2 = sqrt(2.0);
}

namespace Graph_lib {
//-------------------------------------- Rectangle
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


//-------------------------------------- Circle
  Point n(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x, pNW.y - circle.radius());
  }

  Point ne(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x + static_cast<int>(circle.radius() * root2 / 2), pNW.y - static_cast<int>(circle.radius() * root2 / 2));
  }

  Point nw(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x - static_cast<int>(circle.radius() * root2 / 2), pNW.y - static_cast<int>(circle.radius() * root2 / 2));
  }

  Point s(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x, pNW.y + circle.radius());
  }

  Point se(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x + static_cast<int>(circle.radius() * root2 / 2), pNW.y + static_cast<int>(circle.radius() * root2 / 2));
  }

  Point sw(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x - static_cast<int>(circle.radius() * root2 / 2), pNW.y + static_cast<int>(circle.radius() * root2 / 2));
  }

  Point e(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x + circle.radius(), pNW.y);
  }

  Point w(const Circle& circle)
  {
    Point pNW = center(circle);
    return Point(pNW.x - circle.radius(), pNW.y);
  }

  Point center(const Circle& circle)
  {
    return circle.center();
  }

//-------------------------------------- Ellipse
  Point n(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x, pNW.y - ellipse.minor());
  }

  Point ne(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x + static_cast<int>(ellipse.major() * root2 / 2), pNW.y - static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point nw(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x - static_cast<int>(ellipse.major() * root2 / 2), pNW.y - static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point s(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x, pNW.y + ellipse.minor());
  }

  Point se(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x + static_cast<int>(ellipse.major() * root2 / 2), pNW.y + static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point sw(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x - static_cast<int>(ellipse.major() * root2 / 2), pNW.y + static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point e(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x + ellipse.major(), pNW.y);
  }

  Point w(const Ellipse& ellipse)
  {
    Point pNW = center(ellipse);
    return Point(pNW.x - ellipse.major(), pNW.y);
  }

  Point center(const Ellipse& ellipse)
  {
    return ellipse.center();
  }

}