/*
  Regular_polygon.cpp
  author  : Andrei-KS
*/

#include "Regular_polygon.h"
#include "Vector2D.h"

namespace Graph_lib {

  Regular_polygon::Regular_polygon(Point center, int lengthToCorner, int amountAngles, double shapeRotate)
  {
    if (amountAngles < 3)
    {
      error("The amount of angles less than 3");
    }
    if ( lengthToCorner <= 0)
    {
      error("The distance from the center to a corner point less or equal zero");
    }
    const double rotateAngle = 360.0 / amountAngles;
    Utility_lib::Vector2D direction{ lengthToCorner,0 };
    direction.rotate(shapeRotate);
    for (int indexAngle = 0; indexAngle < amountAngles; indexAngle++)
    {
      Polygon::add(Point{ static_cast<int>(direction.x) + center.x, static_cast<int>(direction.y) + center.y });
      direction.rotate(rotateAngle);
    }
  }

}