/*
  Right_triangle.h
  author  : Andrei-KS
*/

#ifndef __RIGHT_TRIANGLE_H__
#define __RIGHT_TRIANGLE_H___

#include "Graph.h"

namespace Graph_lib {
  /* 
  */ 
  struct Right_triangle : Polygon {
    /*
    * @param rightAngle -
    * @param sidelength -
    * @param shapeRotate - measured in degrees counter - clockwise from 3 o'clock.
    */
    Right_triangle(Point rightAngle, int sidelength, double shapeRotate = 0);

  protected:
    /**/
    void add(Point p) = delete;
  };
}

#endif // !__RIGHT_TRIANGLE_H__