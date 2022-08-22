/*
  Vector2D.cpp
  author  : Andrei-KS
*/

#include "std_lib_facilities.h"
#include "Vector2D.h"
#include "Utility_lib_Constatnt.h"
#include <cmath>
#include <numbers>

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

  void Vector2D::rotate(double rotateAngel)
  {
    double angleInRadian = rotateAngel * PI / 180;
    double prevX = x;
    double prevY = y;
    x = prevX * cos(angleInRadian) + prevY * sin(angleInRadian);
    y = - prevX * sin(angleInRadian) + prevY * cos(angleInRadian);
  }

  Vector2D getRotateVector(const Vector2D& vect, double rotateAngel)
  {
    double angleInRadian = rotateAngel * PI / 180;
    return Vector2D{ vect.x * cos(angleInRadian) + vect.y * sin(angleInRadian) ,- vect.x * sin(angleInRadian) + vect.y * cos(angleInRadian) };
  }
}