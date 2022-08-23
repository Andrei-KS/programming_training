/*
  Right_triangle.cpp
  author  : Andrei-KS
*/

#include "Right_triangle.h"
#include "Vector2D.h"

namespace Graph_lib {

  Right_triangle::Right_triangle(Point rightAngle, int sidelength, double shapeRotate)
  {
    if (sidelength <= 0)
    {
      error("The distance from the center to a corner point less or equal zero");
    }
    Polygon::add(rightAngle);
    Utility_lib::Vector2D direction{ sidelength,0 };
    direction.rotate(shapeRotate);
    Polygon::add(Point{ static_cast<int>(direction.x) + rightAngle.x, static_cast<int>(direction.y) + rightAngle.y });
    direction.rotate(90);
    Polygon::add(Point{ static_cast<int>(direction.x) + rightAngle.x, static_cast<int>(direction.y) + rightAngle.y });
  }

}