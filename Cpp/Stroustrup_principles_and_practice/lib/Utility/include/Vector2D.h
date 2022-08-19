/*
  Vector2D.h
  author  : Andrei-KS
*/

#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

namespace Utility_lib {
  struct Vector2D {
    double x;
    double y;
  public:
    double length() const;
    Vector2D getUnitVector() const;
    Vector2D getNormal() const;
  };
}

#endif // !__VECTOR2D_H__