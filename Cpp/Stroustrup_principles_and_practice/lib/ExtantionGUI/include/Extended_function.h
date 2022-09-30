/*
  Extended_function.h
  author  : Andrei-KS
*/

#ifndef __EXTENDED_FUNCTION_H__
#define __EXTENDED_FUNCTION_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  *
  */
  struct Extended_function : Shape {
    /*
    * 
    */
    struct Range {
      double left;
      double right;
    };

    /*
    * 
    */
    struct Scale {
      double x;
      double y;
    };

    /*
    * graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
    * x coordinates are scaled by xscale and y coordinates scaled by yscale
    */
    Extended_function(Fct* f, Range range, Point orig, int count = 100, Scale scale = {25.0,25.0});
    
    /*
    */
    void reset(Fct* f, Range range, Point orig, int count = 100, Scale scale = { 25.0,25.0 });

    void draw_lines() const;
  
  private:
    /**/
    Fct* mFunction;

    /**/
    Range mRange;

    /**/
    Point mOrigin;

    /**/
    int mCount;

    /**/
    Scale mScale;
  };
}
#endif // !__EXTENDED_FUNCTION_H__