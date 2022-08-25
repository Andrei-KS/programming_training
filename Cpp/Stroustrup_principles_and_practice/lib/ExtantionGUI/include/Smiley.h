/*
  Smiley.h
  author  : Andrei-KS
*/

#ifndef __SMILEY_H__
#define __SMILEY_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  class Smiley : public Circle {
  public:
    /*
    */
    Smiley(Point center, int radius);

  protected:
    /*
    */
    void draw_lines() const override;

  };
}


#endif // !__SMILEY_H__