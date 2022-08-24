/*
  Poly.h
  author  : Andrei-KS
*/

#ifndef __POLY_H__
#define __POLY_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Poly : Polygon {
    /*
    * @param points - points set 
    */
    Poly(vector<Point> points);
  };
}

#endif // !__POLY_H__