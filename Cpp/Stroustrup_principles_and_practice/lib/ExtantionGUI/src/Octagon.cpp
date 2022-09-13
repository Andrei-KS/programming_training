/*
  Octagon.cpp
  author  : Andrei-KS
*/

#include "Octagon.h"
#include "Vector2D.h"
#include "Utility_lib_Constatnt.h"

namespace Graph_lib {
  Octagon::Octagon(Point center, int sideLength, double shapeRotate)
    : mSideLength(sideLength)
  {
    if (sideLength <= 0)
    {
      error("Octagon: the side length less or equal zero");
    }
    Shape::add(center);

    const double rotateAngle = 360.0 / 8;
    const double lengthToCorner =  mSideLength / 2.0 / sin(rotateAngle * Utility_lib::PI / 180.0 / 2.0);

    Utility_lib::Vector2D direction{ lengthToCorner,0 };
    direction.rotate(rotateAngle/2 + shapeRotate);

    for (int indexAngle = 0; indexAngle < 8; indexAngle++)
    {
      Shape::add(Point{ static_cast<int>(direction.x) + this->center().x, static_cast<int>(direction.y) + this->center().y });
      direction.rotate(rotateAngle);
    }
  }

  void Octagon::draw_lines() const
  {
    if (fill_color().visibility()) {
      fl_color(fill_color().as_int());
      fl_begin_complex_polygon();
      for (int i = 1; i < number_of_points(); ++i) {
        fl_vertex(point(i).x, point(i).y);
      }
      fl_end_complex_polygon();
      fl_color(color().as_int());	// reset color
    }

    if (color().visibility() && 1 < number_of_points())
    {
      for (unsigned int i = 2; i < number_of_points(); ++i)
      {
       fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
      }
      fl_line(point(1).x, point(1).y, point(number_of_points()-1).x, point(number_of_points() - 1).y);
    }

  }

  Point Octagon::center() const
  {
    return point(0);
  }

}