/*
  Immobile_Circle.h
  author  : Andrei-KS
*/

#ifndef __IMMOBILE_CIRCLE_H__
#define __IMMOBILE_CIRCLE_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  class Immobile_Circle : public Circle {
  public:
    /*
    */
    Immobile_Circle(Point center, int radius);

  private:
    /*
    */
    void move(int dx, int dy) override;
  };
}


#endif // !__IMMOBILE_CIRCLE_H__