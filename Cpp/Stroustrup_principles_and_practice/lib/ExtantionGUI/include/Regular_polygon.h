/*
  Regular_polygon.h
  author  : Andrei-KS
*/

#ifndef __REGULAR_POLYGON_H__
#define __REGULAR_POLYGON_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Regular_polygon : Polygon {
    /*
    * @param center -
    * @param lengthToCorner -
    * @param shapeRotate - measured in degrees counter - clockwise from 3 o'clock.
    */
    Regular_polygon(Point center, int lengthToCorner, int amountAngles = 3, double shapeRotate = 0);

  protected:
    /**/
    void add(Point p) = delete;
  };
}

#endif // !__REGULAR_POLYGON_H__