/*
  Vector2D.h
  author  : Andrei-KS
*/

#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

namespace Utility_lib {
  struct Vector2D {
    double x = 0;
    double y = 0;
  public:
    double length() const;
    Vector2D getUnitVector() const;
    Vector2D getNormal() const;
    /*
    * @param rotateAngel - in degree
    */
    void rotate(double rotateAngel);
  };

  /*
  * @param vector -
  * @param rotateAngel - measured in degrees counter - clockwise from 3 o'clock.
  * @return rotated vector
  */
  Vector2D getRotateVector(const Vector2D& vect, double rotateAngel);
  
  /*
  * @param start -
  * @param end -
  * @return vector lenght
  */
  double getLength(const Vector2D& start, const Vector2D& end);

  /*
  * @param vector -
  * @return vector lenght
  */
  double getLength(const Vector2D& vect);

  Vector2D operator-(const Vector2D& left, const Vector2D& right);
  Vector2D operator+(const Vector2D& left, const Vector2D& right);
}

#endif // !__VECTOR2D_H__