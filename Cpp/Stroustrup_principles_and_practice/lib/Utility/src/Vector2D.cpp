/*
  Vector2D.cpp
  author  : Andrei-KS
*/

#include "std_lib_facilities.h"
#include "Vector2D.h"
#include "Utility_lib_Constatnt.h"
#include <cmath>

namespace Utility_lib {
  double Vector2D::length() const
  {
    return sqrt(pow(x, 2) + pow(y, 2));
  }


  Vector2D Vector2D::getUnitVector() const
  {
    double l = length();
    return Vector2D{ x / l, y / l };
  }


  Vector2D Vector2D::getNormal() const
  {
    if ((std::abs(x) < EPS) && (std::abs(y) < EPS))
    {
      return Vector2D{ 0, 0 };
    }

    if (std::abs(x) < EPS)
    {
      return Vector2D{ 1, 0 };
    }

    if (std::abs(y) < EPS)
    {
      return Vector2D{ 0, 1 };
    }

    Vector2D temp{ 1, -x / y };
    double length = temp.length();
    return Vector2D{ temp.x / length, temp.y / length };
  }
}