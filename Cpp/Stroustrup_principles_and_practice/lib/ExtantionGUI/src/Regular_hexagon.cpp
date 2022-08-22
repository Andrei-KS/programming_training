/*
  Regular_hexagon.cpp
  author  : Andrei-KS
*/

#include "Regular_hexagon.h"
#include "Vector2D.h"

namespace Graph_lib {

  Regular_hexagon::Regular_hexagon(Point center, int lengthToCorner, double shapeRotate)
  {
    if (lengthToCorner <= 0)
    {
      error("the distance from the center to a corner point less or equal zero");
    }
    const double rotateAngle = 360.0 / 6;
    Utility_lib::Vector2D direction{ lengthToCorner,0 };
    direction.rotate(shapeRotate);
    for (int indexAngle = 0; indexAngle < 6; indexAngle++)
    {
      Polygon::add(Point{ static_cast<int>(direction.x) + center.x, static_cast<int>(direction.y) + center.y });
      direction.rotate(rotateAngle);
    }
  }

}