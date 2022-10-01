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
      double precision = mPrecision <= 0 ? 0.001 : mPrecision;
      double dist = (mRange.right - mRange.left) / mCount;
      double r = mRange.left;
      double currentLeftX = mOrigin.x + static_cast<int>(r * mScale.x);
      double currentLeftY = mOrigin.y - static_cast<int>(mFunction(r) * mScale.y);
      for (int i = 0; i < mCount; ++i) {
        r += dist;
        double currentRightX = mOrigin.x + (r * mScale.x);
        double currentRightY = mOrigin.y - (mFunction(r) * mScale.y);
        if (currentRightY - currentLeftY <= mPrecision && currentLeftY - currentRightY <= mPrecision)
        {
          currentRightY = currentLeftY;
        }
        fl_line(static_cast<int>(currentLeftX), static_cast<int>(currentLeftY), static_cast<int>(currentRightX), static_cast<int>(currentRightY));
        currentLeftX = currentRightX;
        currentLeftY = currentRightY;
      }
    }
  }
}