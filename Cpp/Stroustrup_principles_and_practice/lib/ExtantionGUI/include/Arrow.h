/*
  Arrow.h
  author  : Andrei-KS
*/

#ifndef __ARROW_H__
#define __ARROW_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Arrow : Shape {
    /*
    */
    Arrow(Point start, Point end, int arrowheadLength = 5, int arrowheadWidth = 5);

    /*
    */
    void draw_lines() const;

  private:
    /**/
    int mArrowheadWidth;

    /**/
    int mArrowheadLength;
  };
}


#endif // !__ARROW_H__