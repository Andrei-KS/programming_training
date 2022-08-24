/*
  Poly.cpp
  author  : Andrei-KS
*/

#include "Poly.h"

namespace Graph_lib {
  Poly::Poly(vector<Point> points)
  {
    if (points.size() < 3)
    {
      error("Bad Poly: The number of points is less than 3.");
    }
    for (Point point : points)
    {
      add(point);
    }
  }
}
