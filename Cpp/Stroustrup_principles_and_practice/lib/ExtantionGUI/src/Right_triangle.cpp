/*
  Right_triangle.cpp
  author  : Andrei-KS
*/

#include "Right_triangle.h"
#include "Vector2D.h"

namespace Graph_lib {

  Right_triangle::Right_triangle(Point rightAngle, int sidelength1, int sidelength2, double shapeRotate)
  {
    if (sidelength1 <= 0 || sidelength2 <= 0)
    {
      error("The one of side lengths of the right triangle less or equal zero");
    }
    Polygon::add(rightAngle);
    Utility_lib::Vector2D direction{ 1,0 };
    direction.rotate(shapeRotate);
    Polygon::add(Point{ static_cast<int>(direction.x * sidelength1) + rightAngle.x, static_cast<int>(direction.y * sidelength1) + rightAngle.y });
    direction.rotate(90);
    Polygon::add(Point{ static_cast<int>(direction.x * sidelength2) + rightAngle.x, static_cast<int>(direction.y * sidelength2) + rightAngle.y });
  }

}