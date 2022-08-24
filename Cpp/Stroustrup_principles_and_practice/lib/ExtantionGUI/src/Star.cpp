/*
  Star.cpp
  author  : Andrei-KS
*/

#include "Star.h"
#include "Vector2D.h"

namespace Graph_lib {

  Star::Star(Point center, int numberPoints, int majorLength, int minorLength)
  {
    if (numberPoints < 2)
    {
      error("Bad Star: The number of points should not less than 2");
    }
    if (majorLength <= minorLength)
    {
      error("Bad Star: The majorLength should greate than minorLength");
    }
    add(center);
    double rotateAngle = 360 / 2 / numberPoints;
    Utility_lib::Vector2D currDirection = Utility_lib::getRotateVector(Utility_lib::Vector2D{ 0,-1 }, -rotateAngle);

    for (int index = 0; index < numberPoints * 2; index++)
    {
      int length = index % 2 ? majorLength : minorLength;
      add(Point{center.x + static_cast<int>(currDirection.x * length) ,center.y + static_cast<int>(currDirection.y * length) });
      currDirection.rotate(rotateAngle);
    }
  }

  void Star::draw_lines() const
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


    if (color().visibility()) {	// edge on top of fill
      fl_color(color().as_int());
      for (int i = 2; i < number_of_points(); ++i) {
        fl_line(point(i-1).x, point(i - 1).y, point(i).x, point(i).y);
      }
      fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, point(1).x, point(1).y);
    }


  }

  Point Star::center() const
  {
    return point(0);
  }
}