/*
  Octagon.h
  author  : Andrei-KS
*/

#ifndef __OCTAGON_H__
#define __OCTAGON_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  class Octagon : public Shape {
  public:
    /*
    */
    Octagon(Point center, int sideLength, double shapeRotate = 0);

    /*
    */
    void draw_lines() const;

    /*
    */
    Point center() const;

    /*
    */
    int sideLength() const;

  private:
    /**/
    int mSideLength;
  };
}


#endif // !__OCTAGON_H__