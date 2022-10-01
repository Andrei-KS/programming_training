/*
  Bar_graph.cpp
  author  : Andrei-KS
*/

#include "Bar_graph.h"
#include <limits>

namespace Graph_lib {

  Bar_graph::Bar_graph(Point leftTopCorner, int width, int height, const vector<double>& values)
    : mLeftTopCorner(leftTopCorner)
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

    mBars = vector<Bar_info>(values.size(), Bar_info());

    for (int valueIndex = 0; valueIndex < values.size(); valueIndex++)
    {
      if (values[valueIndex] != NAN && values[valueIndex] > mMaxValue)
      {
        mMaxValue = values[valueIndex];
      }

      if (values[valueIndex] != NAN && values[valueIndex] < mMinValue)
      {
        mMinValue = values[valueIndex];
      }
      mBars[valueIndex].value = values[valueIndex];
    }
  }

  Bar_graph::Bar_graph(Point leftTopCorner, int width, int height, const vector<Bar_info>& Bar_infos)
    : mBars(Bar_infos)
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

    for (int valueIndex = 0; valueIndex < Bar_infos.size(); valueIndex++)
    {
      if (Bar_infos[valueIndex].value != NAN && Bar_infos[valueIndex].value > mMaxValue)
      {
        mMaxValue = Bar_infos[valueIndex].value;
      }

      if (Bar_infos[valueIndex].value != NAN && Bar_infos[valueIndex].value < mMinValue)
      {
        mMinValue = Bar_infos[valueIndex].value;
      }
    }
  }

  void Bar_graph::draw_lines() const
  {
    if (!mBars.size())
    {
      return;
    }

    int BarWidth = mWidth / mBars.size();
    double yUnit = (mMaxValue - mMinValue) / mHeight;
    if (yUnit <= numeric_limits<double>::epsilon() && yUnit >= -numeric_limits<double>::epsilon())
    {
      return;
    }

    for (int barIndex = 0; barIndex < mBars.size(); barIndex++)
    {
      if (mBars[barIndex].value != NAN)
      {
        int height = static_cast<int>((mBars[barIndex].value - mMinValue) / yUnit);
        height = height == 0 ? 1 : height;

        Color fillColor = mBars[barIndex].fill_color.visibility()? mBars[barIndex].fill_color : fill_color();
        if (fillColor.visibility())
        {
          fl_color(fillColor.as_int());
          fl_rectf(mLeftTopCorner.x + barIndex * BarWidth, mLeftTopCorner.y + (mHeight - height), BarWidth, height);
        }

        Color lineColor = mBars[barIndex].line_color.visibility() ? mBars[barIndex].line_color : color();
        if (lineColor.visibility())
        {
          fl_color(lineColor.as_int());
          fl_rect(mLeftTopCorner.x + barIndex * BarWidth, mLeftTopCorner.y + (mHeight - height), BarWidth, height);

          if (mBars[barIndex].label != "")
          {
            int ofnt = fl_font();
            int osz = fl_size();
            fl_font(mBars[barIndex].font.as_int(), mBars[barIndex].font_size);
            fl_draw(45, mBars[barIndex].label.c_str(), mLeftTopCorner.x + barIndex * BarWidth, mLeftTopCorner.y + (mHeight - height));
            fl_font(ofnt, osz);
          }
        }
      }
    }

    fl_color(color().as_int()); // reset color
  }

  const Bar_graph::Bar_info& Bar_graph::getBarInfo(int index) const
  {
    if (index >= mBars.size())
    {
      error("Bar_graph: getBarInfo: index outrange");
    }
    return mBars[index];
  }

  void Bar_graph::setBarInfo(int index, const Bar_info& barInfo)
  {
    if (index >= mBars.size())
    {
      error("Bar_graph: getBarInfo: index outrange");
    }
    mBars[index] = barInfo;

    mMaxValue = (numeric_limits<double>::min());
    mMinValue = (numeric_limits<double>::max());
    for (int valueIndex = 0; valueIndex < mBars.size(); valueIndex++)
    {
      if (mBars[valueIndex].value != NAN && mBars[valueIndex].value > mMaxValue)
      {
        mMaxValue = mBars[valueIndex].value;
      }

      if (mBars[valueIndex].value != NAN && mBars[valueIndex].value < mMinValue)
      {
        mMinValue = mBars[valueIndex].value;
      }
    }
  }
}