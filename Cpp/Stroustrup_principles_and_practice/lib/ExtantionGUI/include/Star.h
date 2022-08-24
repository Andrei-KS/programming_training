/*
  Star.h
  author  : Andrei-KS
*/

#ifndef __STAR_H__
#define __STAR_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Star : Shape {
    /*
    * @param numberPoints -
    */
    Star(Point center, int numberPoints, int majorLength = 10, int minorLength = 2);

    /*
    */
    void draw_lines() const;

    /*
    */
    Point center() const;
  };
}

#endif // !__STAR_H__