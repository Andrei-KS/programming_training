/*
  Arc.cpp
  author  : Andrei-KS
*/

#include "Arc.h"

namespace Graph_lib {
  Arc::Arc(Point center, int xAxisHalfLength, int yAxisHalfLength, double start, double end)
    : mXAxisLength(0)
    , mYAxisLength(0)
    , mStart(0)
    , mEnd(0)
  {
    setStart(start);
    setEnd(end);
    setXAxisHalfLength(xAxisHalfLength);
    setYAxisHalfLength(yAxisHalfLength);
    Shape::add(Point{ center.x - xAxisHalfLength, center.y - yAxisHalfLength });

  }

  void Arc::draw_lines() const
  {
    if (mEnd < mStart)
    {
      error("end - of arc measured in degrees counter must be greater than or equal to start");
    }
    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(point(0).x, point(0).y, mXAxisLength, mYAxisLength, mStart, mEnd);
    }
  }

  Point Arc::center() const
  {
    return Point{ point(0).x + xAxisHalfLength(), point(0).y + yAxisHalfLength()};
  }

  int Arc::xAxisHalfLength() const
  {
    return mXAxisLength / 2;
  }

  int Arc::yAxisHalfLength() const
  {
    return mYAxisLength / 2;
  }

  double Arc::start() const
  {
    return mStart;
  }

  double Arc::end() const
  {
    return mEnd;
  }

  void Arc::setXAxisHalfLength(int xAxisHalfLength)
  {
    mXAxisLength = xAxisHalfLength * 2;
  }

  void Arc::setYAxisHalfLength(int yAxisHalfLength)
  {
    mYAxisLength = yAxisHalfLength * 2;
  }

  void Arc::setStart(double start)
  {
    mStart = start;
  }

  void Arc::setEnd(double end)
  {
    mEnd = end;
  }

}