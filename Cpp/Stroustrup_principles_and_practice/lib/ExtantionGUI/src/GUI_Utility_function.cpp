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
    return Point(pNW.x + rect.width() / 2, pNW.y);
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
    return Point(pNW.x, pNW.y + rect.height() / 2);
  }

  Point center(const Rectangle& rect)
  {
    Point pNW = nw(rect);
    return Point(pNW.x + rect.width() / 2, pNW.y + rect.height() / 2);
  }


  //-------------------------------------- Circle
  Point n(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x, pCenter.y - circle.radius());
  }

  Point ne(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x + static_cast<int>(circle.radius() * root2 / 2), pCenter.y - static_cast<int>(circle.radius() * root2 / 2));
  }

  Point nw(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x - static_cast<int>(circle.radius() * root2 / 2), pCenter.y - static_cast<int>(circle.radius() * root2 / 2));
  }

  Point s(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x, pCenter.y + circle.radius());
  }

  Point se(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x + static_cast<int>(circle.radius() * root2 / 2), pCenter.y + static_cast<int>(circle.radius() * root2 / 2));
  }

  Point sw(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x - static_cast<int>(circle.radius() * root2 / 2), pCenter.y + static_cast<int>(circle.radius() * root2 / 2));
  }

  Point e(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x + circle.radius(), pCenter.y);
  }

  Point w(const Circle& circle)
  {
    Point pCenter = center(circle);
    return Point(pCenter.x - circle.radius(), pCenter.y);
  }

  Point center(const Circle& circle)
  {
    return circle.center();
  }

  //-------------------------------------- Ellipse
  Point n(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x, pCenter.y - ellipse.minor());
  }

  Point ne(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x + static_cast<int>(ellipse.major() * root2 / 2), pCenter.y - static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point nw(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x - static_cast<int>(ellipse.major() * root2 / 2), pCenter.y - static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point s(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x, pCenter.y + ellipse.minor());
  }

  Point se(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x + static_cast<int>(ellipse.major() * root2 / 2), pCenter.y + static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point sw(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x - static_cast<int>(ellipse.major() * root2 / 2), pCenter.y + static_cast<int>(ellipse.minor() * root2 / 2));
  }

  Point e(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x + ellipse.major(), pCenter.y);
  }

  Point w(const Ellipse& ellipse)
  {
    Point pCenter = center(ellipse);
    return Point(pCenter.x - ellipse.major(), pCenter.y);
  }

  Point center(const Ellipse& ellipse)
  {
    return ellipse.center();
  }

  //-------------------------------------- Box
  Point n(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + box.width() / 2, pNWBounderingBox.y };
  }

  Point ne(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + box.width() - static_cast<int>(box.cornerRoundingWidth() * (1 - root2 / 2)), pNWBounderingBox.y + static_cast<int>(box.cornerRoundingHeight() * (1 - root2 / 2)) };
  }

  Point nw(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + static_cast<int>(box.cornerRoundingWidth() * (1 - root2 / 2)), pNWBounderingBox.y + static_cast<int>(box.cornerRoundingHeight() * (1 - root2 / 2)) };
  }

  Point s(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + box.width() / 2,pNWBounderingBox.y + box.height() };
  }

  Point se(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + box.width() - static_cast<int>(box.cornerRoundingWidth() * (1 - root2 / 2)), pNWBounderingBox.y + box.height() - static_cast<int>(box.cornerRoundingHeight() * (1 - root2 / 2))};
  }

  Point sw(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + static_cast<int>(box.cornerRoundingWidth() * (1 - root2 / 2)), pNWBounderingBox.y + box.height() - static_cast<int>(box.cornerRoundingHeight() * (1 - root2 / 2)) };
  }

  Point e(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x, pNWBounderingBox.y + box.height() / 2 };
  }

  Point w(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + box.width(), pNWBounderingBox.y + box.height() / 2 };
  }

  Point center(const Box& box)
  {
    Point pNWBounderingBox = box.point(0);
    return Point{ pNWBounderingBox.x + box.width() / 2,pNWBounderingBox.y + box.height() / 2 };
  }

  //-------------------------------------- TextBox
  Point n(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + textBox.width() / 2, pNWBounderingBox.y };
  }

  Point ne(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + textBox.width() - static_cast<int>(textBox.marginSize() * (1 - root2 / 2)), pNWBounderingBox.y + static_cast<int>(textBox.marginSize() * (1 - root2 / 2)) };
  }

  Point nw(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + static_cast<int>(textBox.marginSize() * (1 - root2 / 2)), pNWBounderingBox.y + static_cast<int>(textBox.marginSize() * (1 - root2 / 2)) };
  }

  Point s(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + textBox.width() / 2,pNWBounderingBox.y + textBox.height() };
  }

  Point se(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + textBox.width() - static_cast<int>(textBox.marginSize() * (1 - root2 / 2)), pNWBounderingBox.y + textBox.height() - static_cast<int>(textBox.marginSize() * (1 - root2 / 2)) };
  }

  Point sw(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + static_cast<int>(textBox.marginSize() * (1 - root2 / 2)), pNWBounderingBox.y + textBox.height() - static_cast<int>(textBox.marginSize() * (1 - root2 / 2)) };
  }

  Point e(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x, pNWBounderingBox.y + textBox.height() / 2 };
  }

  Point w(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + textBox.width(), pNWBounderingBox.y + textBox.height() / 2 };
  }

  Point center(const TextBox& textBox)
  {
    Point pNWBounderingBox = textBox.point(0);
    return Point{ pNWBounderingBox.x + textBox.width() / 2,pNWBounderingBox.y + textBox.height() / 2 };
  }

}