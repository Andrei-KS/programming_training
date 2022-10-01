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
    
    template<typename T>
    Extended_function(Fct* f, Range range, Point orig, int count, Scale scale, T value)
      : mFunction(f)
      , mRange(range)
      , mOrigin(orig)
      , mCount(count)
      , mScale(scale)
      , mPrecision(-1)
    {
      if (mRange.right - mRange.left <= 0)
      {
        error("bad graphing range");
      }

      if (count <= 0)
      {
        error("non-positive graphing count");
      }


    }

    template<>
    Extended_function(Fct* f, Range range, Point orig, int count, Scale scale, double value)
      : mFunction(f)
      , mRange(range)
      , mOrigin(orig)
      , mCount(count)
      , mScale(scale)
      , mPrecision(value)
    {
      if (mRange.right - mRange.left <= 0)
      {
        error("bad graphing range");
      }

      if (count <= 0)
      {
        error("non-positive graphing count");
      }
    }

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

    /**/
    double mPrecision;
  };
}
#endif // !__EXTENDED_FUNCTION_H__