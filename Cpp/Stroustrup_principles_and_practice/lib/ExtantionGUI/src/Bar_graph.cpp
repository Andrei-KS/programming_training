/*
  Bar_graph.cpp
  author  : Andrei-KS
*/

#include "Bar_graph.h"
#include <limits>

namespace Graph_lib {

  Bar_graph::Bar_graph(Point leftTopCorner, int width, int height, const vector<double>& values)
    : mValues(values)
    , mLeftTopCorner(leftTopCorner)
    , mWidth(width)
    , mHeight(height)
    , mMaxValue(numeric_limits<double>::min())
    , mMinValue(numeric_limits<double>::max())
  {
    if (mWidth < 0)
    {
      error("Bar_graph: Bar_graph width cannot be less zero");
    }

    if (mHeight < 0)
    {
      error("Bar_graph: Bar_graph height cannot be less zero");
    }

    for (double value : mValues)
    {
      if (value > mMaxValue)
      {
        mMaxValue = value;
      }

      if (value < mMinValue)
      {
        mMinValue = value;
      }
    }
  }

  void Bar_graph::draw_lines() const
  {
    if (!mValues.size())
    {
      return;
    }

    int BarWidth = mWidth / mValues.size();
    double yUnit = (mMaxValue - mMinValue) / mHeight;
    if (yUnit <= numeric_limits<double>::epsilon() && yUnit >= -numeric_limits<double>::epsilon())
    {
      return;
    }

    if (fill_color().visibility())
    {
      fl_color(fill_color().as_int());
      for (int barIndex = 0; barIndex < mValues.size(); barIndex++)
      {
        int height = static_cast<int>((mValues[barIndex] - mMinValue) / yUnit);
        height = height == 0 ? 1 : height;
        fl_rectf(mLeftTopCorner.x + barIndex * BarWidth, mLeftTopCorner.y + (mHeight - height), BarWidth, height);
      }
      fl_color(color().as_int()); // reset color
    }


    if (color().visibility())
    {
      for (int barIndex = 0; barIndex < mValues.size(); barIndex++)
      {
        int height = static_cast<int>((mValues[barIndex] - mMinValue) / yUnit);
        height = height == 0 ? 1 : height;
        fl_rect(mLeftTopCorner.x + barIndex * BarWidth, mLeftTopCorner.y + (mHeight - height), BarWidth, height);
      }
    }
  }
}