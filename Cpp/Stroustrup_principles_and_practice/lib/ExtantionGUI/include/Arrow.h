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
    void rotate(double angle);

    /*
    */
    void setDirection(double angle);

    /*
    */
    virtual void move(int dx, int dy);


    /*
    */
    void draw_lines() const;

  protected:
    /**/
    void calculateArrow();

  private:
    /**/
    vector<Graph_lib::Point> mDisplayPoint;

    /**/
    int mArrowheadWidth;

    /**/
    int mArrowheadLength;
  };
}


#endif // !__ARROW_H__