/*
  Extended_function.cpp
  author  : Andrei-KS
*/

#include "Extended_function.h"

namespace Graph_lib {
  Extended_function::Extended_function(Fct* f, Range range, Point orig, int count, Scale scale)
    : mFunction(f)
    , mRange(range)
    , mOrigin(orig)
    , mCount(count)
    , mScale(scale)
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

  void Extended_function::reset(Fct* f, Range range, Point orig, int count, Scale scale)
  {
    mFunction = f;
    mRange = range;
    mOrigin = orig;
    mCount = count;
    mScale = scale;

    if (mRange.right - mRange.left <= 0)
    {
      error("bad graphing range");
    }

    if (count <= 0)
    {
      error("non-positive graphing count");
    }
  }

  void Extended_function::draw_lines() const
  {
    if (color().visibility())
    {
      double dist = (mRange.right - mRange.left) / mCount;
      double r = mRange.left;
      double currentLeftX = mOrigin.x + static_cast<int>(r * mScale.x);
      double currentLeftY = mOrigin.y - static_cast<int>(mFunction(r) * mScale.y);
      for (int i = 0; i < mCount; ++i) {
        r += dist;
        double currentRightX = mOrigin.x + static_cast<int>(r * mScale.x);
        double currentRightY = mOrigin.y - static_cast<int>(mFunction(r) * mScale.y);
        fl_line(currentLeftX, currentLeftY, currentRightX, currentRightY);
        currentLeftX = currentRightX;
        currentLeftY = currentRightY;
      }
    }
  }
}