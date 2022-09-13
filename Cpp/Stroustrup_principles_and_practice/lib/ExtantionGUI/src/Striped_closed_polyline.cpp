/*
  Striped_closed_polyline.cpp
  author  : Andrei-KS
*/

#include "Striped_closed_polyline.h"
#include <limits>

namespace {
}

namespace Graph_lib {

  Striped_closed_polyline::Striped_closed_polyline()
    : mXMin(std::numeric_limits<int>::max())
    , mYMin(std::numeric_limits<int>::max())
    , mXMax(std::numeric_limits<int>::min())
    , mYMax(std::numeric_limits<int>::min())
  {
  }

  void Striped_closed_polyline::draw_lines() const
  {
    if (mNeedRecalculateStrips)
    {
      recalculateStrips();
    }

    if (fill_color().visibility()) {	// fill
      fl_color(fill_color().as_int());
      fl_line_style(fill_line_style().style(), fill_line_style().width());
      for (const pair<Point,Point>& item : mStrips)
      {
        fl_line(item.first.x, item.first.y, item.second.x, item.second.y);
      }

      // reset
      fl_color(color().as_int());
      fl_line_style(style().style(), style().width());
    }

    if (color().visibility()) {	// edge on top of fill
      fl_color(color().as_int());
      Shape::draw_lines();
      fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, point(0).x, point(0).y);
    }     
  }

  void Striped_closed_polyline::add(Point p)
  {
    Shape::add(p);
    if (p.x > mXMax)
    {
      mXMax = p.x;
    }
    if (p.x < mXMin)
    {
      mXMin = p.x;
    }
    if (p.y > mYMax)
    {
      mYMax = p.y;
    }
    if (p.y < mYMin)
    {
      mYMin = p.y;
    }
    mNeedRecalculateStrips = true;
  }

  void Striped_closed_polyline::set_fill_line_style(Line_style lineStyle)
  {
    mFillLineStyle = lineStyle;
    mNeedRecalculateStrips = true;
  }

  Line_style Striped_closed_polyline::fill_line_style() const
  {
    return mFillLineStyle;
  }

  void Striped_closed_polyline::set_distance_between_strips(int value)
  {
    mDistanceBetweenStrips = value;
    mNeedRecalculateStrips = true;
  }

  int Striped_closed_polyline::distance_between_strips() const
  {
    return mDistanceBetweenStrips;
  }

  void Striped_closed_polyline::recalculateStrips() const
  {
    mStrips.clear();
    mNeedRecalculateStrips = false;

    int widthStrip = fill_line_style().width() <= 0? style().width() : fill_line_style().width();
    if (widthStrip <= 0)
    {
      return;
    }

    int distanceBetweenStrips = distance_between_strips() < 0 ? widthStrip : distance_between_strips();
    int top = mYMin + distanceBetweenStrips;
    int down = mYMax - distanceBetweenStrips;
    if (number_of_points() > 3)
    {
      vector<int> intersectionPoints;
      vector<pair<Point, Point>> segments;
      for (int index = 0; index < number_of_points() - 1; index++)
      {
        segments.push_back({ point(index),point(index + 1) });
      }
      segments.push_back({ point(number_of_points() - 1),point(0) });

      for (int currentYPosition = top; currentYPosition < down; currentYPosition += widthStrip + distanceBetweenStrips)
      {
        Point currentStripStart{ mXMin, currentYPosition };
        Point currentStripEnd{ mXMax, currentYPosition };
        for (const pair<Point, Point>& segment : segments)
        {
          if ((segment.first.y - currentYPosition) * (segment.second.y - currentYPosition) < 0)
          {
            if (segment.first.x == segment.second.x)
            {
              intersectionPoints.push_back({ segment.first.x });
            }
            else
            {
              intersectionPoints.push_back({ (currentYPosition - segment.first.y)*(segment.first.x - segment.second.x) / (segment.first.y - segment.second.y) + segment.first.x});
            }
          }
        }
        std::sort(intersectionPoints.begin(), intersectionPoints.end(), [](int left, int right) { return left < right; });
        if (intersectionPoints.size() > 0) {
          for (int indexIntersectionPoints = 0; indexIntersectionPoints < intersectionPoints.size() - 1; indexIntersectionPoints += 2)
          {
            mStrips.push_back({ {intersectionPoints[indexIntersectionPoints],currentYPosition},{intersectionPoints[indexIntersectionPoints + 1],currentYPosition} });
          }
        }
        intersectionPoints.clear();
      }
    }
  }
}