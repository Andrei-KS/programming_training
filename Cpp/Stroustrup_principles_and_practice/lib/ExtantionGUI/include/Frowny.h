/*
  Frowny.h
  author  : Andrei-KS
*/

#ifndef __FROWNY_H__
#define __FROWNY_H__

#include "Graph.h"

namespace Graph_lib {

  /*
  */
  class Frowny : public Circle {
  public:
    /*
    */
    Frowny(Point center, int radius);

    /*
    */
    void draw_lines() const override;
  };

}


#endif // !__FROWNY_H__